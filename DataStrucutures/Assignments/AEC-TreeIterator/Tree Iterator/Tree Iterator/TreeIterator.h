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
#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include "BSTNode.h"
#include "BinarySearchTree.h"
#include "DLLQueue.h"

template <typename T>
class TreeIterator
{
public:
	TreeIterator();
	TreeIterator(const BinarySearchTree<T> & tree);
	TreeIterator(const TreeIterator & copy);
	~TreeIterator();

	TreeIterator& operator=(const TreeIterator & rhs);

	void MoveNext();
	bool IsDone();
	T GetCurrent();

protected:
	BSTNode<T>* m_current;
	BinarySearchTree<T> m_tree;
	DLLQueue<BSTNode<T>*> m_q;
};

/**************************************************************
*	Purpose: 	Default Ctor
*
*	Entry:		None
*
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename T>
TreeIterator<T>::TreeIterator() : m_tree(), m_current(nullptr), m_q()
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
TreeIterator<T>::TreeIterator(const BinarySearchTree<T> & tree) : m_tree(tree), m_current(nullptr), m_q()
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
TreeIterator<T>::TreeIterator(const TreeIterator<T> & copy) : m_current(nullptr)
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
TreeIterator<T>::~TreeIterator()
{
	m_current = nullptr;
	// m_tree and m_q handle themselves
}

/**************************************************************
*	Purpose:	op equals
*
*	Entry:		ForwardIterator rhs
*
*	Exit:		this is equal to rhs
****************************************************************/
template <typename T>
TreeIterator<T>& TreeIterator<T>::operator=(const TreeIterator<T> & rhs)
{
	if (this != &rhs)
	{
		m_tree = rhs.m_tree;
		m_current = rhs.m_current;
	}

	return *this;
}

/**********************************************************************
* Purpose:
*
* Entry:
*
* Exit:
************************************************************************/
template <typename T>
void TreeIterator<T>::MoveNext()
{
	if (m_q.isEmpty())
		m_current = nullptr;
	else
		m_current = m_q.Dequeue();
}

/**********************************************************************
* Purpose:	returns true if m_current is end of list
*
* Entry:	None.
*
* Exit:		true or false
************************************************************************/
template <typename T>
bool TreeIterator<T>::IsDone()
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
T TreeIterator<T>::GetCurrent()
{
	if (m_current == nullptr)
		throw Exception("ERROR: trying to access empty node.");

	return m_current->GetData();
}


#endif