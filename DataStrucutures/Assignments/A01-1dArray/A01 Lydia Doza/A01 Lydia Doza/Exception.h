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

	const char* GetMessage() const;
	void SetMessage(char * msg);

	Exception& operator=(const Exception & rhs);
	
	friend ostream& operator<<(ostream & stream, const Exception & except);

private:
	char* m_msg;
};

#endif