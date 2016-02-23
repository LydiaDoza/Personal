/***********************************************************
* Author:					Lydia Doza
* Date Created:				29/4/2015
* Last Modification Date:	29/4/2015
* Assignment:				9
* Filename:					Iterator
*
* Overview:
*	Tests the iterator classes.
************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#include "doublelinkedlist.h"
#include "ForwardIterator.h"
#include "BackwardsIterator.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	DoubleLinkedList<int> alist;

	alist.Append(5);
	alist.Prepend(4);
	alist.Append(15);
	alist.Prepend(2);
	alist.Prepend(3);
	alist.Append(25);
	alist.Prepend(1);
	alist.Append(35);
	alist.Prepend(0);

	ForwardIterator<int> forward(alist);
	BackwardsIterator<int> backward(alist);

	cout << "Forward Iterator:" << endl;
	for (forward.Reset(); !forward.IsDone(); forward.MoveNext())
		cout << forward.GetCurrent() << endl;


	cout << "\nBackward Iterator:" << endl;
	for (backward.Reset(); !backward.IsDone(); backward.MoveNext())
		cout << backward.GetCurrent() << endl;

	return 0;
}