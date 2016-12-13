#ifndef UNBUTTON_INPUT_STREAM_EXCEPTION
#define UNBUTTON_INPUT_STREAM_EXCEPTION

#include <exception>

/**
 * This exception is thrown by the UnButtonInputStream if its underlying
 * input stream is no longer readable.  This is typically expected to
 * mean the end of file has been reached but could be due to any number 
 * of things
 */
class UnButtonInputStreamException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Input buffer could not be filled because the input stream could not be read";
	}
};
#endif