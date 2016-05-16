/***********************************************************
* Class:			Exception
*
* Managers:
* 	Exception()
* 		Default constructor, sets m_msg to nullptr
*	Exception(char * msg)
*		sets m_msg to msg
*	Exception(const Exception & copy)
* 		Copy Ctor
*	~Exception()
*		Destructor
* 	Exception& operator=(const Exception & rhs)
*		Overload the = operator
*
* Public Methods:
*	const char* GetMessage()
*		returns the m_msg
*	void SetMessage(char * msg)
*		sets m_msg to msg
*	ostream& operator<<(ostream &, const Exception &)
*		overloads << so that exceptions can be printed to
*		console window
************************************************************/
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class Exception
{
public:
	Exception();
	Exception(char * msg);
	Exception(const Exception & copy);
	~Exception();

	const char* GetMessage();
	void SetMessage(char * msg);

	Exception& operator=(const Exception & rhs);
	
	friend ostream& operator<<(ostream & stream, const Exception & except);

private:
	char* m_msg;
};

#endif