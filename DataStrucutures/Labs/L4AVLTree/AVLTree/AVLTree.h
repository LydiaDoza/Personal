/***********************************************************
* Class:			AVLTree
*
* Managers:
* 	AVLTree()
* 		Default constructor
*	AVLTree(const AVLTree & copy)
* 		Copy Ctor
*	~AVLTree()
*		Destructor
* 	void operator=(const AVLTree & rhs)
*		Overload the = operator
*
* Public Methods:
*
*
************************************************************/
#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
using std::cout;
using std::endl;

#include "BinarySearchTree.h"
#include "BSTNode.h"

template <typename T>
class AVLTree : public BinarySearchTree < T >
{
public:
	AVLTree();
	AVLTree(const AVLTree & copy);
	~AVLTree();

	AVLTree& operator=(const AVLTree & rhs);

	void Insert(const T & data);

	void Delete(const T & data);

private:
	void Insert(const T & data, BSTNode<T>*&root, bool &taller);
	void LeftBalance(BSTNode<T>*& root, bool& taller);
	void RightBalance(BSTNode<T>*& root, bool& taller);
	void RotateLeft(BSTNode<T>*& root);
	void RotateRight(BSTNode<T>*& root);
	void RotateLR(BSTNode<T> *&root);
	void RotateRL(BSTNode<T> *&root);
	void Delete(const T & data, BSTNode<T> *&root);
	void Delete(BSTNode<T> * & node);
};
/**************************************************************
*	Purpose: 	Default Ctor
*	Entry:		None
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename T>
AVLTree<T>::AVLTree() : BinarySearchTree()
{

}

/**************************************************************
*	Purpose:	Copy Ctor
*	Entry:		data member to be copied
*	Exit:		this is equal to copy
****************************************************************/
template <typename T>
AVLTree<T>::AVLTree(const AVLTree<T> & copy) :m_root(nullptr)
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
AVLTree<T>::~AVLTree()
{
	//parent dtor
}

/**************************************************************
*	Purpose:	op equals
*	Entry:		AVLTree rhs
*	Exit:		this is equal to rhs
****************************************************************/
template <typename T>
AVLTree<T>& AVLTree<T>::operator=(const AVLTree<T> & rhs)
{
	if (this != &rhs)
	{
		BinarySearchTree<T>::operator =(rhs);
	}

	return *this;
}

/**********************************************************************
* Purpose:	inserts a node into AVL tree. Calls recursive insert.
* Entry: 	const T & data
* Exit:		node is created and inserting into AVL tree. Efficient. wow.
************************************************************************/
template <typename T>
void AVLTree<T>::Insert(const T & data)
{
	bool taller = false;
	Insert(data, m_root, taller);
}

/**********************************************************************
* Purpose:	uses recursion to insert data into AVL tree leaf node
* Entry: 	const T & data, BSTNode<T>*&root, bool &taller
* Exit:		node inserted to tree
************************************************************************/
template <typename T>
void AVLTree<T>::Insert(const T & data, BSTNode<T>*&root, bool &taller)
{
	if (root == nullptr)
	{
		root = new BSTNode<T>(data);
		taller = true;
	}
	else if (data < root->m_data)
	{
		//left subtree
		Insert(data, root->m_left, taller);
		if (taller)
		{
			switch (root->m_bf)
			{
			case BSTNode<T>::balfac::LH: // outta balance on left
				LeftBalance(root, taller);
				break;
			case BSTNode<T>::balfac::EH: // not out of balance
				root->m_bf = BSTNode<T>::LH;
				break;
			case BSTNode<T>::balfac::RH: // right heavy
				root->m_bf = BSTNode<T>::EH;
				taller = false;
				break;
			}
		}
	}
	else if (data > root->m_data)
	{
		//right subtree
		Insert(data, root->m_right, taller);
		if (taller)
		{
			switch (root->m_bf)
			{
			case BSTNode<T>::balfac::LH: // outta balance
				root->m_bf = BSTNode<T>::EH;
				taller = false;
				break;
			case BSTNode<T>::balfac::EH:
				root->m_bf = BSTNode<T>::RH;
				break;
			case BSTNode<T>::balfac::RH:
				RightBalance(root, taller);
				break;
			}
		}
	}
	else // data == root->m_data
		cout << "\nERROR: Data already exists in tree." << endl;
}

