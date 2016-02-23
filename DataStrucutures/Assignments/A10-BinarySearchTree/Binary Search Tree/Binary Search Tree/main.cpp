/***********************************************************
* Author:					Lydia Doza
* Date Created:				9/5/2015
* Last Modification Date:	9/5/2015
* Assignment Number:		10
* Filename:					Binary Search Tree
*
* Overview:
*	Tests Binary Search Tree
************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#include "BinarySearchTree.h"
#include "BSTNode.h"

template <typename T>
void Visit(BSTNode<T>*);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	BinarySearchTree<int> b;
	BinarySearchTree<int> c;

	b.Insert(20);
	b.Insert(12);
	b.Insert(25);
	b.Insert(11);
	b.Insert(18);
	b.Insert(22);

	cout << "Displaying b:" << "\nIn order:" << endl;
	b.TravInOrder(&Visit);

	cout << "\n\nPost Order:" << endl;
	b.TravPostOrder(&Visit);

	cout << "\n\nPre Order:" << endl;
	b.TravPreOrder(&Visit);

	cout << "\n\nBreadth First:" << endl;
	b.TravBreadth(&Visit);

	c.InsertRecurs(20);
	c.InsertRecurs(12);
	c.InsertRecurs(25);
	c.InsertRecurs(11);
	c.InsertRecurs(18);
	c.InsertRecurs(22);

	BinarySearchTree<int> d(c);

	cout << "\n\ncopy ctor d(c):" << endl;
	d.TravInOrder(&Visit);

	cout << "\nheight of c:" << c.Height() << endl;

	cout << "\ndelete 11, 12, 22 from c:" << endl;
	c.FindNodeAndDelete(11);
	c.FindNodeAndDelete(12);
	c.FindNodeAndDelete(22);
	c.TravInOrder(&Visit);

	cout << "\nheight of c:" << c.Height() << endl;

	cout << "\ndelete something that isn't in list" << endl;
	try
	{
		c.FindNodeAndDelete(55);
	}
	catch (Exception e)
	{
		cout << "\n" << e << endl;
	}

	cout << "\nd = c" << endl;
	d = c;

	cout << "\nTraverse d in order" << endl;
	d.TravInOrder(&Visit);

	cout << "\nTraverse c in order" << endl;
	c.TravInOrder(&Visit);

	cout << "\npurge b" << endl;
	b.Purge();
	b.TravInOrder(&Visit);

	return 0;
}

/**********************************************************************
* Purpose:	Prints all of tree in order
* Entry: 	BSTNode<T>*
* Exit:		all nodes in tree are displayed
************************************************************************/
template <typename T>
void Visit(BSTNode<T>* node)
{
	cout << node->GetData() << " ";
}

