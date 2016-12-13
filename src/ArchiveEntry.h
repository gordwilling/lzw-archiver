#ifndef ARCHIVE_ENTRY_H
#define ARCHIVE_ENTRY_H

#include <string>
#include <vector>

/**
 * This class contains information about a single file in an archive, including
 * name, fully qualified path, original size, and compressed size
 */
class ArchiveEntry
{
public:
    
    /**
     * A Vector of ArchiveEntry instances
     */
    typedef std::vector<ArchiveEntry> Vector; 

    /**
     * Creates a new ArchiveEntry. 
     * @param filePath the fully qualified path to the file
     * @param fileName the name of the file without path information
     */
	ArchiveEntry( const std::string& filePath = std::string(""), const std::string& fileName = std::string("") ) 
		: m_filePath( filePath ),
          m_fileName( fileName ),
		  m_originalSize(0),
		  m_compressedSize(0) 
	{
	}

    /**
     * @return a reference to the fully qualified path of the file
     */
	inline std::string& filePath() { return m_filePath; }

    /**
     * @return a reference to the name of the file
     */
    inline std::string& fileName() { return m_fileName; }

    /**
     * @return the size of the file in bytes before compression
     */
	inline unsigned long long& originalSize() { return m_originalSize; }

    /**
     * @return the size of the file in bytes after compression
     */
	inline unsigned long long& compressedSize() { return m_compressedSize; }

private:
	std::string m_filePath;
    std::string m_fileName;
	unsigned long long m_originalSize;
	unsigned long long m_compressedSize;
};
#endif