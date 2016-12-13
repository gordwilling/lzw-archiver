#ifndef BIT_BUTTER_H
#define BIT_BUFFER_H

/**
 * A FIFO buffer providing the following capability
 * <ul>
 *   <li>
 *     Write n-bit words to a buffer, then 
 *     extract buffered data one character (8-bits) at a time
 *   </li>
 *   <li>
 *     Write 8-bit characters to a buffer, then
 *     extract buffered data n-bits at a time
 *   </li>
 * </ul>
 * These are useful preliminary steps when you need to perform
 * I/O operations using variable length codewords, as the standard
 * library stream classes are designed to work with bytes.
 * <p>
 * <b>Usage Note:</b> This class uses a long int as the underlying
 * buffer, meaning that there is a maximum of 64 bits of storage 
 * available. The usage pattern for which this class was designed 
 * involves small writes to the buffer (a few characters) until a full 
 * word is formed, at which point the word is extracted. This means that 
 * usually the buffer contains just a few bits at any given time.  
 * Writing too much data to the buffer before extraction will result in 
 * loss of data.
 * <p>
 * <b>Usage Example:</b>
 * <pre>
 *   // reading an n-bit word from an input stream
 *   char c;
 *   while( !buffer.hasWord() )
 *   {	
 *       istream.get( c )		
 *       buffer.appendChar( c );
 *   }
 *   int word = buffer.getWord();
 *   
 *   // writing an n-bit word to an output stream
 *   buffer.appendWord( word );
 *   while ( buffer.hasChar() )
 *	 {
 *	     ostream.put( buffer.getChar() );
 *	 }
 * </pre>
 */
class BitBuffer
{
public:
	/**
	 * 8-bits, all ones. Used when adding or extracting characters
	 * to the buffer
	 */
	static const unsigned char CHAR_MASK = ~0;

	/**
	 * 32-bits, all ones. This is used to produce a mask that will aid in the 
	 * extraction of an n-bit word from the buffer, where n = word size
	 */
	static const unsigned int INT_MASK = ~0;

	/**
	 * Create a new BitBuffer, configured for the specified word size
	 * @param wordSize the bit length of a word
	 */
	BitBuffer( size_t wordSize );

	/**
	 * @return true if the buffer contains enough bits to represent
	 *         a word of length n, where n is the word size, false otherwise.
	 */
	bool hasWord();

	/**
	 * @return true if the buffer contains enough bits to represent
	 *         a character (8-bits)
	 */
	bool hasChar();

	/**
	 * @return the next character in the buffer.  Before calling this function,
	 *         use #hasChar() to ensure that the buffer contains enough data to 
	 *         produce a character. Behaviour is undetermined if not enough
	 *         data is in the buffer
	 */          
	unsigned char getChar();

	/**
	 * @return the next word in the buffer.  The word is returned as an unsigned
	 *         int, but only the first n-bits will be populated with data, where n
	 *	       is the word size.  (Higher order bits will be zeros.)  Before calling 
	 *         this function, use #hasWord() to ensure that the buffer contains 
	 *         enough data to produce the word. Behaviour is undetermined if not enough
	 *         data is in the buffer
	 */  
	unsigned int getWord();

	/**
	 * Append an 8-bit character to the buffer
	 * @param c the character to append
	 */
	void appendChar( const char c );

	/**
	 * Append the first n-bits (right to left) of the given integer to the
	 * left end of the buffer, where n is equal to the word size
	 * @param i the integer from which the n-bit word will be extracted and 
	 *        appended to the buffer. Higher order bits in the integer are ignored
	 */
	void appendWord( const int i );

	/**
	 * Sets a new word size. All full words written to the buffer using the previous
	 * word size should be extracted from the buffer before setting a new word
	 * size. (A partial word may remain in the buffer, which is fine.)
	 * @param wordSize the new word size to use
	 */
	void setWordSize( size_t wordSize );

	/**
	 * @return the number of bits in the buffer
	 */
	inline unsigned short length();

private:
	/**
	 * The current word size
	 */
	size_t m_wordSize;

	/**
	 * The bit container
	 */
	unsigned long m_buffer;

	/**
	 * The number of bits currently used in the buffer
	 */
	unsigned short m_length;

	/**
	 * A mask corresponding to the current word size.  Given 
	 * a word size of n, the first n bits in the mask will be
	 * ones, the rest zeros.
	 */
	unsigned int m_wordMask;
};
#endif