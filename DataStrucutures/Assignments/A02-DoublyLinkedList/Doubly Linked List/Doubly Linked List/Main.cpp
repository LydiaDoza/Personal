#include <iostream>
#include "doublelinkedlist.h"

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

void TestAppend(DoubleLinkedList<int> & alist);
void TestFirstAndLast(const DoubleLinkedList<int> & alist);
void TestPrepend(DoubleLinkedList<int> & alist);
void TestPurge(DoubleLinkedList<int> alist);
void TestInsertBefore();
void TestInsertAfter();
void TestExtract();

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Tests Canonical Functions
	DoubleLinkedList<int> alist;			//ctor
	DoubleLinkedList<int> blist(alist);		//copy ctor
	DoubleLinkedList<int> clist;

	clist = blist;							//= operator

	// Tests Mutators
	std::cout << alist.getHead() << std::endl;
	std::cout << alist.getTail() << std::endl;

	// Tests Methods

	TestAppend(alist);
	TestFirstAndLast(alist);
	TestPrepend(alist);
	TestPurge(alist);
	TestInsertBefore();
	TestInsertAfter();
	TestExtract();

	std::cout << "\n********** List Integrity **********" << std::endl;
	alist.PrintForwards();
	alist.PrintBackwards();
}

void TestAppend(DoubleLinkedList<int> & alist)
{
	std::cout << "\n********** Append **********" << std::endl;

	alist.Append(5);
	alist.Append(15);
	alist.Append(25);
	alist.Append(35);
}

void TestFirstAndLast(const DoubleLinkedList<int> & alist)
{
	DoubleLinkedList<int> blist;

	std::cout << "\n********** First and Last **********" << std::endl;

	// Full List
	std::cout << alist.First() << std::endl;
	std::cout << alist.Last() << std::endl;

	// Empty List
	try
	{
		std::cout << blist.First() << std::endl;
	}
	catch (char * msg)
	{
		std::cout << msg << std::endl;
	}
	try
	{
		std::cout << blist.Last() << std::endl;
	}
	catch (char * msg)
	{
		std::cout << msg << std::endl;
	}
}

void TestPrepend(DoubleLinkedList<int> & alist)
{
	DoubleLinkedList<int> blist;

	std::cout << "\n********** Prepend **********" << std::endl;

	// Full List
	alist.Prepend(4);
	alist.Prepend(3);
	alist.Prepend(2);
	alist.Prepend(1);
	alist.Prepend(0);

	std::cout << alist.First() << std::endl;
	std::cout << alist.Last() << std::endl;

	// Empty List
	blist.Prepend(100);
	blist.Prepend(200);
	blist.Prepend(300);
	blist.Prepend(400);
	blist.Prepend(500);

	std::cout << blist.First() << std::endl;
	std::cout << blist.Last() << std::endl;
}

void TestPurge(DoubleLinkedList<int> alist)
{
	std::cout << "\n********** Purge **********" << std::endl;

	std::cout << alist.getHead() << std::endl;
	std::cout << alist.getTail() << std::endl;

	alist.Purge();

	std::cout << alist.getHead() << std::endl;
	std::cout << alist.getTail() << std::endl;
}

void TestInsertBefore()
{
	DoubleLinkedList<int> clist;

	std::cout << "\n********** InsertBefore **********" << std::endl;

	// Empty List
	try
	{
		clist.InsertBefore(-1, 0);
	}
	catch (char * msg)
	{
		std::cout << msg << std::endl;
	}
	// Head and Tail are the same
	clist.Append(0);
	clist.InsertBefore(-1, 0);

	std::cout << clist.First() << std::endl;
	std::cout << clist.Last() << std::endl;

	// Before Head
	clist.InsertBefore(-3, -1);

	std::cout << clist.First() << std::endl;
	std::cout << clist.Last() << std::endl;

	// Middle
	clist.InsertBefore(-2, -1);

	std::cout << clist.First() << std::endl;
	std::cout << clist.Last() << std::endl;

	// Node doesn't exist
	try
	{
		clist.InsertBefore(-2, 99);
	}
	catch (char * msg)
	{
		std::cout << msg << std::endl;
	}
}

void TestInsertAfter()
{
	DoubleLinkedList<int> clist;

	std::cout << "\n********** InsertAfter **********" << std::endl;

	try
	{
		clist.InsertAfter(-1, 0);
	}
	catch (char * msg)
	{
		std::cout << msg << std::endl;
	}
	// Head and Tail are the same
	clist.Append(0);
	clist.InsertAfter(1, 0);

	std::cout << clist.First() << std::endl;
	std::cout << clist.Last() << std::endl;

	// After Tail
	clist.InsertAfter(3, 1);

	std::cout << clist.First() << std::endl;
	std::cout << clist.Last() << std::endl;

	// Middle
	clist.InsertAfter(2, 1);

	std::cout << clist.First() << std::endl;
	std::cout << clist.Last() << std::endl;

	// Node doesn't exist
	try
	{
		clist.InsertAfter(-2, 99);
	}
	catch (char * msg)
	{
		std::cout << msg << std::endl;
	}
}

void TestExtract()
{
	DoubleLinkedList<int> alist;

	std::cout << "\n********** Extract **********" << std::endl;

	// Empty List
	try
	{
		alist.Extract(0);
	}
	catch (char * msg)
	{
		std::cout << msg << std::endl;
	}
	// Head and Tail are the same
	alist.Append(0);
	alist.Extract(0);

	try
	{
		std::cout << alist.First() << std::endl;
	}
	catch (char * msg)
	{
		std::cout << msg << std::endl;
	}

	try
	{
		std::cout << alist.Last() << std::endl;
	}
	catch (char * msg)
	{
		std::cout << msg << std::endl;
	}

	// Remove Head
	alist.Append(0);
	alist.Append(1);
	alist.Extract(0);

	std::cout << alist.First() << std::endl;
	std::cout << alist.Last() << std::endl;

	// Remove Tail
	alist.Prepend(0);
	alist.Extract(1);

	std::cout << alist.First() << std::endl;
	std::cout << alist.Last() << std::endl;
}