/**********************************************************************
* Purpose:	left rotate balance stuff
* Entry: 	BSTNode<T>* root, bool& taller
* Exit:		left rotate balance stuff
************************************************************************/
template <typename T>
void AVLTree<T>::LeftBalance(BSTNode<T>* &root, bool& taller)
{
	BSTNode<T>* left_tree(nullptr);
	BSTNode<T> *right_tree(nullptr);

	left_tree = root->m_left;
	switch (left_tree->m_bf)
	{
	case BSTNode<T>::LH:
		root->m_bf = BSTNode<T>::EH;
		left_tree->m_bf = BSTNode<T>::EH;
		RotateLeft(root);
		taller = false;
		break;
	case BSTNode<T>::EH:
		cout << "Error: leftBalance";
		break;
	case BSTNode<T>::RH:////
		right_tree = left_tree->m_right;
		switch (right_tree->m_bf)
		{
		case BSTNode<T>::LH:
			root->m_bf = BSTNode<T>::RH;
			left_tree->m_bf = BSTNode<T>::EH;
			break;
		case BSTNode<T>::EH:
			root->m_bf = BSTNode<T>::EH;
			left_tree->m_bf = BSTNode<T>::EH;
			break;
		case BSTNode<T>::RH:
			root->m_bf = BSTNode<T>::EH;
			left_tree->m_bf = BSTNode<T>::LH;
			break;
		}
		right_tree->m_bf = BSTNode<T>::EH;
		RotateLR(root);
		break;
	}
}

/**********************************************************************
* Purpose:	Checks that the right subtree is balanced
* Entry: 	BSTNode<T>*& root, bool& taller
* Exit:
************************************************************************/
template <typename T>
void AVLTree<T>::RightBalance(BSTNode<T>*& root, bool& taller)
{
	BSTNode<T>* left_tree(nullptr);
	BSTNode<T>*right_tree(nullptr);

	right_tree = root->m_right;
	switch (right_tree->m_bf)
	{
	case BSTNode<T>::LH:
		left_tree = right_tree->m_left;
		switch (right_tree->m_bf) // set balance factors
		{
		case BSTNode<T>::LH: // left heavy
			root->m_bf = BSTNode<T>::EH;
			right_tree->m_bf = BSTNode<T>::RH;
			break;
		case BSTNode<T>::EH:
			root->m_bf = BSTNode<T>::EH;
			right_tree->m_bf = BSTNode<T>::EH;
			break;
		case BSTNode<T>::RH:
			root->m_bf = BSTNode<T>::LH;
			right_tree->m_bf = BSTNode<T>::LH;
			break;
		}
		right_tree->m_bf = BSTNode<T>::EH;
		RotateRL(root);
		break;
	case BSTNode<T>::EH:
		cout << "Error: leftBalance";
		break;
	case BSTNode<T>::RH:
		root->m_bf = BSTNode<T>::EH;
		right_tree->m_bf = BSTNode<T>::EH;
		RotateRight(root);
		taller = false;
		break;
	}
}

/**********************************************************************
* Purpose:	Implements LL Rotation.
* Entry: 	BSTNode<T>*& root
* Exit:		Rotated
************************************************************************/
template <typename T>
void AVLTree<T>::RotateLeft(BSTNode<T>*& root)
{
	BSTNode<T>* temp = root;

	root = root->m_left;
	temp->m_left = root->m_right;
	root->m_right = temp;
}

