/***********************************************************
* Class:			PreOrder
*
* Managers:
* 	PreOrder()
* 		Default constructor
*	PreOrder(const PreOrder & copy)
* 		Copy Ctor
*	~PreOrder()
*		Destructor
* 	void operator=(const PreOrder & rhs)
*		Overload the = operator
*
* Public Methods:
*
*
************************************************************/
#ifndef PREORDER_H
#define PREORDER_H

#include "TreeIterator.h"

template <typename T>
class PreOrder : public TreeIterator < T >
{
public:
	PreOrder();
	PreOrder(const BinarySearchTree<T> & tree);
	PreOrder(const PreOrder & copy) = delete;
	~PreOrder();

	PreOrder& operator=(const PreOrder & rhs) = delete;

	void Reset();
	void Reset(BSTNode<T>* root);

protected:
	// BSTNode<T> * m_current;
	// BinarySearchTree m_tree;
	// DLLQueue<T> m_q;
};

/**************************************************************
*	Purpose: 	Default Ctor
*
*	Entry:		None
*
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename T>
PreOrder<T>::PreOrder() 
{

}

/**********************************************************************
* Purpose:
*
* Entry: 	BinarySearchTree<T> tree
*
* Exit:		template <typename T>

************************************************************************/
template <typename T>
PreOrder<T>::PreOrder(const BinarySearchTree<T> & tree) :TreeIterator(tree)
{
	Reset();
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
PreOrder<T>::~PreOrder()
{

}


/**********************************************************************
* Purpose:
*
* Entry:
*
* Exit:		
************************************************************************/
template <typename T>
void PreOrder<T>::Reset()
{
	if (m_tree.m_root == nullptr)
		throw Exception("Tree is empty");

	while (!m_q.isEmpty())
		m_current = m_q.Dequeue();

	Reset(m_tree.m_root);
	m_current = m_q.Dequeue();
}

/**********************************************************************
* Purpose:
*
* Entry: 	BSTNode<T>* root
*
* Exit:		template <typename T>
void
************************************************************************/
template <typename T>
void PreOrder<T>::Reset(BSTNode<T>* root)
{
	if (root != nullptr)
	{
		BSTNode<T>* insert = new BSTNode<T>(*root);
		m_q.Enqueue(insert);
		Reset(root->m_left_subtree);
		Reset(root->m_right_subtree);
	}
}


#endif