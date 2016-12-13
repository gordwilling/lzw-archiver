#include "GuiBase.h"
#include "../ArchiveEntry.h"

/**
 * This class handles user interface events resulting from
 *  user actions. 
 */
class Gui : public GuiBase
{
public:	
    /**
     * Default Constructor
     */
	Gui();

private:
    /**
     * The path to the directory of the executable, used as
     * the starting path for the open, save, and extract
     * dialogs
     */
    std::string m_currentDirectory;
    /**
     * Handler for the File|New menu item
     * @param event (not used)
     */
	virtual void OnFileNew( wxCommandEvent& event );

    /**
     * Handler for the File|Open menu item
     * @param event (not used)
     */
	virtual void OnFileOpen( wxCommandEvent& event );

    /**
     * Handler for the File|Exit menu item
     * @param event (not used)
     */
	virtual void OnFileExit( wxCommandEvent& event );

    /**
     * Handler for the 'Create' toolbar button
     * @param event (not used)
     */
	virtual void OnCompress( wxCommandEvent& event );

    /**
     * Handler for the 'Extract' toolbar button
     * @param event (not used)
     */
	virtual void OnExpand( wxCommandEvent& event );

    /**
     * Handler for the 'About' toolbar button
     * @param event (not used)
     */
	virtual void OnAbout( wxCommandEvent& event );

    /**
     * Entry point for creating a new archive
     */
    void NewFile();

    /**
     * Entry point for opening an existing archive
     * @param message the caption to use for the open file dialog
     * @return true if the user selected a file, false if the user
     *         canceled 
     */
	bool OpenFile( std::string& message );

    /**
     * Refreshes the content of the Grid control with the 
     * information from the currently loaded ArchiveDescriptor
     */
	void RefreshGrid();

    /**
     * @param entries the vector of ArchiveEntries containing information
     *        about the files in the archive
     * @return the total compression ratio of an existing archive 
     */
	double CompressionRatioTotal( ArchiveEntry::Vector& entries );

    /**
     * @param entries the vector of ArchiveEntries containing information
     *        about the files in the archive
     * @return the total compression of an existing archive, expressed as
     *         a percentage.  The percentage represents the amount of space
     *         that is no longer occupied by the compressed file as compared 
     *         to the space occupied by the original file
     * 
     */
    double CompressedPercentageTotal( ArchiveEntry::Vector& entries );

    /**
     * @param entry the archive entry containing information about the file
     * @return the compression ratio of a single file in the archive
     */ 
    double CompressionRatio( ArchiveEntry& entry );

    /**
     * @param entry the archive entry containing information about the file
     * @return the compression of a file in the archive, expressed as
     *         a percentage.  The percentage represents the amount of space
     *         that is no longer occupied by the compressed file as compared 
     *         to the space occupied by the original file
     */ 
	double CompressedPercentage( ArchiveEntry& entry );

    /**
     * Initializes the current directory reference to the directory from which
     * the executable is being run
     */
    void InitCurrentDirectory();

    /**
     * Converts a double value to a string value.  This function is tailored to
     * suit the display format of the numbers displayed in the GridView
     * @param d a double value
     * @return a string representation of the double value.
     */
    std::string ToString( double d );
        
    /**
     * @return a the path of the current directory
     */
    inline const std::string& currentDirectory() { return m_currentDirectory; }
};