/***********************************************************
* Author:					Lydia Doza
* Date Created:				10/5/2015
* Last Modification Date:	10/5/2015
* assignment Number:		extra credit
* Filename:					Tree Iterator
*
* Overview:
*	binary search tree iterator
************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;
using std::left;

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#include "BinarySearchTree.h"
#include "BreadthFirst.h"
#include "InOrderIterator.h"
#include "PreOrder.h"
#include "PostOrder.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	BinarySearchTree<int> b;

	b.Insert(20);
	b.Insert(12);
	b.Insert(25);
	b.Insert(11);
	b.Insert(18);
	b.Insert(22);

	InOrderIterator<int> inOrd(b);
	PreOrder<int> preOrd(b);
	PostOrder<int> postOrd(b);
	BreadthFirst<int> breadth(b);


	cout << setw(12) << left << "In order:";
	for (inOrd.Reset(); !inOrd.IsDone(); inOrd.MoveNext())
		cout << setw(3) << inOrd.GetCurrent();

	cout << "\n\n" << setw(12) << left << "pre order:";
	for (preOrd.Reset(); !preOrd.IsDone(); preOrd.MoveNext())
		cout << setw(3) << preOrd.GetCurrent();

	cout << "\n\n" << setw(12) << left << "post order:";
	for (postOrd.Reset(); !postOrd.IsDone(); postOrd.MoveNext())
		cout << setw(3) << postOrd.GetCurrent();

	cout << "\n\n" << setw(12) << left << "Breadth:";
	for (breadth.Reset(); !breadth.IsDone(); breadth.MoveNext())
		cout << setw(3) << breadth.GetCurrent();

	cout << endl << endl;

	return 0;
}