/**********************************************************************
* Purpose:	Implements RR Rotation
* Entry: 	BSTNode<T>*& root
* Exit:		Rotated
************************************************************************/
template <typename T>
void AVLTree<T>::RotateRight(BSTNode<T>*& root)
{
	BSTNode<T>* temp = root;

	root = root->m_right;
	temp->m_right = root->m_left;
	root->m_left = temp;
}

/**********************************************************************
* Purpose:	Rotates Right then Left.
* Entry: 	BSTNode<T> *&root
* Exit:		errything rotated.
************************************************************************/
template <typename T>
void AVLTree<T>::RotateLR(BSTNode<T> *&root)
{
	RotateRight(root->m_left);
	RotateLeft(root);
}

/**********************************************************************
* Purpose:	uses LL rotation then RR rotation
* Entry: 	BSTNode<T> *&root
* Exit:		AVL tree is rebalanced
************************************************************************/
template <typename T>
void AVLTree<T>::RotateRL(BSTNode<T> *&root)
{
	RotateLeft(root->m_right);
	RotateRight(root);
}

/**********************************************************************
* Purpose:	finds and deletes node containing data from avl tree.
* Entry: 	const T & data
* Exit:		Either node is successfully deleted or a message is thrown
*			stating the node was not found/ does not exist.
************************************************************************/
template <typename T>
void AVLTree<T>::Delete(const T & data)
{
	if (m_root == nullptr)
		throw Exception("ERROR: tree has no branches.");

	Delete(data, m_root);
}

/**********************************************************************
* Purpose:	Deletes node containing data.
* Entry: 	const T & data, BSTNode<T> *&root
* Exit:		Node is deleted.
************************************************************************/
template <typename T>
void AVLTree<T>::Delete(const T & data, BSTNode<T> *&root)
{
	BSTNode<T> * temp = nullptr;

	if (root == nullptr)
		throw Exception("Data not found in tree.");
	if (data == root->m_data)
	{
		Delete(root);
	}
	else
	{
		if (data < root->m_data)	// data is smaller
			Delete(data, root->m_left);
		else							// data is larger
			Delete(data, root->m_right);
		int lheight = root->m_left ? root->m_left->Height() : 0;
		int rheight = root->m_right ? root->m_right->Height() : 0;
		int balance = lheight - rheight;

		// invalid, must re-balance
		if (abs(balance) > 1)
		{
			if (balance > 0)
				RotateLeft(root);
			else
				RotateRight(root);
		}
		else
			root->m_bf = BSTNode<T>::balfac(balance);
	}
}

/**********************************************************************
* Purpose:	delete node from tree
* Entry: 	BSTNode<T> * & node
* Exit:		Node delete from tree and tree rebalanced
************************************************************************/
template <typename T>
void AVLTree<T>::Delete(BSTNode<T> * & node)
{
	if (!node)
		throw Exception("ERROR: Node doesn't exist.");

	BSTNode<T>* temp = node;

	//no children
	if (!node->m_left && !node->m_right)
	{
		delete node;
		node = nullptr;
	}
	// has left child
	else if (!node->m_right)
	{
		node = node->m_left;
		delete temp;
	}
	// has right child
	else if (!node->m_left)
	{
		node = node->m_right;
		delete temp;
	}
	// has both children
	else
	{
		// bring left up.
		if (node->m_left->m_bf >= node->m_right->m_bf)
		{
			BSTNode<T> * child = node->m_left->m_right;
			node = node->m_left;
			node->m_right = temp->m_right;
			delete temp;

			temp = node->m_right;

			while (temp->m_left)
				temp = temp->m_left;

			temp->m_left = child;
		}
		//bring up right
		else
		{
			BSTNode<T> * child = node->m_right->m_left;
			node = node->m_right;
			node->m_left = temp->m_left;
			delete temp;

			temp = node->m_left;
			while (temp->m_right)
				temp = temp->m_right;

			temp->m_right = child;
		}
	}
}

#endif