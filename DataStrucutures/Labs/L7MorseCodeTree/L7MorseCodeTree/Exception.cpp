#include "Exception.h"


/**********************************************************************
* Purpose:	Default constructor
* Entry:	None
* Exit:		Exception instance created, m_msg set to nullptr
************************************************************************/
Exception::Exception() : m_msg(nullptr) {}

/**********************************************************************
* Purpose:	1 argument ctor
* Entry:	char * msg to send to exception
* Exit:		m_msg is set to msg
************************************************************************/
Exception::Exception(char * msg) : m_msg(msg)
{
	m_msg = new char[strlen(msg) + 1];
	strcpy(m_msg, msg);
}

/**********************************************************************
* Purpose:	copy ctor
* Entry:	Exception copy
* Exit:		this is equal to copy
************************************************************************/
Exception::Exception(const Exception & copy) : m_msg(nullptr)
{
	m_msg = new char[strlen(copy.m_msg) + 1];
	strcpy(m_msg, copy.m_msg);
}

/**********************************************************************
* Purpose:	Destructor
* Entry:	None.
* Exit:		deletes m_msg, sets it to nullptr
************************************************************************/
Exception::~Exception()
{
	delete[] m_msg;
	m_msg = nullptr;
}

/**********************************************************************
* Purpose:	Gets Message of thrown exception
* Entry:	None.
* Exit:		m_msg is returned
************************************************************************/
const char* Exception::GetMessage() { return m_msg; }

/**********************************************************************
* Purpose:	Sets m_msg to input msg
* Entry:	char * msg
* Exit:		m_msg set to msg
************************************************************************/
void Exception::SetMessage(char * msg) { m_msg = msg; }

/**********************************************************************
* Purpose:	overloads = sign to handle Exceptions
* Entry:	Exception rhs
* Exit:		this is set to rhs
************************************************************************/
Exception& Exception::operator=(const Exception & rhs)
{
	if (this != &rhs)
	{
		delete[] m_msg;
		m_msg = new char[strlen(rhs.m_msg) + 1];
		strcpy(m_msg, rhs.m_msg);
	}
	return *this;
}

/**********************************************************************
* Purpose:	overloads << to print the message of the Exception
* Entry:	ostream stream by ref, const ref Exception
* Exit:
************************************************************************/
ostream& operator<<(ostream & stream, const Exception & except)
{
	if (except.m_msg != nullptr)
		stream  << except.m_msg << endl;

	return stream;
}