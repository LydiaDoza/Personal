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
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BSTNode.h"
#include "DLLQueue.h"
#include "Exception.h"

template <typename T>
class BinarySearchTree
{
	template <typename T>
	friend class DLLQueue;

public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree & copy);
	~BinarySearchTree();

	BinarySearchTree& operator=(const BinarySearchTree & rhs);

	void Insert(const T & data);
	void InsertRecurs(const T & data);

	void DeleteByCopy(BSTNode<T>*&node);
	void FindNodeAndDelete(const T & data);

	void Purge();

	int Height();

	void TravInOrder(void(*Visit)(BSTNode<T>*));
	void TravPreOrder(void(*Visit)(BSTNode<T>*));
	void TravPostOrder(void(*Visit)(BSTNode<T>*));
	void TravBreadth(void(*Visit)(BSTNode<T>*));

	BSTNode<T>* Copy(const BSTNode<T> *root);

private:
	BSTNode<T> * m_root;

	void InsertRecurs(const T & data, BSTNode<T>*&root);
	void Purge(BSTNode<T>*&root);
	void TravInOrder(void(*Visit)(BSTNode<T>*), BSTNode<T>* root);
	void TravPreOrder(void(*Visit)(BSTNode<T>*), BSTNode<T>* root);
	void TravPostOrder(void(*Visit)(BSTNode<T>*), BSTNode<T>* root);
	int Height(BSTNode<T>* root);
};

/**************************************************************
*	Purpose: 	Default Ctor
*	Entry:		None
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename T>
BinarySearchTree<T>::BinarySearchTree() : m_root(nullptr)
{}

/**************************************************************
*	Purpose:	Copy Ctor
*	Entry:		data member to be copied
*	Exit:		this is equal to copy
****************************************************************/
template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> & copy) :m_root(nullptr)
{
	m_root = Copy(copy.m_root);
}

/**************************************************************
*	Purpose:	Dtor
*	Entry:		None
*	Exit:		Memory deallocated, members set back to zero
*				or nullptr
****************************************************************/
template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	Purge();
	m_root = nullptr;
}

/**************************************************************
*	Purpose:	op equals
*	Entry:		BinarySearchTree rhs
*	Exit:		this is equal to rhs
****************************************************************/
template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T> & rhs)
{
	if (this != &rhs)
	{
		Purge();
		m_root = Copy(rhs.m_root);
	}

	return *this;
}

/**********************************************************************
* Purpose:	creates a new node and inserts it into binary search tree
* Entry:	T data
* Exit:		new node is inserted into binary search tree
************************************************************************/
template <typename T>
void BinarySearchTree<T>::Insert(const T & data)
{
	BSTNode<T> * new_node = new BSTNode<T>(data);
	BSTNode<T> * travel = m_root;
	BSTNode<T> * prev = nullptr;

	while (travel != nullptr)
	{
		prev = travel;
		if (data < travel->m_data)
			travel = travel->m_left;
		else
			travel = travel->m_right;
	}

	if (m_root == nullptr)
		m_root = new_node;
	else if (data < prev->m_data)
		prev->SetLeft(new_node);
	else
		prev->SetRight(new_node);
}

/**********************************************************************
* Purpose:	public access to recursive insert
* Entry: 	T data
* Exit:		void
************************************************************************/
template <typename T>
void BinarySearchTree<T>::InsertRecurs(const T & data)
{
	InsertRecurs(data, m_root);
}

/**********************************************************************
* Purpose:	Called by InsertRecurs above
* Entry:	BSTNode<T>* root, T data
* Exit:		root inserted
************************************************************************/
template <typename T>
void BinarySearchTree<T>::InsertRecurs(const T & data, BSTNode<T>*&root)
{
	if (root == nullptr)
		root = new BSTNode<T>(data);
	else
	{
		if (data < root->m_data)
			InsertRecurs(data, root->m_left);
		else
			InsertRecurs(data, root->m_right);
	}
}

/**********************************************************************
* Purpose:	Deletes node from tree
* Entry:	T data
* Exit:		node deleted
************************************************************************/
template <typename T>
void BinarySearchTree<T>::DeleteByCopy(BSTNode<T> *& node)
{
	BSTNode<T>* temp = node;
	BSTNode<T>* prev = nullptr;

	if (node == nullptr)
		throw Exception("ERROR: not in tree");
	else if (node->m_left == nullptr && 
		node->m_right == nullptr) // lef
	{
		delete node;
		node = nullptr;
	}
	else // chitlins
	{
		if (node->m_left == nullptr) // right child
			node = node->m_right; 
		else if (node->m_right == nullptr) // left child
			node = node->m_left;
		else // both chitlins
		{
			temp = node->m_left;
			prev = node;
			while (temp->m_right != nullptr)
			{
				prev = temp;
				temp = temp->m_right;
			}
			node->m_data = temp->m_data;
			if (prev == node)
				prev->m_left = temp->m_left;
			else
				prev->m_right = temp->m_left;
		}
		delete temp;
		temp = nullptr;
	}
}

