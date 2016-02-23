/***********************************************************
* Class:			BinarySearchTree
*
* Managers:
* 	BinarySearchTree()
* 		Default constructor
*	BinarySearchTree(const BinarySearchTree & copy)
* 		Copy Ctor
*	~BinarySearchTree()
*		Destructor
* 	void operator=(const BinarySearchTree & rhs)
*		Overload the = operator
*
* Public Methods:
*
*
************************************************************/
#ifndef THREADBST_H
#define THREADBST_H

#include "ThreadBSTNode.h"
#include "DLLQueue.h"
#include "Exception.h"
#include <iostream>
using std::endl;
template <typename T>
class ThreadBST
{
	template <typename T>
	friend class DLLQueue;

public:
	ThreadBST();
	ThreadBST(const ThreadBST<T> & copy);
	~ThreadBST();

	ThreadBST<T>& operator=(const ThreadBST<T> & rhs);

	void Insert(const T & data);
	void InsertRecurs(const T & data);

	void DeleteByCopy(ThreadBSTNode<T>*&node);
	void FindNodeAndDelete(const T & data);

	void Purge();

	int TotalHeight();
	int NodeHeight(ThreadBSTNode<T> * node);

	void TravInOrder(void(*Visit)(ThreadBSTNode<T>*));
	void TravPreOrder(void(*Visit)(ThreadBSTNode<T>*));
	void TravPostOrder(void(*Visit)(ThreadBSTNode<T>*));
	void TravBreadth(void(*Visit)(ThreadBSTNode<T>*));

	ThreadBSTNode<T>* Copy(const ThreadBSTNode<T> *root);

protected:
	int m_count;
	ThreadBSTNode<T> * m_root;

	void InsertRecurs(const T & data, ThreadBSTNode<T>*&root);
	void Purge(ThreadBSTNode<T>*&root);
	void TravInOrder(void(*Visit)(ThreadBSTNode<T>*), ThreadBSTNode<T>* root);
	void TravPreOrder(void(*Visit)(ThreadBSTNode<T>*), ThreadBSTNode<T>* root);
	void TravPostOrder(void(*Visit)(ThreadBSTNode<T>*), ThreadBSTNode<T>* root);
	int TotalHeight(ThreadBSTNode<T>* root);
};

/**************************************************************
*	Purpose: 	Default Ctor
*	Entry:		None
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename T>
ThreadBST<T>::ThreadBST() : m_root(nullptr), m_count(0)
{

}

/**************************************************************
*	Purpose:	Copy Ctor
*	Entry:		data member to be copied
*	Exit:		this is equal to copy
****************************************************************/
template <typename T>
ThreadBST<T>::ThreadBST(const ThreadBST<T> & copy) : m_root(nullptr)
{
	*this = copy;
}

/**************************************************************
*	Purpose:	Dtor
*	Entry:		None
*	Exit:		Memory deallocated, members set back to zero
*				or nullptr
****************************************************************/
template <typename T>
ThreadBST<T>::~ThreadBST()
{
	Purge();
	m_root = nullptr;
	m_count = 0;
}

/**************************************************************
*	Purpose:	op equals
*	Entry:		BinarySearchTree rhs
*	Exit:		this is equal to rhs
****************************************************************/
template <typename T>
ThreadBST<T>& ThreadBST<T>::operator=(const ThreadBST<T> & rhs)
{
	if (this != &rhs)
	{
		Purge();
		m_root = Copy(rhs.m_root);
		m_count = rhs.m_count;
	}
	return *this;
}

/**********************************************************************
* Purpose:	creates a new node and inserts it into binary search tree
*			Iteratively
* Entry:	T data
* Exit:		new node is inserted into binary search tree
************************************************************************/
template <typename T>
void ThreadBST<T>::Insert(const T & data)
{
	ThreadBSTNode<T> * new_node = new ThreadBSTNode<T>(data);
	ThreadBSTNode<T> * travel = m_root;
	ThreadBSTNode<T> * prev = nullptr;

	// go through tree until correct spot is found
	while (travel != nullptr)
	{
		prev = travel;
		if (data < travel->GetData())
			travel = travel->GetLeft();
		else
			travel = travel->GetRight();
	}

	if (m_root == nullptr)
	{
		m_root = new_node;
		++m_count;
	}
	else if (data < prev->GetData())
	{
		prev->SetLeft(new_node);
		prev->m_left->m_parent = prev;
		++m_count;
	}
	else
	{
		prev->SetRight(new_node);
		prev->m_right->m_parent = prev;
		++m_count;
	}
}

/**********************************************************************
* Purpose:	public access to recursive insert
* Entry: 	T data
* Exit:		void
************************************************************************/
template <typename T>
void ThreadBST<T>::InsertRecurs(const T & data)
{
	if (root->m_data == data)
		throw Exception("Data already exists in tree.");
	InsertRecurs(data, m_root);
	++m_count;
}

