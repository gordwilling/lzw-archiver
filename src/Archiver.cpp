#include <algorithm>
#include <cassert>
#include <sstream>
#include <wx/progdlg.h>
#include "Archiver.h"
#include "ArchiveDescriptor.h"
#include "ArchiverException.h"
#include "Main.h"
#include "lzw/Button.h"
#include "lzw/ButtonOutputStream.h"
#include "lzw/UnButtonInputStream.h"

void Archiver::New(const std::string& archivePath )
{
    descriptor() = ArchiveDescriptor( archivePath );
}

void Archiver::AddFile(const std::string& filePath, const std::string &fileName )
{
	if( FileExists( filePath ) )
	{
		descriptor().entries().push_back( ArchiveEntry( filePath, fileName ) );
	}
	else 
	{
		throw ArchiverException( "Could not add the file to the archive because the file does not exist." );
	}
}

/// \todo Add callback parameter to decouple progress dialog
/// \todo Put a timestamp in the file footer to ensure the file hasn't been modified
///       since it was loaded
/// \todo Add a file format GUID to the output file so we can detect files we didn't make
///       and abort processing them asap
/// \todo Ensure any changes made here are handled in Extract()
void Archiver::Save()
{
	std::ofstream archiveFile( descriptor().filePath(), std::ios::binary|std::ios::out|std::ios::trunc );
	if( archiveFile.fail() )
	{
		throw ArchiverException( "Failed to create output stream. Unable to write archive to disk." );
	}

	Button b;
    ButtonOutputStream bstream( archiveFile );
    ArchiveEntry::Vector entries = descriptor().entries();
	std::ifstream file;

	// progress dialog... 
    int fileProcessingIndex = 0;
	wxProgressDialog progressDialog( "Buttoning Up", "", entries.size(), wxGetApp().GetTopWindow(), 
				wxPD_APP_MODAL | wxPD_SMOOTH | wxPD_AUTO_HIDE );
	for(ArchiveEntry::Vector::iterator it = entries.begin(); it!=entries.end(); it++)
	{	
        // this part is just the progress dialog
		std::ostringstream message( std::ios::out );
        message << "Buttoning file " << fileProcessingIndex << " of " << entries.size() << ": " << it->fileName();
		progressDialog.Update( ++fileProcessingIndex, message.str() );

        // compress the file and update the archive descriptor with some stats
		it->originalSize() = FileSize( it->filePath() );			
		file.open(it->filePath(), std::ios::binary|std::ios::in); 
		it->compressedSize() = b.compress( file, bstream );
        file.close();
	}

    // because of the variable length encodings, the last 
    // END_OF_FILE code can get truncated on the final 
    // write, leading to... Disaster!
    // Writing this wee string to the stream forces all of
    // the END_OF_FILE code out into the stream, enabling the 
    // extraction process to correctly see the last END_OF_FILE 
    // code. (a little bit kludgy but fine for now)
    b.compress( std::istringstream("b", std::ios::in ), bstream );

    // Create footer containing archive statistics. 
    
    // first note the stream position. this is the start of the footer
	unsigned long long footerPosition = archiveFile.tellp();

	// number of files in archive
	archiveFile << entries.size() << std::endl;

    // individual file information 
	for ( ArchiveEntry::Vector::iterator it=entries.begin(); it != entries.end(); it++ )
	{
		archiveFile << it->filePath() << std::endl;
        archiveFile << it->fileName() << std::endl;
		archiveFile << it->originalSize() << std::endl;
		archiveFile << it->compressedSize() << std::endl;
	}
    
    // lastly, a newline followed by the index of
    // where the footer begins. (the footer is used to view
    // the content of the archive without having to decompress
    // the whole thing.) The load function will jump to the 
    // end of the file, find this index, and use the footer
    // info to build the ArchiveDescriptor
    archiveFile << std::endl << footerPosition;
	archiveFile.close();
}

