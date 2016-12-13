#ifndef UN_BUTTON_INPUT_STREAM
#define UN_BUTTON_INPUT_STREAM

#include <iostream>
#include "ButtonStreamBase.h"

/**
 * Helper for the #Button class used during decompression.  This class handles the 
 * deserialization of LZW codewords from a compressed stream. In particular, it handles 
 * the conversion of incoming bytes into the variable-length codewords representing 
 * encoded symbols.  This class begins by using the minimum code word size of 9 bits, 
 * and gradually increases the codeword size as indicated by the cues left in the 
 * compressed data stream by the compression logic.
 */
class UnButtonInputStream : public ButtonStreamBase
{
public:
	/**
	 * Creates a new instance wrapping the specified input stream
	 * @param in reference to the input stream from which LZW encodings are to
	 *        be read
	 */
	UnButtonInputStream( std::istream &in );

	/**
	 * Reads a symbol code from the input stream.  If a code word has its
	 * maximum value (i.e. every bit is a one) this is interpreted as a signal to
	 * expected larger codewords (current size + 1) in the remaining part 
	 * of the stream.  In this case, the required adjustments are made and the
	 * next code word is read, which most likely represents the next symbol
	 * endcoding
	 * @param i a reference to the integer into which the read value is 
	 *        to be placed
	 */
	unsigned int get( unsigned int &i );

private:
	/**
	 * A reference to the underlying input stream
	 */
	std::istream &m_in;

	/**
	 * Fills a BitBuffer with enough bytes to produce a code word
	 */
	void fillBuffer();

	/**
	 * Input stream accessor
	 * @return a reference to the underlying input stream
	 */
	inline std::istream& in() { return m_in; }	
};
#endif