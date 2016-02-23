/***********************************************************
* Author:					Lydia Doza
* Date Created:				21/5/2015
* Last Modification Date:	4/6/2015
* Lab Number:				
* Filename:					AVLTree
*
* Overview:
*	Wow. Such AVL tree. Much testing.
*
* Input:
*	hard coded data (same as power point)
*
* Output:
*	traverse stuff.
************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#include "AVLTree.h"
#include <string>
using std::string;

template <typename T>
void DisplayNode(BSTNode<T>*);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	AVLTree<int> tree;
	// Insert numbers into tree like in the slides
	tree.Insert(8);
	tree.Insert(9);
	tree.Insert(10);
	tree.Insert(2);
	tree.Insert(1);
	tree.Insert(5);
	tree.Insert(2); // insert something that already exists
	tree.Insert(3);
	tree.Insert(6);
	tree.Insert(4);
	tree.Insert(7);
	tree.Insert(11);

	tree.TravInOrder(&DisplayNode);
	cout << endl << endl;
	tree.TravBreadth(DisplayNode);
	cout << endl << endl;
	tree.TravPostOrder(DisplayNode);
	cout << endl << endl;
	tree.TravPreOrder(DisplayNode);
	cout << endl << endl;

	tree.Delete(8);

	tree.TravInOrder(&DisplayNode);
	cout << endl << endl;
	tree.TravBreadth(DisplayNode);
	cout << endl << endl;

	return 0;
}

/**********************************************************************
* Purpose:	Prints data in node.
* Entry: 	BSTNode<T>*
* Exit:		all nodes in tree are displayed
************************************************************************/
template <typename T>
void DisplayNode(BSTNode<T>* node)
{
	T data = node->GetData();
	cout << data << " ";
}
