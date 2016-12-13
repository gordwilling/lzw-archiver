#ifndef ARCHIVE_DESCRIPTOR_H
#define ARCHIVE_DESCRIPTOR_H

#include <vector>
#include "ArchiveEntry.h"

/**
 * This class contains all of the information about an archive file, including
 * its path, the list of file within, their original sizes, and their compressed sizes
 */
class ArchiveDescriptor
{    
public:
    /**
     * Creates a new ArchiveDescriptor with the specified path. 
     * @param filePath the fully qualified path of the archive. 
     */
    ArchiveDescriptor::ArchiveDescriptor( const std::string& filePath = std::string() ) 
        : m_filePath( filePath ),
          m_fileCount(),
          m_entries() {}

    /**
     * @return a reference to the file path of the archive
     */
    inline std::string& filePath() { return m_filePath; };

    /**
     * @return the number of files in the archive. This quantity is
     *         stored in the archive file itself and should eventually match
     *         the length of the ArchiveEntryVector, although the two
     *         values are not in sync during the loading process
     */
    inline unsigned int& fileCount() { return m_fileCount; }

    /**
     * @return the vector of entries in the archive
     */
    inline ArchiveEntry::Vector& entries() { return m_entries; }

private:
    /**
     * The fully qualified path of the archive.  This is either the
     * path to an existing archive, or the path to which an archive
     * undergoing creation is to be written
     */
    std::string m_filePath;

    /**
     * The number of files in the archive, to be populated when reading
     * the file in from disk prior to the ArchiveEntryVector being populated
     */
    unsigned int m_fileCount;

    /**
     * The vector of ArchiveEntry instances, each representing a file 
     * in the archive
     */
    ArchiveEntry::Vector m_entries;
};
#endif