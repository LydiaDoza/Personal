// Start Up Code for In-Lab #6 - Part II -- NEED TO FIX FIRST!
// These errors were added for fun - and to help keep you on your toes.
// Have fun!

#include <istream>
#include <string>

#include "myString.h"


class String
{
 public:
	String(const char* = "");
	String(const String&);
	~String();
	String& operator=(const String&);
	void display() const;
 private:
   char* ptr;
};


String::String(const char* p) : ptr(0)
{
   p = p ? p : "";
   ptr = new char[strlen(p) + 1];
   strcpy(ptr, p);
}

String::String(const String& S) : ptr(0)
{
   ptr = new char[strlen(S.ptr) + 1];
   strcpy(ptr, S.ptr);
}

String::~String()
{
   delete [] ptr;
}

//HEY - CHECK THIS OUT CAREFULLY!  Pretty nice and YOU must be able to explain every line!
String& String::operator=(const String& S)
{
   if(this != &S)
   {
      if(strlen(S.ptr) != strlen(ptr))
      {
         delete [] ptr;
         ptr = new char[strlen(S.ptr) + 1];
      }
      strcpy(ptr, S.ptr);
   }
   return *this;
}


void String::display() const
{	cout << " Here is the string: " << ptr << endl;
}
