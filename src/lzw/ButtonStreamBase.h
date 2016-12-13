#ifndef BUTTON_STREAM_BASE_H
#define BUTTON_STREAM_BASE_H

#include "../util/BitBuffer.h"

/**
 * Abstract base class for the #ButtonOutputStream and #UnButtonInputStream classes.
 * This class contains members commmon to those two child classes and
 * a function which performs the basic adjustments necessary to increment the
 * code word length.
 */
class ButtonStreamBase
{
public:
	/**
	 * Default constructor
	 */
	ButtonStreamBase();

	/**
	 * Virtual destructor, providing "abstractness".
	 */
	virtual ~ButtonStreamBase() = 0;
        
    /**
	 * Resets the code length to its initial value and correspondingly 
     * adjusts the maximum value pertaining to that code length, as well as
	 * the set code word size in the #BitBuffer. 
	 */
    void resetCodeLength();

protected:
	/**
	 * Increments the code length and correspondingly adjusts the 
	 * maximum value pertaining to the new code length, as well as
	 * the set code word size in the #BitBuffer
	 */
	void incrementCodeLength();
	
	/**
	 * @return a reference to the current code length
	 */
	inline unsigned int& codeLength() { return m_codeLength; }

    /**
	 * @return a the maximum code length
	 */
	inline const unsigned int maxCodeLength() { return m_maxCodeLength; }

	/**
	 * @return a reference to the maximum value possible given the 
	 *         current code length
	 */
	inline unsigned int& maxCodeValue() { return m_maxCodeValue; }

	/**
	 * @return a reference to the bit buffer
	 */
	inline BitBuffer& buffer() { return m_buffer; }

private:
	/**
	 * The current length of a code word
	 */
	unsigned int m_codeLength;

    /**
     * The maximum length of a code word
     */
     unsigned int m_maxCodeLength;

	/**
	 * The maximum value of a code word given its current length
	 */
	unsigned int m_maxCodeValue;

	/**
	 * A BitBuffer, used to handle variable-length code to byte
	 * conversion (and vice-versa)
	 */
	BitBuffer m_buffer;
};
#endif