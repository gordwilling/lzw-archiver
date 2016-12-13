#include <wx/filedlg.h>
#include <wx/aboutdlg.h>
#include <wx/stdpaths.h>
#include <sstream>
#include <cmath>
#include <windows.h>

#include "Gui.h"
#include "GuiStrings.h"
#include "../Main.h"
#include "../ArchiverException.h"

Gui::Gui() : GuiBase (NULL)
{
    InitCurrentDirectory();
}

void Gui::OnFileNew( wxCommandEvent& event )
{
	NewFile();
}

void Gui::OnFileOpen( wxCommandEvent& event )
{
	OpenFile( std::string( GuiStrings::OPEN_ARCHIVE ) );
}

void Gui::OnFileExit( wxCommandEvent& event )
{
	Close();
}

void Gui::OnAbout( wxCommandEvent& event ) 
{ 
	wxAboutDialogInfo d;
    d.SetName( GuiStrings::APP_NAME );
	d.SetVersion( GuiStrings::APP_VERSION );
	d.SetDescription( GuiStrings::APP_DESCRIPTION );
	d.SetCopyright( GuiStrings::APP_COPYRIGHT );
	wxAboutBox( d );
}

void Gui::OnCompress( wxCommandEvent& event )
{
    NewFile();	
}

void Gui::OnExpand( wxCommandEvent& event )
{
    try
    {
        if ( wxGetApp().IsArchiveLoaded() )
        {
            wxDirDialog dirChooser( this, 
                    GuiStrings::EXPAND_SELECT_TARGET_DIRECTORY, 
                    currentDirectory() );

	        if( dirChooser.ShowModal() == wxID_OK )
	        {
                std::string dir = dirChooser.GetPath();
                wxGetApp().ExtractArchive( dir );

                // open the folder in explorer so the user can
                // view the extracted files
                std::string cmd = "explorer.exe /e, \"" + dir + "\"";
                WinExec( cmd.c_str(), SW_NORMAL );
            }
        }
        else
        {
            // no archive is open so present the open file dialog
            // for the user to select an archive to extract
            if ( OpenFile( std::string( GuiStrings::EXPAND_SELECT_FILE ) ) )
            {
                OnExpand( wxCommandEvent() );
            }
        }
    }
    catch( ArchiverException e )
    {
        wxMessageDialog msgbox(wxGetApp().GetTopWindow(), e.what(), GuiStrings::ERROR_ARCHIVE_EXTRACT );
		msgbox.ShowModal();
    }
}

void Gui::NewFile()
{
    // select a filename for the new archive
	wxFileDialog saveFile( this, 
            GuiStrings::NEW_SELECT_FILENAME,
            currentDirectory(),
            GuiStrings::DEFAULT_FILENAME,
            GuiStrings::APP_FILES_WILDCARD,
            wxFD_SAVE | wxFD_OVERWRITE_PROMPT );

	if ( saveFile.ShowModal()==wxID_OK )
	{
		// select the files to put in the archive
		wxFileDialog openFile( this,
            GuiStrings::NEW_SELECT_FILES_TO_ARCHIVE,
            currentDirectory(),
            GuiStrings::DEFAULT_FILENAME,
            GuiStrings::ALL_FILES_WILDCARD,
            wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_MULTIPLE );
	
		if ( openFile.ShowModal() == wxID_OK )
		{
            try
            {
                // create a new archive 
                wxGetApp().NewArchive(std::string(saveFile.GetPath()));
		        lblCurrentFile->SetLabel(saveFile.GetPath());

			    wxArrayString fileNames;
			    wxArrayString filePaths;

			    openFile.GetFilenames(fileNames);
			    openFile.GetPaths(filePaths);

			    for(unsigned int fileIndex=0; fileIndex < filePaths.GetCount(); fileIndex++)
			    {
				     wxGetApp().AddToArchive(std::string(filePaths[fileIndex]), std::string(fileNames[fileIndex]) );
			    }
				wxGetApp().SaveArchive();

                // during the archiving process, some additional information
                // was gathered and put into the archive footer.  load the newly
                // created archive to get that information and update the display
                wxGetApp().OpenArchive(std::string(saveFile.GetPath()));
                RefreshGrid();
            }
            catch( ArchiverException e )
            {
                wxMessageDialog msgbox (wxGetApp().GetTopWindow(), e.what(), GuiStrings::ERROR_ARCHIVE_CREATION );
		        msgbox.ShowModal();   
            }
		}
	}
}

