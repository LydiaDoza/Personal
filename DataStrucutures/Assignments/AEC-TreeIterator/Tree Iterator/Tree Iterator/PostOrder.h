/***********************************************************
* Class:			PostOrder
* 		
* Managers:
* 	PostOrder()
* 		Default constructor
*	PostOrder(const PostOrder & copy)
* 		Copy Ctor
*	~PostOrder()
*		Destructor
* 	void operator=(const PostOrder & rhs)
*		Overload the = operator
*
* Public Methods:
*	
*
************************************************************/
#ifndef POSTORDER_H
#define POSTORDER_H

#include "TreeIterator.h"
#include "DLLQueue.h"

template <typename T>
class PostOrder : public TreeIterator<T>
{
public:
	PostOrder();
	PostOrder(const BinarySearchTree<T> & tree);
	PostOrder(const PostOrder & copy) = delete;
	~PostOrder();
	
	PostOrder& operator=(const PostOrder & rhs) = delete;

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
PostOrder<T>::PostOrder() 
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
PostOrder<T>::PostOrder(const BinarySearchTree<T> & tree) :TreeIterator(tree)
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
PostOrder<T>::~PostOrder()
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
void PostOrder<T>::Reset()
{
	if (m_tree.m_root != nullptr)
	{

		while (!m_q.isEmpty())
			m_current = m_q.Dequeue();

		Reset(m_tree.m_root);
		m_current = m_q.Dequeue();
	}
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
void PostOrder<T>::Reset(BSTNode<T>* root)
{
	if (root != nullptr)
	{
		BSTNode<T>* insert = new BSTNode<T>(*root);
		Reset(root->m_left_subtree);
		Reset(root->m_right_subtree);
		m_q.Enqueue(insert);
	}
}
#endif