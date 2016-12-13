#ifndef BUTTON_OUTPUT_STREAM_H
#define BUTTON_OUTPUT_STREAM_H

#include <ostream>
#include "ButtonStreamBase.h"

/**
 * Helper for the #Button class.  This class handles the serialization of
 * LZW symbol encodings to a stream. In particular, it handles the
 * conversion of variable-length codewords into fixed-width bytes suitable
 * for output to a standard stream.  This class begins by using the minimum
 * code word size of 9 bits, gradually increasing that size as needed to accomodate 
 * increasing code values.
 */
class ButtonOutputStream : public ButtonStreamBase
{
public:	
	/**
	 * Creates a new instance wrapping the specified output stream
	 * @param out the output stream to which LZW symbol codes are to
	 *        be written
	 */
	ButtonOutputStream( std::ostream &out );

	/**
	 * Writes a symbol code to the output stream.  If the current code word
	 * size is too small to represent the code value, a reserved signal word 
	 * is written to inform the decompression logic of an increase in code
	 * word size, then the code is written using the larger sized word.
	 * @param i the code the write
	 * @return the number of bytes written to the stream as a result of this call
	 */
	unsigned int put( unsigned int i );

private:
	/**
	 * A reference to the underlying output stream to which the symbol 
	 * encodings are being written
	 */
	std::ostream &m_out;

	/**
	 * Writes a symbol code to the output stream. This function is 
	 * designed to be called by #put()
	 * @param code the code to write
	 * @return the number of bytes written to the output stream
	 */
	unsigned int write( unsigned int code );

	/**
	 * Output stream accessor
	 * @return a reference to the underlying output stream
	 */
	inline std::ostream& out() { return m_out; }
};
#endif