/***********************************************************
* Class:			ForwardIterator
*
* Managers:
* 	ForwardIterator()
* 		Default constructor
*	ForwardIterator(const ForwardIterator & copy)
* 		Copy Ctor
*	~ForwardIterator()
*		Destructor
* 	void operator=(const ForwardIterator & rhs)
*		Overload the = operator
*
* Public Methods:
*
*
************************************************************/
#ifndef FORWARDITERATOR_H
#define FORWARDITERATOR_H

#include "ListIterator.h"
#include "Node.h"
#include "doublelinkedlist.h"
#include "Exception.h"

template <typename T>
class ForwardIterator : public ListIterator < T >
{
public:
	ForwardIterator();
	ForwardIterator(DoubleLinkedList<T> list);
	ForwardIterator(const ForwardIterator & copy);
	~ForwardIterator();

	ForwardIterator& operator=(const ForwardIterator & rhs);

	void MoveNext();
	void Reset();
	bool IsDone();
	T GetCurrent();

private:
	Node<T>* m_current;
};

/**************************************************************
*	Purpose: 	Default Ctor
*
*	Entry:		None
*
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename T>
ForwardIterator<T>::ForwardIterator() : m_list(), m_current(nullptr)
{

}

/**********************************************************************
* Purpose:	1 arg ctor
*
* Entry:	DoubleLinkedList<T> list
*
* Exit:		m_list set to list and m_current set to head
************************************************************************/
template <typename T>
ForwardIterator<T>::ForwardIterator(DoubleLinkedList<T> list) : m_current(nullptr), ListIterator(list)
{
	Reset();
}

/**************************************************************
*	Purpose:	Copy Ctor
*
*	Entry:		data member to be copied
*
*	Exit:		this is equal to copy
****************************************************************/
template <typename T>
ForwardIterator<T>::ForwardIterator(const ForwardIterator<T> & copy) : m_current(nullptr)
{
	this = copy;
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
ForwardIterator<T>::~ForwardIterator()
{
	m_current = nullptr;
	// m_list handles itself in base class
}

/**************************************************************
*	Purpose:	op equals
*
*	Entry:		ForwardIterator rhs
*
*	Exit:		this is equal to rhs
****************************************************************/
template <typename T>
ForwardIterator<T>& ForwardIterator<T>::operator=(const ForwardIterator<T> & rhs)
{
	if (this != &rhs)
	{
		m_list = rhs.m_list;
		m_current = rhs.m_current;
	}

	return *this;
}

/**************************************************************
*	Purpose:	Moves current to next (after current)
*
*	Entry:		None.
*
*	Exit:		m_current is set the next
****************************************************************/
template <typename T>
void ForwardIterator<T>::MoveNext()
{
	if (m_list.isEmpty())
		throw Exception("ERROR: List is empty.");
	else if (m_list.getHead() == m_list.getTail())
		throw Exception("ERROR: List only has one element.");
	else if (IsDone())
		throw Exception("ERROR: End of List reached, cannot go next.");
	else
		m_current = m_list.Search(m_current->GetData())->GetNext();
}

/**********************************************************************
* Purpose:	Sets m_current to first item in list
*
* Entry:	None.
*
* Exit:		m_current set to head.
************************************************************************/
template <typename T>
void ForwardIterator<T>::Reset()
{
	m_current = m_list.getHead();
}


/**********************************************************************
* Purpose:	returns true if m_current is end of list
*
* Entry:	None.
*
* Exit:		true or false
************************************************************************/
template <typename T>
bool ForwardIterator<T>::IsDone()
{
	return (m_current == nullptr);
}

/**********************************************************************
* Purpose:	Returns current Node.
*
* Entry:	None.
*
* Exit:		m_current
************************************************************************/
template <typename T>
T ForwardIterator<T>::GetCurrent()
{
	if (m_current == nullptr)
		throw Exception("ERROR: list is empty.");

	return m_current->GetData();
}


#endif