bool Gui::OpenFile( std::string& message )
{
    wxFileDialog openFile( this, message,
        currentDirectory(),
        GuiStrings::DEFAULT_FILENAME,
        GuiStrings::APP_FILES_WILDCARD,
        wxFD_OPEN | wxFD_FILE_MUST_EXIST );

	if ( openFile.ShowModal() == wxID_OK )
	{
		wxGetApp().OpenArchive(std::string(openFile.GetPath()));		
		lblCurrentFile->SetLabel(openFile.GetPath());		
		RefreshGrid();	
        return true;
	}
    return false;
}

void Gui::RefreshGrid()
{
	grid->DeleteRows( 0, grid->GetNumberRows() );

    ArchiveEntry::Vector entries = wxGetApp().ArchiveDescriptor().entries();

	for( unsigned int i = 0; i < entries.size(); i++ )
	{			
		grid->AppendRows();
        grid->SetCellAlignment(i,0,wxALIGN_LEFT,wxALIGN_CENTER);
        grid->SetCellAlignment(i,1,wxALIGN_RIGHT,wxALIGN_CENTER);
        grid->SetCellAlignment(i,2,wxALIGN_RIGHT,wxALIGN_CENTER);
        grid->SetCellAlignment(i,3,wxALIGN_RIGHT,wxALIGN_CENTER);
        grid->SetCellAlignment(i,4,wxALIGN_RIGHT,wxALIGN_CENTER);

		grid->SetCellValue(entries[i].fileName(),i,0);
		grid->SetCellValue(wxFileName::GetHumanReadableSize(entries[i].originalSize()),i,1);
		grid->SetCellValue(wxFileName::GetHumanReadableSize(entries[i].compressedSize()),i,2);
		grid->SetCellValue(ToString(CompressionRatio(entries[i])),i,3);
		grid->SetCellValue(ToString(CompressedPercentage(entries[i])) + "%",i,4);
	}

    statusBar->SetStatusText( GuiStrings::STATUS_BAR_COMPRESSION_RATIO + 
            ToString( CompressionRatioTotal( entries ) ) +
            " (" + ToString( CompressedPercentageTotal( entries ) ) + "%)" );
}

double Gui::CompressionRatioTotal( ArchiveEntry::Vector& entries )
{
    unsigned long long totalOriginalSize = 0;
    unsigned long long totalCompressedSize = 0;
    for ( ArchiveEntry::Vector::iterator it = entries.begin(); it != entries.end(); it++ )
    {
        totalOriginalSize += it->originalSize();
        totalCompressedSize += it->compressedSize();
    }
    return static_cast<double>(totalOriginalSize)/totalCompressedSize;
}

double Gui::CompressedPercentageTotal( ArchiveEntry::Vector& entries )
{
    return std::floor( 0.5 + (1.0 - 1.0/CompressionRatioTotal(entries))*100 );
}

double Gui::CompressionRatio( ArchiveEntry& entry )
{
	return static_cast<double>(entry.originalSize())/entry.compressedSize();
}

double Gui::CompressedPercentage( ArchiveEntry& entry )
{
	return std::floor( 0.5 + (1.0 - 1.0/CompressionRatio(entry))*100 );
}

std::string Gui::ToString( double d )
{
    std::ostringstream s( std::ostringstream::out);
	s.precision(3);
	s << d;
	return s.str();
}

void Gui::InitCurrentDirectory()
{
    std::string exePath( wxStandardPaths::Get().GetExecutablePath() );
    size_t indexOfLastSlash = exePath.find_last_of( '\\' );
    if ( indexOfLastSlash != 0 )
    {
        m_currentDirectory = exePath.erase( indexOfLastSlash );
    }
    else
    {
        m_currentDirectory = GuiStrings::DEFAULT_DIRECTORY;
    }
}