/**********************************************************************
* Purpose:	Finds data in tree and calls delete by copy
* Entry:	T data
* Exit:		either a delete will happen or nothing will
************************************************************************/
template <typename T>
void BinarySearchTree<T>::FindNodeAndDelete(const T & data)
{
	if (m_root == nullptr)
		throw Exception("ERROR: Tree is empty.");
	else
	{
		BSTNode<T>* travel = m_root;
		BSTNode<T>* prev = nullptr;
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
}

/**********************************************************************
* Purpose:	Completely empties tree.
* Entry:	None.
* Exit:		Binary Search Tree is now empty.
************************************************************************/
template <typename T>
void BinarySearchTree<T>::Purge()
{
	Purge(m_root);
}

/**********************************************************************
* Purpose:	Called by Purge for recursion
* Entry: 	Node<T>*root
* Exit:		Tree is now empty
************************************************************************/
template <typename T>
void BinarySearchTree<T>::Purge(BSTNode<T>*&root)
{
	if (root != nullptr)
	{
		Purge(root->m_left);
		Purge(root->m_right);
		delete root;
		root = nullptr;
	}
}

/**********************************************************************
* Purpose:	Returns longest height in binary tree
* Entry:	none
* Exit:		integer height
************************************************************************/
template <typename T>
int BinarySearchTree<T>::Height()
{
	return Height(m_root);
}

/**********************************************************************
* Purpose:	called from no arg height for recursion
* Entry: 	BSTNode* root
* Exit:		height
************************************************************************/
template <typename T>
int BinarySearchTree<T>::Height(BSTNode<T>* root)
{
	int left_height = 0;
	int right_height = 0;

	if (root != nullptr)
	{
		if (root->m_left != nullptr)
			left_height = 1 + Height(root->m_left);

		if (root->m_right != nullptr)
			right_height = 1 + Height(root->m_right);
	}
	return (left_height > right_height) ? left_height : right_height;
}

/**********************************************************************
* Purpose:	Traverses the binary search tree
* Entry:	function pointer void function(Node<T>*)
* Exit:		each node is visited
************************************************************************/
template <typename T>
void BinarySearchTree<T>::TravInOrder(void(*Visit)(BSTNode<T>*))
{
	TravInOrder(Visit, m_root);
}

/**********************************************************************
* Purpose:	Visits every node.
* Entry: 	void(*Visit)(Node<T>*), Node<T>* root
* Exit:		each node is visited
************************************************************************/
template <typename T>
void BinarySearchTree<T>::TravInOrder(void(*Visit)(BSTNode<T>*), 
										BSTNode<T>* root)
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
void BinarySearchTree<T>::TravPreOrder(void(*Visit)(BSTNode<T>*))
{
	TravPreOrder(Visit, m_root);
}

/**********************************************************************
* Purpose:	visits each node
* Entry: 	void(*Visit)(Node<T>*), Node<T>* root
* Exit:		every node in tree is visited
************************************************************************/
template <typename T>
void BinarySearchTree<T>::TravPreOrder(void(*Visit)(BSTNode<T>*), 
										BSTNode<T>* root)
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
void BinarySearchTree<T>::TravPostOrder(void(*Visit)(BSTNode<T>*))
{
	TravPostOrder(Visit, m_root);
}

/**********************************************************************
* Purpose:	Post order traversal
* Entry: 	void(*Visit)(Node<T>*), Node<T>* root
* Exit:		every node in tree is visited
************************************************************************/
template <typename T>
void BinarySearchTree<T>::TravPostOrder(void(*Visit)(BSTNode<T>*), 
										BSTNode<T>* root)
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
void BinarySearchTree<T>::TravBreadth(void(*Visit)(BSTNode<T>*))
{
	BSTNode<T> * travel = m_root;
	DLLQueue<BSTNode<T>*> q;
	if (travel != nullptr)
	{
		q.Enqueue(travel);
		while (!q.isEmpty())
		{
			travel = q.Dequeue();
			Visit(travel);
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
BSTNode<T>* BinarySearchTree<T>::Copy(const BSTNode<T>* root)
{
	BSTNode<T> * copy = nullptr;

	if (root != nullptr)
	{
		copy = new BSTNode<T>(root->m_data);
		copy->m_left = Copy(root->m_left);
		copy->m_right = Copy(root->m_right);
	}
	return copy;
}
#endif