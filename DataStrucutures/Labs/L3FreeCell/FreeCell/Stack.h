/***********************************************************
* Class:			Stack
*
* Managers:
* 	Stack()
* 		Default constructor
*	Stack(const Stack & copy)
* 		Copy Ctor
*	~Stack()
*		Destructor
* 	void operator=(const Stack & rhs)
*		Overload the = operator
*
* Public Methods:
*	void Push(T data)
*		pushes T to top of stack
*	T Pop()
*		Removes and returns top of stack
*	T Peek()
*		Returns top of stack
*	int Size()
*		Returns number of items on stack
************************************************************/
#ifndef STACK_H
#define STACK_H

#include "Array.h"
#include "Exception.h"

template <typename T>
class Stack
{
public:
	Stack();
	Stack(int size);
	Stack(const Stack<T> & copy);
	~Stack();

	Stack<T>& operator=(const Stack<T> & rhs);

	void Push(T data);
	T Pop();
	T Peek();
	int Size();
	bool IsEmpty();
	bool IsFull();

private:
	Array<T> m_array;
	int m_size;
	int m_items;
};

/**********************************************************************
* Purpose:	creates an array based stack of m_size size
* Entry:	int size
* Exit:		stack created
************************************************************************/
template <typename T>
Stack<T>::Stack(int size) : m_array(size), m_size(size), m_items(0)
{}

/**************************************************************
*	Purpose: 	Default Ctor
*	Entry:		None
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename T>
Stack<T>::Stack() : m_array(), m_size(0), m_items(0)
{}

/**************************************************************
*	Purpose:	Copy Ctor
*	Entry:		data member to be copied
*	Exit:		this is equal to copy
****************************************************************/
template <typename T>
Stack<T>::Stack(const Stack<T> & copy)
	: m_array(copy.m_array), m_items(copy.m_items), m_size(copy.m_size)
{	  }

/**************************************************************
*	Purpose:	Dtor
*	Entry:		None
*	Exit:		Memory deallocated, members set back to zero
*				or nullptr
****************************************************************/
template <typename T>
Stack<T>::~Stack()
{
	// Array.h handles itself
	m_items = 0;
	m_size = 0;
}

/**************************************************************
*	Purpose:	op equals
*	Entry:		Stack rhs
*	Exit:		this is equal to rhs
****************************************************************/
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T> & rhs)
{
	if (this != &rhs)
	{
		m_array = rhs.m_array;
		m_size = rhs.m_size;
		m_items = rhs.m_items;
	}
	return *this;
}

/**********************************************************************
* Purpose:	Adds data to top of stack
* Entry:	T data
* Exit:		data pushed to top of stack
************************************************************************/
template <typename T>
void Stack<T>::Push(T data)
{
	if (IsFull())
		throw Exception("Can't push to full stack");

	m_array[m_items++] = data;
}

/**********************************************************************
* Purpose:	Takes top of stack off and returns it
* Entry:	None.
* Exit:		T data from top of stack
************************************************************************/
template <typename T>
T Stack<T>::Pop()
{
	if (IsEmpty())
		throw Exception("Can't Pop from empty Stack");

	return m_array[--m_items];
}

/**********************************************************************
* Purpose:	Returns top of stack, but keeps it on stack.
* Entry:	none
* Exit:		top of stack
************************************************************************/
template <typename T>
T Stack<T>::Peek()
{	return m_array[m_items];   }

/**********************************************************************
* Purpose:	Returns number of items in stack
* Entry:	none
* Exit:		size 
************************************************************************/
template <typename T>
int Stack<T>::Size()
{	return m_items;   }

/**********************************************************************
* Purpose:	true if size is 0 in stack
* Entry:	none
* Exit:		true or false
************************************************************************/
template <typename T>
bool Stack<T>::IsEmpty()
{	return (m_items == 0);   }

/**********************************************************************
* Purpose:	returns true if stack is full
* Entry:	none
* Exit:		true or false
************************************************************************/
template <typename T>
bool Stack<T>::IsFull()
{	return (m_items == m_size);   }

#endif