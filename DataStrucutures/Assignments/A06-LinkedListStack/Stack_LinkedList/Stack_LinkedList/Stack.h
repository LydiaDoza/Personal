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
*	
*
************************************************************/
#ifndef STACK_H
#define STACK_H

#include "doublelinkedlist.h"
#include "Exception.h"
#include "Node.h"

template <typename T>
class Stack
{
public:
	Stack();
	Stack(const Stack & copy);
	~Stack();
	
	Stack& operator=(const Stack & rhs);

	void Push(T data);
	T Pop();
	T Peek();
	int Size();
	bool isEmpty();
	
private:
	int m_items;
	DoubleLinkedList<T> d_link_list;
};

/**************************************************************
*	Purpose: 	Default Ctor
*
*	Entry:		None
*
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename T>
Stack<T>::Stack() : m_items(0), d_link_list()
{

}

/**************************************************************
*	Purpose:	Copy Ctor
*
*	Entry:		data member to be copied
*
*	Exit:		this is equal to copy
****************************************************************/
template <typename T>
Stack<T>::Stack(const Stack<T> & copy)
{
	*this = copy;
}

/**************************************************************
*	Purpose:	Dtor
*
*	Entry:		None
*
*	Exit:		Memory deallocated, members set back to zero
*				or nullptr
****************************************************************/
template <typename T>
Stack<T>::~Stack()
{
	m_items = 0; 
	// d_link_list handles itself
}

/**************************************************************
*	Purpose:	op equals
*
*	Entry:		Stack rhs
*
*	Exit:		this is equal to rhs
****************************************************************/
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T> & rhs)
{
	if (this != &rhs)
	{
		m_items = rhs.m_items;
		d_link_list = rhs.d_link_list;
	}

return *this;
}

/**********************************************************************
* Purpose:	pushes data to top of stack and grows stack
*
* Entry:	T data
*
* Exit:		stack is one bigger with data on top
************************************************************************/
template <typename T>
void Stack<T>::Push(T data)
{
	d_link_list.Append(data);
	++m_items;
}

/**********************************************************************
* Purpose:	Takes item off top of list.
*
* Entry:	None.
*
* Exit:		Last item on stack is returned
************************************************************************/
template <typename T>
T Stack<T>::Pop()
{
	if (m_items == 0)
		throw Exception("ERROR: cannot Pop from empty list.");
	T temp = d_link_list.Last();
	d_link_list.Extract(d_link_list.Last());

	--m_items;

	return temp;
}

/**********************************************************************
* Purpose:	Returns top of stack but keeps it there
*
* Entry:	None
*
* Exit:		top of stack
************************************************************************/
template <typename T>
T Stack<T>::Peek()
{
	return d_link_list.Last;
}

/**********************************************************************
* Purpose:	Returns number of items in stack
*
* Entry:	none
*
* Exit:		m_items
************************************************************************/
template <typename T>
int Stack<T>::Size()
{
	return m_items;
}

/**********************************************************************
* Purpose:	Returns true if there are 0 items in stack
*
* Entry:	None
*
* Exit:		True or false
************************************************************************/
template <typename T>
bool Stack<T>::isEmpty()
{
	return (m_items == 0);
}

#endif