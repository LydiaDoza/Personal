/***********************************************************
* Class:			BreadthFirst
*
* Managers:
* 	BreadthFirst()
* 		Default constructor
*	BreadthFirst(const BreadthFirst & copy)
* 		Copy Ctor
*	~BreadthFirst()
*		Destructor
* 	void operator=(const BreadthFirst & rhs)
*		Overload the = operator
*
* Public Methods:
*
*
************************************************************/
#ifndef BREADTHFIRST_H
#define BREADTHFIRST_H

#include "TreeIterator.h"
#include "DLLQueue.h"

template <typename T>
class BreadthFirst : public TreeIterator < T >
{
public:
	BreadthFirst();
	BreadthFirst(const BinarySearchTree<T> & tree);
	BreadthFirst(const BreadthFirst & copy) = delete;
	~BreadthFirst();

	BreadthFirst& operator=(const BreadthFirst & rhs) = delete;

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
BreadthFirst<T>::BreadthFirst()
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
BreadthFirst<T>::BreadthFirst(const BinarySearchTree<T> & tree) :TreeIterator(tree)
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
BreadthFirst<T>::~BreadthFirst()
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
void BreadthFirst<T>::Reset()
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
void BreadthFirst<T>::Reset(BSTNode<T>* root)
{
	BSTNode<T> * travel = m_tree.m_root;
	DLLQueue<BSTNode<T>*> q;
	if (travel != nullptr)
	{
		q.Enqueue(travel);
		while (!q.isEmpty())
		{
			travel = q.Dequeue();
			BSTNode<T>* insert = new BSTNode<T>(*travel);
			m_q.Enqueue(insert);
			if (travel->m_left_subtree != nullptr)
				q.Enqueue(travel->m_left_subtree);

			if (travel->m_right_subtree != nullptr)
				q.Enqueue(travel->m_right_subtree);
		}
	}
}

#endif