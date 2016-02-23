/***********************************************************
* Abstract Class:			ListIterator
* 		
* Managers:
* 	ListIterator()
* 		Default constructor
*	ListIterator(const ListIterator & copy)
* 		Copy Ctor
*	~ListIterator()
*		Destructor
* 	void operator=(const ListIterator & rhs)
*		Overload the = operator
*
* Public Methods:
*	
*
************************************************************/
#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "iIterator.h"
#include "doublelinkedlist.h"

template <typename T>
class ListIterator : public iIterator<T>
{
public:
	ListIterator();
	ListIterator(DoubleLinkedList<T> list);
	ListIterator(const ListIterator & copy) = delete;
	~ListIterator();
	
	ListIterator& operator=(const ListIterator & rhs) = delete;
	
protected:
	DoubleLinkedList<T> m_list;
};

/**************************************************************
*	Purpose: 	Default Ctor
*
*	Entry:		None
*
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename T>
ListIterator<T>::ListIterator() : m_list()
{

}

/**********************************************************************
* Purpose:	1 arg ctor to pass in a list.
*
* Entry:	DoubleLinkedList<T> list
*
* Exit:		m_list is initialized to list
************************************************************************/
template <typename T>
ListIterator<T>::ListIterator(DoubleLinkedList<T> list) : m_list(list)
{

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
ListIterator<T>::~ListIterator()
{
	// DoubleLinkedList handles it's own dtor schedule
}

#endif