/**********************************************************************
* Purpose:	Called by InsertRecurs above
* Entry:	BSTNode<T>* root, T data
* Exit:		root inserted
************************************************************************/
template <typename T>
void ThreadBST<T>::InsertRecurs(const T & data, ThreadBSTNode<T>*&root)
{
	bool nu = false;

	// if finally at an empty spot insert new root
	if (root == nullptr)
		root = new ThreadBSTNode<T>(data);
	else // recursively call function passing appropriate pointer
	{
		if (data < root->m_data)
		{
			if (root->m_left == nullptr)
				nu = true;

			InsertRecurs(data, root->m_left);

			if (nu)
				root->m_left->m_parent = root;
		}
		else
		{
			if (root->m_right == nullptr)
				nu = true;

			InsertRecurs(data, root->m_right);

			if (nu)
				root->m_right->m_parent = root;
		}
	}
}

/**********************************************************************
* Purpose:	Deletes node from tree
* Entry:	T data
* Exit:		node deleted
************************************************************************/
template <typename T>
void ThreadBST<T>::DeleteByCopy(ThreadBSTNode<T> *& node)
{
	ThreadBSTNode<T>* temp = node;
	ThreadBSTNode<T>* prev = nullptr;

	if (node == nullptr)
		throw Exception("ERROR: not in tree");
	// no children
	else if (node->m_left == nullptr && node->m_right == nullptr)
	{
		delete node;
		node = nullptr;
	}
	else // has children
	{
		// only right child
		if (node->m_left == nullptr)
			node = node->m_right;
		// only left child
		else if (node->m_right == nullptr)
			node = node->m_left;
		// both children
		else
		{
			temp = node->m_left;
			prev = node;
			// get left subtree's rightmost child
			while (temp->m_right != nullptr)
			{
				prev = temp;
				temp = temp->m_right;
			}
			// set node's data
			node->m_data = temp->m_data;

			if (prev == node)
				prev->m_left = temp->m_left;
			else
				prev->m_right = temp->m_left;
		}
		delete temp;
		temp = nullptr;
	}
	--m_count;
}

/**********************************************************************
* Purpose:	Finds data in tree and calls delete by copy
* Entry:	T data
* Exit:		either a delete will happen or nothing will
************************************************************************/
template <typename T>
void ThreadBST<T>::FindNodeAndDelete(const T & data)
{
	if (m_root == nullptr)
		throw Exception("ERROR: Tree is empty.");
	else
	{
		ThreadBSTNode<T>* travel = m_root;
		ThreadBSTNode<T>* prev = nullptr;
		bool found = false;
		// while we are in the tree and while we haven't found
		// the node with data in it
		while (travel != nullptr && !found)
		{
			if (travel->m_data == data)
				found = true;
			else
			{
				prev = travel;

				if (data < travel->m_data)
					travel = travel->m_left;
				else
					travel = travel->m_right;
			}
		}

		// travel left tree or travel data isn't desired data
		if (travel == nullptr || !found)
			throw Exception("ERROR: Data not found in tree.");
		// we are in tree and data is found
		else
		{
			if (travel == m_root)
				DeleteByCopy(m_root);
			else if (data < prev->m_data)
				DeleteByCopy(prev->m_left);
			else
				DeleteByCopy(prev->m_right);
		}
	}
	--m_count;
}

/**********************************************************************
* Purpose:	Completely empties tree. Calls Recurseive Purge Function
* Entry:	None.
* Exit:		Binary Search Tree is now empty.
************************************************************************/
template <typename T>
void ThreadBST<T>::Purge()
{
	Purge(m_root);
}

/**********************************************************************
* Purpose:	Called by Purge for recursion
* Entry: 	Node<T>*root
* Exit:		Tree is now empty
************************************************************************/
template <typename T>
void ThreadBST<T>::Purge(ThreadBSTNode<T>*&root)
{
	if (root != nullptr)
	{
		Purge(root->m_left);
		Purge(root->m_right);
		delete root;
		root = nullptr;
		m_count = 0;
	}
}

/**********************************************************************
* Purpose:	Returns longest height in binary tree
* Entry:	none
* Exit:		integer height
************************************************************************/
template <typename T>
int ThreadBST<T>::TotalHeight()
{
	return TotalHeight(m_root);
}

/**********************************************************************
* Purpose:	called from no arg height for recursion
* Entry: 	BSTNode* root
* Exit:		height
************************************************************************/
template <typename T>
int ThreadBST<T>::TotalHeight(ThreadBSTNode<T>* root)
{
	int left_height = 0;
	int right_height = 0;

	if (root != nullptr)
	{
		if (root->m_left != nullptr)
			left_height = 1 + TotalHeight(root->m_left);

		if (root->m_right != nullptr)
			right_height = 1 + TotalHeight(root->m_right);
	}
	// larger of left and right heights
	return (left_height > right_height) ? left_height : right_height;
}

