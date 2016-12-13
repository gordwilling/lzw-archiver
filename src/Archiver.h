#ifndef ARCHIVER_H
#define ARCHIVER_H

#include <Windows.h>
#include <string>
#include <vector>
#include <fstream>
#include "ArchiveDescriptor.h"
#include "ArchiveEntry.h"

/**
 * This class handles (on the macro-level) all of the file archiving tasks, 
 * including creation, loading, and extraction of archives
 */
class Archiver
{
public:
    /**
     * Default constructor
     */
    Archiver() 
        : m_descriptor() 
    {
    }

    /** 
     * Instantiates a new ArchiveDescriptor configured with the specified destination
     * path and updates the descriptor reference held by this class
     * @param archivePath the fully qualified path name of the new archive
     */
    void New( const std::string& archivePath );

	/**
     * Adds a file to the currently referenced #ArchiveDescriptor
     * @param filePath the fully qualified path of the file
     * @param fileName the fileName itself (name & extension) without path information
     */
	void AddFile( const std::string &filePath, const std::string &fileName );

	/**
     * Compresses and saves a new archive containing the files in the currently
     * loaded #ArchiveDescriptor
     */
	void Save();					

	/**
     * Extracts the files in the currently loaded archive to the specified
     * target directory
     * @param targetDirectory the directory into which the files are to be placed
     */
	void Extract( const std::string& targetDirectory );

	/**
     * Loads the archive at the specified path. 
     */
	void Load( const std::string &archivePath );	

    /**
     * @param filePath The fully qualified path to the file 
     * @return true if the file at the supplied path exists, false otherwise
     */
    bool FileExists( const std::string& filePath );

    /**
     * @param filePath The fully qualified path to the file 
     * @return the file size of the file at the specified path
     */
	unsigned long long FileSize( const std::string& filePath );	
    
    /**
     * @return a reference to the descriptor pertaining to the currently loaded
     *         archive
     */
	inline ArchiveDescriptor& descriptor() { return m_descriptor; }

private:
    /**
     * Finds the footer index and positions the supplied stream (hopefully
     * connected to an archive file created by this program) at that index,
     * in preparation for loading.  
     * @param archiveStream an open stream to an existing archive file on disk
     */
	void PositionStreamAtFooter( std::istream& archiveStream );

    /** 
     * When an archive is loaded (either from loading an existing one, or
     * creating a new one) information about its content is held here
     */
    ArchiveDescriptor m_descriptor; 
};
#endif;