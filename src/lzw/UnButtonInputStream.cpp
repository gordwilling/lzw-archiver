#include "UnButtonInputStream.h"
#include "UnButtonInputStreamException.h"
#include "Button.h"

UnButtonInputStream::UnButtonInputStream( std::istream &in )
	: m_in( in )
{
}

unsigned int UnButtonInputStream::get( unsigned int &code )
{
	try
	{
		fillBuffer();
		code = buffer().getWord();	

		while ( code == maxCodeValue() )
		{	
			// this is a reserved code indicating a code length
			// increase. adjust our code length accordingly, then
			// read in the next code
			incrementCodeLength();
			get( code );
		}
		return code;
	}
	catch( UnButtonInputStreamException )
	{
		return Button::END_OF_FILE;
	}    
}

void UnButtonInputStream::fillBuffer() 
{
	char c = 0;
	while( !buffer().hasWord() )
	{	
		if ( !in().get( c ) )
		{
			throw UnButtonInputStreamException();
		}
		
		buffer().appendChar( c );
	}
}