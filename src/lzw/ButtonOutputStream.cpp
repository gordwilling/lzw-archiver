#include "ButtonOutputStream.h"

ButtonOutputStream::ButtonOutputStream( std::ostream &out ) 
	: m_out( out )
{	
}

unsigned int ButtonOutputStream::put( unsigned int code )
{	
	unsigned int bytesWritten = 0;
	while ( code >= maxCodeValue() )
	{
		bytesWritten += write( maxCodeValue() );
		incrementCodeLength();
	}
	bytesWritten += write( code );
	return bytesWritten;
}

unsigned int ButtonOutputStream::write( unsigned int code )
{
	unsigned int bytesWritten = 0;
	buffer().appendWord( code );
	while ( buffer().hasChar() )
	{
		out().put( buffer().getChar() );
		bytesWritten += 1;
	}
	return bytesWritten;
}