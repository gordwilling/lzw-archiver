#ifndef BUTTON_H
#define BUTTON_H

#include <unordered_map>
#include <string>
#include "ButtonOutputStream.h"
#include "UnButtonInputStream.h"

/**
 * This class provides stream compression and decompression
 * using an LZW implementation.
 */
class Button
{	
public:
	/**
	* initial codeword length in bits
	*/
	static const short INITIAL_CODE_LENGTH = 8;

	/**
	* maximum length of a codeword in bits
	*/ 
	static const short MAX_CODE_LENGTH = 30; 

	/**
	 * Maximum value of a code word that can be achieved given the #MAX_CODE_LENGTH
	 */
	static const unsigned long MAX_CODE = (1 << MAX_CODE_LENGTH) - 1;

	/**
	* this end of file indicator will be the last codeword written. 
	*/
	static const short END_OF_FILE = 0x100;

	/**
	 * The initial code map contains single character ASCII codes from 0 to 255
	 */
	static const unsigned int INITIAL_MAP_SIZE = 256;

	/**
	 * Compresses the content of an input stream and writes the compressed content to
	 * a target output stream.
	 * @param source the input stream of data to compress
	 * @param target the output stream to which the compressed data is to be
	 *               written 
	 * @return the number of bytes written to the target stream
	 */
	unsigned long long compress( std::istream &source, ButtonOutputStream &target );

	/**
	 * Decompresses content from a compressed input stream and writes it to
	 * the specified target output stream.  The given input stream must contain
	 * data that was previously compressed using {@link #compress} 
	 * @param source the input stream of data to decompress
	 * @param target the output stream to which the decompressed data is to be
	 *               written 
	 * @see #compress
	 */
	void decompress( UnButtonInputStream &source, std::ostream &target );

private:
	/**
	 * type name for the code map, which maps sequence patterns (symbols) to code values.
	 * (used during compression)
	 */
	typedef std::unordered_map<std::string, unsigned int> code_map_t;
	
	/**
	 * type name for a code map entry
	 */
	typedef std::unordered_map<std::string, unsigned int>::value_type code_map_value_t;

	/**
	 * type name for the pattern map, which maps code values to sequency patterns (symbols).
	 * (used during decompression)
	 */
	typedef std::unordered_map<unsigned int, std::string> pattern_map_t;

	/**
	 * type name for a pattern map entry
	 */
	typedef std::unordered_map<unsigned int, std::string>::value_type pattern_map_value_t;

	/**
	 * Populates a new code map with the first 256 character patterns mapped to their
	 * corresponding codes
	 * @param codeMap an empty code map to populate
	 */
	void initCodeMap( code_map_t &codeMap ); 

	/**
	 * Populates a new pattern map with the first 256 codes mapped to their
	 * corresponding patterns.  The resultant map is similar to the code map used for 
	 * compression, but the keys and values are switched. that is, the compression map
	 * put patterns to codes, whereas this one puts codes to patterns
	 * @param patternMap an empty pattern map to populate
	 */
	void initPatternMap( pattern_map_t &patternMap );

};
#endif