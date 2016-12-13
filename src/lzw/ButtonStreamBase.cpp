#include "ButtonStreamBase.h"
#include "Button.h"

ButtonStreamBase::ButtonStreamBase()
	: m_codeLength( Button::INITIAL_CODE_LENGTH ),
      m_maxCodeLength( Button::MAX_CODE_LENGTH ),
	  m_maxCodeValue( (1 << m_codeLength) - 1 ),
	  m_buffer( m_codeLength )
{
}

ButtonStreamBase::~ButtonStreamBase() 
{
}

void ButtonStreamBase::incrementCodeLength()
{
    m_codeLength++;
	m_maxCodeValue = (1 << codeLength()) - 1;
	m_buffer.setWordSize( m_codeLength );

}

void ButtonStreamBase::resetCodeLength()
{
    m_codeLength = Button::INITIAL_CODE_LENGTH;
	m_maxCodeValue = (1 << codeLength()) - 1;
	m_buffer.setWordSize( m_codeLength );
}