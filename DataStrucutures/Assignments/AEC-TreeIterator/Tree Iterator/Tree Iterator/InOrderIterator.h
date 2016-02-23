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
#ifndef INORDERITERATOR_H
#define INORDERITERATOR_H

#include "TreeIterator.h"
#include "BinarySearchTree.h"

template <typename T>
class InOrderIterator : public TreeIterator < T >
{
public:
	InOrderIterator();
	InOrderIterator(const BinarySearchTree<T> & list);
	InOrderIterator(const InOrderIterator & copy) = delete;
	~InOrderIterator();

	InOrderIterator& operator=(const InOrderIterator & rhs) = delete;

	void Reset();
	void Reset(BSTNode<T>* root);

protected:
	// BSTNode<T> * m_current;
	// BinarySearchTree m_tree;
	// DLLQueue<BSTNode<T>* m_q;
};

/**********************************************************************
* Purpose:	Default Constructor, initializes stuff to null/zero/
*			default initializers
*
* Entry:	None
*
* Exit:		template <typename T>

************************************************************************/
template <typename T>
InOrderIterator<T>::InOrderIterator() : 
{

}

/**********************************************************************
* Purpose:	1 arg ctor initializes stuff
*
* Entry: 	BinarySearchTree<T> list
*
* Exit:		template <typename T>

************************************************************************/
template <typename T>
InOrderIterator<T>::InOrderIterator(const BinarySearchTree<T> & tree) : TreeIterator(tree)
{
	Reset();
}

template <typename T>
InOrderIterator<T>::~InOrderIterator()
{
	
}

template <typename T>
void InOrderIterator<T>::Reset()
{
	if (m_tree.m_root == nullptr)
		throw Exception("Tree is empty");

	while (!m_q.isEmpty())
		m_current = m_q.Dequeue();

	Reset(m_tree.m_root);
	m_current = m_q.Dequeue();
}

template <typename T>
void InOrderIterator<T>::Reset(BSTNode<T>* root)
{
	if (root != nullptr)
	{
		BSTNode<T>* insert = new BSTNode<T>(*root);
		Reset(root->m_left_subtree);
		m_q.Enqueue(insert);
		Reset(root->m_right_subtree);
	}
}

#endif