/// \todo Add callback parameter to decouple progress dialog
/// \todo Ensure any changes made to Save() are reflected here as well
void Archiver::Extract( const std::string& targetDirectory )
{	
    std::string s;
    std::ifstream archive( descriptor().filePath(), std::ios::binary | std::ios::in );

    Button b;
    UnButtonInputStream ubstream( archive );

    ArchiveEntry::Vector entries = descriptor().entries();
    int fileProcessingIndex = 0;

    // progress dialog... 
	wxProgressDialog progressDialog( "UnButtoning", "", entries.size(), wxGetApp().GetTopWindow(), 
				wxPD_APP_MODAL | wxPD_SMOOTH | wxPD_AUTO_HIDE );
	for( ArchiveEntry::Vector::iterator it = entries.begin(); it != entries.end(); it++ )
	{
        // this part is just updating progress dialog
		std::ostringstream message( std::ios::out );
		message << "UnButtoning file " << fileProcessingIndex << " of " << entries.size() << ": " << it->fileName();
		progressDialog.Update( ++fileProcessingIndex, message.str() );

		std::string outputFileName = targetDirectory + "\\" + it->fileName();
		std::ofstream outputFile( outputFileName, std::ios::binary|std::ios::out|std::ios::trunc);					
		
        b.decompress( ubstream, outputFile );
        outputFile.close();
	}

    // the rest of the file is the footer, which we don't need right now
	archive.close();	
}

void Archiver::Load( const std::string &archivePath )
{
    std::ifstream archive( archivePath, std::ios::binary | std::ios::in );
    if ( !archive.bad() )
    {
        ArchiveDescriptor d( archivePath );
        
        PositionStreamAtFooter( archive );

        // first item in footer is the number of files in the archive
	    archive >> d.fileCount();

        // every file has a collection of associated data
	    for ( unsigned int i = 0; i < d.fileCount(); i++ )
	    {	
            d.entries().push_back( ArchiveEntry() );
        
		    // for some reason it takes two reads to get to the filepath
		    std::getline( archive, d.entries()[i].filePath() );
		    std::getline( archive, d.entries()[i].filePath() );		
            std::getline( archive, d.entries()[i].fileName() );
		    archive >> d.entries()[i].originalSize();
            archive >> d.entries()[i].compressedSize();		
	    }

        // this is now the relevent data for the currently loaded archive.
        descriptor() = d;
    }
    else
    {
        throw ArchiverException( "An error occured trying to load the archive." );
    }
}

void Archiver::PositionStreamAtFooter( std::istream& archiveStream )
{
    // the last line of the archive contains the footer position.
    // seek to the end of file content, then read backwards
    // a character at a time until a newline is reached.
    // the characters encountered along the way form the string
    // version of the footer position.

	archiveStream.seekg( 0, std::ios::end);
    unsigned int length = archiveStream.tellg();

    std::string s;
    char c = 0;
    for ( unsigned int i = length - 1; i != 0 && c != '\n'; i-- )
    {
        archiveStream.seekg( i, std::ios::beg );
        archiveStream.get( c );
        if ( c != '\n' )
        {
            s.insert( 0, 1, c );
        }
    }     

    // convert the string version of the footer position to
    // a numerical quantity, then position the stream
    std::istringstream iss( s );
    unsigned long long footerPosition = 0;
    iss >> footerPosition;
    archiveStream.seekg( footerPosition, std::ios::beg );
}

bool Archiver::FileExists( const std::string& filePath )
{
    DWORD dwAttrib = GetFileAttributes(filePath.c_str());
    return dwAttrib != INVALID_FILE_ATTRIBUTES && !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}

unsigned long long Archiver::FileSize( const std::string& filePath )
{
	std::ifstream is ( filePath );
	unsigned long long begin = is.tellg();  
	is.seekg ( 0, std::ios::end );
	unsigned long long end  = is.tellg();
	is.close();
	return end - begin;
}