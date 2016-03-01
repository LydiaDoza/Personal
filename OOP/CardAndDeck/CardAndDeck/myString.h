/************************************************************************
* Class: String
*
* Constructors:
*	String(const char* = "")
*		Creates a string and sets it to input string of characters
*	String(char)
*		Creates a string of a character
*
* Destructors:
*	~String()
*		Deallocates String, sets ptr to nullptr
*
* Managers:
*	String(const String & obj)
*		Copy ctor
*************************************************************************/
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstring> // new header (rather than string.h)



class String
{
public:
	inline String(const char* = "");
	inline String(char ch);
	inline String(const String&); // Copy constructor
	~String() { delete[] ptr; ptr = nullptr; }

	inline String& operator=(const String & other);
	inline bool operator!=(const String & other) const;
	inline bool operator == (const String & other) const;

	inline void Display() const;
	inline void Display(char word[]) const;

private:
	char* ptr;
};

/**************************************************************
*	Name:
*		String(cont char* p)
*
*	Purpose:
*		Creates a new String instance with value p.
*
*	Entry
*		String of characters p.
*
*	Exit:
*		String instance created.
****************************************************************/
inline String::String(const char* p)
{
	p = p ? p : "";
	ptr = new char[strlen(p) + 1];
	strcpy(ptr, p);
}

/**************************************************************
*	Name:
*		String(char ch)
*
*	Purpose:
*		Creates String instance of a character.
*
*	Entry
*		A character.
*
*	Exit:
*		String instance created.
****************************************************************/
inline String::String(char ch)
{
	ptr = new char[2];
	ptr[0] = ch;
	ptr[1] = '\0';
}

/**************************************************************
*	Name:
*		String(const String & obj)
*
*	Purpose:
*		Copy constructor for string.
*
*	Entry
*		A string object
*
*	Exit:
*		String object copied into another string object
****************************************************************/
inline String::String(const String & obj) // Copy constructor
{
	ptr = new char[strlen(obj.ptr) + 1];
	strcpy(ptr, obj.ptr);
}

/**************************************************************
*	Name:
*		operator !=(const String & other)
*
*	Purpose:
*		Checks if other is not equal to *this
*
*	Entry
*		None.
*
*	Exit:
*		None.
****************************************************************/
inline bool String::operator!=(const String & other)  const
{
	return strcmp(ptr, other.ptr) != 0;
}

/**************************************************************
*	Name:
*		operator = (const String & obj)
*
*	Purpose:
*		this* set to parameters of other
*
*	Entry
*		None.
*
*	Exit:
*		None.
****************************************************************/
inline String& String::operator = (const String & other)
{
	if (this != &other)
	{
		delete ptr;
		ptr = new char[strlen(other.ptr) + 1];
		strcpy(ptr, other.ptr);
	}
	return *this;
}

/**************************************************************
*	Name:
*		operator == (const String & obj)
*
*	Purpose:
*		checks if *this is equal to other
*
*	Entry
*		None.
*
*	Exit:
*		None.
****************************************************************/
inline bool String::operator == (const String & other) const
{
	return strcmp(ptr, other.ptr) == 0;
}

/**************************************************************
*	Name:
*		String(const String & obj)
*
*	Purpose:
*		Copy constructor for string.
*
*	Entry
*		A string object
*
*	Exit:
*		String object copied into another string object
****************************************************************/
inline void String::Display() const
{
	cout << ptr;
}

/**************************************************************
*	Name:
*		String(const String & obj)
*
*	Purpose:
*		Copy constructor for string.
*
*	Entry
*		A string object
*
*	Exit:
*		String object copied into another string object
****************************************************************/
inline void String::Display(char word[]) const
{
	cout << ptr;
}
#endif