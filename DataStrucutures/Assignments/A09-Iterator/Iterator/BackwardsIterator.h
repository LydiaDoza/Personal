/***********************************************************
* Class:			BackwardsIterator
*
* Managers:
* 	BackwardsIterator()
* 		Default constructor
*	BackwardsIterator(const BackwardsIterator & copy)
* 		Copy Ctor
*	~BackwardsIterator()
*		Destructor
* 	void operator=(const BackwardsIterator & rhs)
*		Overload the = operator
*
* Public Methods:
*
*
************************************************************/
#ifndef BACKWARDSITERATOR_H
#define BACKWARDSITERATOR_H

#include "ListIterator.h"
#include "Node.h"
#include "doublelinkedlist.h"
#include "Exception.h"

template <typename T>
class BackwardsIterator : public ListIterator < T >
{
public:
	BackwardsIterator();
	BackwardsIterator(DoubleLinkedList<T> list);
	BackwardsIterator(const BackwardsIterator & copy);
	~BackwardsIterator();

	BackwardsIterator& operator=(const BackwardsIterator & rhs);

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
BackwardsIterator<T>::BackwardsIterator() : m_list()
{

}

/**********************************************************************
* Purpose:	1 Arg Ctor
*
* Entry:	DoubleLinkedList<T> list
*
* Exit:		m_list is set to list.
************************************************************************/
template <typename T>
BackwardsIterator<T>::BackwardsIterator(DoubleLinkedList<T> list) : ListIterator(list), m_current(nullptr)
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
BackwardsIterator<T>::BackwardsIterator(const BackwardsIterator<T> & copy)
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
BackwardsIterator<T>::~BackwardsIterator()
{
	m_current = nullptr;
	//m_list handles itself in its class
}

/**************************************************************
*	Purpose:	op equals
*
*	Entry:		BackwardsIterator rhs
*
*	Exit:		this is equal to rhs
****************************************************************/
template <typename T>
BackwardsIterator<T>& BackwardsIterator<T>::operator=(const BackwardsIterator<T> & rhs)
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
void BackwardsIterator<T>::MoveNext()
{
	if (m_list.isEmpty())
		throw Exception("ERROR: List is empty.");
	else if (m_list.getHead() == m_list.getTail())
		throw Exception("ERROR: List only has one element.");
	else if (IsDone())
		throw Exception("ERROR: End of List reached, cannot go next.");
	else
		m_current = m_list.Search(m_current->GetData())->GetPrev();
}

/**********************************************************************
* Purpose:	Sets m_current to last item in list
*
* Entry:	None.
*
* Exit:		m_current set to head.
************************************************************************/
template <typename T>
void BackwardsIterator<T>::Reset()
{
	m_current = m_list.getTail();
}


/**********************************************************************
* Purpose:	returns true if m_current is end of list
*
* Entry:	None.
*
* Exit:		true or false
************************************************************************/
template <typename T>
bool BackwardsIterator<T>::IsDone()
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
T BackwardsIterator<T>::GetCurrent()
{
	if (m_current == nullptr)
		throw Exception("ERROR: list is empty.");

	return m_current->GetData();
}


#endif