/**********************************************************************
* Purpose:	Finds height of node.
* Entry: 	ThreadBST<T> * node
* Exit:		int height of node.
************************************************************************/
template <typename T>
int ThreadBST<T>::NodeHeight(ThreadBSTNode<T> * node)
{
	int h(0);
	if (node->m_parent != nullptr)
		h = 1 + NodeHeight(node->m_parent);
	return h;
}

/**********************************************************************
* Purpose:	Traverses the binary search tree
* Entry:	function pointer void function(Node<T>*)
* Exit:		each node is visited
************************************************************************/
template <typename T>
void ThreadBST<T>::TravInOrder(void(*Visit)(ThreadBSTNode<T>*))
{
	TravInOrder(Visit, m_root);
}

/**********************************************************************
* Purpose:	Visits every node.
* Entry: 	void(*Visit)(Node<T>*), Node<T>* root
* Exit:		each node is visited
************************************************************************/
template <typename T>
void ThreadBST<T>::TravInOrder(void(*Visit)(ThreadBSTNode<T>*), ThreadBSTNode<T>* root)
{
	if (root != nullptr)
	{
		TravInOrder(Visit, root->m_left);
		Visit(root);
		TravInOrder(Visit, root->m_right);
	}
}

/**********************************************************************
* Purpose:	Visits every node in tree
* Entry:	function pointer void funciton(Node<T>*)
* Exit:		every node is visited
************************************************************************/
template <typename T>
void ThreadBST<T>::TravPreOrder(void(*Visit)(ThreadBSTNode<T>*))
{
	TravPreOrder(Visit, m_root);
}

/**********************************************************************
* Purpose:	visits each node
* Entry: 	void(*Visit)(Node<T>*), Node<T>* root
* Exit:		every node in tree is visited
************************************************************************/
template <typename T>
void ThreadBST<T>::TravPreOrder(void(*Visit)(ThreadBSTNode<T>*), ThreadBSTNode<T>* root)
{
	if (root != nullptr)
	{
		Visit(root);
		TravPreOrder(Visit, root->m_left);
		TravPreOrder(Visit, root->m_right);
	}
}

/**********************************************************************
* Purpose:	Uses post order traversal method
* Entry:	funciton pointer: void function(Node<T>*)
* Exit:		Every node is visited
************************************************************************/
template <typename T>
void ThreadBST<T>::TravPostOrder(void(*Visit)(ThreadBSTNode<T>*))
{
	TravPostOrder(Visit, m_root);
}

/**********************************************************************
* Purpose:	Post order traversal
* Entry: 	void(*Visit)(Node<T>*), Node<T>* root
* Exit:		every node in tree is visited
************************************************************************/
template <typename T>
void ThreadBST<T>::TravPostOrder(void(*Visit)(ThreadBSTNode<T>*), ThreadBSTNode<T>* root)
{
	if (root != nullptr)
	{
		TravPostOrder(Visit, root->m_left);
		TravPostOrder(Visit, root->m_right);
		Visit(root);
	}
}

/**********************************************************************
* Purpose:	Uses Breadth First traverse method on tree
* Entry:	function pointer: void function(Node<T>*)
* Exit:		every node is visited
************************************************************************/
template <typename T>
void ThreadBST<T>::TravBreadth(void(*Visit)(ThreadBSTNode<T>*))
{
	ThreadBSTNode<T> * travel = m_root;
	DLLQueue<ThreadBSTNode<T>*> q;
	if (travel != nullptr)
	{
		q.Enqueue(travel);
		while (!q.isEmpty())
		{
			travel = q.Dequeue();
			Visit(travel);

			// for testing
			if (travel->m_data == 'E' ||
				travel->m_data == 'I' ||
				travel->m_data == 'S' ||
				travel->m_data == 'H')
				cout << endl;

			if (travel->m_left != nullptr)
				q.Enqueue(travel->m_left);

			if (travel->m_right != nullptr)
				q.Enqueue(travel->m_right);
		}
	}
}

/**********************************************************************
* Purpose:	Deep copy for tree by recursion
* Entry: 	const Node<T>&*copy
* Exit:		void
************************************************************************/
template <typename T>
ThreadBSTNode<T>* ThreadBST<T>::Copy(const ThreadBSTNode<T>* root)
{
	ThreadBSTNode<T> * copy = nullptr;

	if (root != nullptr)
	{
		copy = new ThreadBSTNode<T>(root->m_data);
		copy->m_left = Copy(root->m_left);
		copy->m_right = Copy(root->m_right);

		if (copy->m_left)
			copy->m_left->m_parent = copy;
		if (copy->m_right)
			copy->m_right->m_parent = copy;
	}
	return copy;
}

#endif