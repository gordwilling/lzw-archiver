#ifndef MAIN_H
#define MAIN_H

#include <wx/wx.h>
#include "Archiver.h"
#include "ArchiveDescriptor.h"

/**
 * This class acts as a service to the Gui, taking requests that result
 * from user actions and delegating them to the appropriate class which
 * performs those actions. In this case, most of the requests are delegated
 * to the Archiver class
 */
class Main : public wxApp
{
public:
    /**
     * Default Constructor
     */
    Main() : m_archiver() {}

    /**
     * Performs application initialization (called by wx Framework after construction)
     */
    virtual bool OnInit(); 

    /**
     * Creates a new archive at the given path
     * @param archivePath the fully qualified path of the archive file to create
     * @see Archiver::New
     */
	void NewArchive( const std::string& archivePath );

    /**
     * Loads an existing archive from disk
     * @param archivePath the fully qualified path of the archive file to open
     * @see Archiver::Load
     */
    void OpenArchive( const std::string& archivePath );	

    /**
     * Extracts the currently open archive to the specified folder
     * @param targetDirectory the directory into which the extracted files are to 
     *        be placed
     * @see Archiver::Extract
     */
	void ExtractArchive( const std::string& targetDirectory );

    /**
     * Adds a file to the currently loaded archive.
     * @param filePath the fully qualified path of the file to add
     * @param fileName the file name of the same file reference by the filePath     
     * @see Archiver::Add
     */
	void AddToArchive( const std::string& filePath, const std::string& fileName );

    /**
     * Saves the currently loaded archive to disk
     * @see Archiver::Save
     */
	void SaveArchive();	

    /**
     * @return true if an archive descriptor is loaded, false otherwise
     */
    const bool IsArchiveLoaded(); 

    /**
     * @return the reference to the currently loaded archive descriptor
     */
    inline ArchiveDescriptor& ArchiveDescriptor() { return archiver().descriptor(); }
private:  
    /**
     * @return a reference to the Archiver class, which does all the work
     */
    inline Archiver& archiver() { return m_archiver; }

    /**
     * the Archiver instance to which most functionality is delegated
     */
    Archiver m_archiver;
};
DECLARE_APP(Main)
#endif