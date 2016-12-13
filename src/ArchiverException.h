#ifndef ARCHIVER_EXCEPTION_H
#define ARCHIVER_EXCEPTION_H

#include <exception>
#include <string>

/**
 * This exception is thrown by the Archiver if it is unable
 * to perform one of its duties. The message returned by #what() 
 * should contain more contextual information
 */
class ArchiverException : public std::exception
{
public:
    ArchiverException( const char* message )
        : m_message( message ) {}

	virtual const char* what() const throw()
	{
		return m_message;
	}
private:
    const char* m_message;
};
#endif