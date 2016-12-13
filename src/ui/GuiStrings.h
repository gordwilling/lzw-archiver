#ifndef GUI_STRINGS_H
#define GUI_STRINGS_H

#include <string>

/**
 * This namespace contains strings used by the Gui
 */
namespace GuiStrings
{
    const std::string& OPEN_ARCHIVE = "Open .pants";
    const std::string& APP_NAME = "button";
    const std::string& APP_VERSION = "0.0.0.1a (Bone)";
    const std::string& APP_DESCRIPTION = "\nA file compression and archiving utility implemented\nusing the Lempel-Ziv Welch compression algorithm.";
    const std::string& APP_COPYRIGHT = "(c) 2012\nGordon Wallace";
    const std::string& APP_FILES_WILDCARD = "Button files (*.pants)|*.pants";
    const std::string& APP_OR_ALL_FILES_WILDCARD = "Button files (*.pants)|*.pants|All files (*.*)|*.*";    
    const std::string& EXPAND_SELECT_TARGET_DIRECTORY = "Select a location for the UnButtoned files";
    const std::string& EXPAND_SELECT_FILE = "Select a previously Buttoned file to extract";    
    const std::string& NEW_SELECT_FILENAME = "Save the new .pants as";    
    const std::string& NEW_SELECT_FILES_TO_ARCHIVE = "Select the files to Button";     
    const std::string& DEFAULT_DIRECTORY =  ".";
    const std::string& DEFAULT_FILENAME = "";
    const std::string& ALL_FILES_WILDCARD = "All files (*.*)|*.*";    
    const std::string& STATUS_BAR_COMPRESSION_RATIO = "Total Compression Ratio: ";    
    const std::string& ERROR_ARCHIVE_CREATION = "Error Creating .pants";
    const std::string& ERROR_ARCHIVE_LOAD = "Error Loading .pants";
    const std::string& ERROR_ARCHIVE_EXTRACT = "Error Extracting .pants";
}
#endif