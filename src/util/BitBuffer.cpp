#include "BitBuffer.h"

BitBuffer::BitBuffer( size_t wordSize )
	: m_buffer( 0 ),
	  m_length( 0 )
{
	setWordSize( wordSize );
}

void BitBuffer::appendChar( const char c )
{
	m_buffer |= (c & CHAR_MASK) << m_length;
	m_length += 8;
}

void BitBuffer::appendWord( const int i )
{
	m_buffer |= i << m_length;
	m_length += m_wordSize;
}

void BitBuffer::setWordSize( size_t wordSize )
{
	m_wordSize = wordSize;
	m_wordMask = ~(INT_MASK << wordSize);
}

bool BitBuffer::hasWord()
{
	return m_length >= m_wordSize;
}

bool BitBuffer::hasChar()
{
	return m_length >= 8;
}

unsigned char BitBuffer::getChar()
{
	char c = m_buffer & CHAR_MASK;
	m_buffer >>= 8;
	m_length -= 8;
	return c;
}

unsigned int BitBuffer::getWord()	
{
	int i = m_buffer & m_wordMask;
	m_buffer >>= m_wordSize;
	m_length -= m_wordSize;
	return i;
}

inline unsigned short BitBuffer::length()
{
	return m_length;
}