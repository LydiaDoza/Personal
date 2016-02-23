/***********************************************************
* Author:					Lydia Doza
* Date Created:				28/4/2015
* Last Modification Date:	28/4/2015
* Assignment:				7
* Filename:					QueueArray
*
* Overview:
*	This tests the circular array based queue.
************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#include "Queue.h"
#include "Exception.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Queue<int> q(10);
	
	cout << "Circular Queue using Array\n" << endl;

	cout << "Before adding anything, there are\n" 
		<< q.Size() << " items in Queue" << endl;

	for (int i(0); i < 10; i++)
	{
		q.Enqueue(i + 4 / 2);
		cout << "\nAdded " << (i + 4) / 2;
	}

	cout << "\n\nFull Queue has: " << q.Size() << " items." << endl;

	try
	{
		q.Enqueue(40);
	}
	catch (Exception e)
	{
		cout << '\n' << e;
	}

	for (int i(0); i < 4; i++)
		q.Dequeue();


	cout << "\nAfter removing 4 items: " << q.Size() << " items." << endl;

	cout << "\nChange front " << q.Front() << " to 53" << endl;
 
	q.Front() = 53;

	cout << "Front is now " << q.Front() << endl;

	try
	{
		for (int i(0); i < 20; i++)
			q.Dequeue();
	}
	catch (Exception e)
	{
		cout << '\n' <<  e;
	}

	cout << "\nsize is " << q.Size() << endl;

	cout << "\n\nAdd a bunch of stuff, remove stuff to"
		<< "\n make sure that the head and tail get moved"
		<< "\n throughoutt the array." << endl;

	for (int i(0); i < 5; i++)
	{
		q.Enqueue(i + 4 / 2);
		cout << "\nEnqueue";
	}

	cout << "\n\nsize is " << q.Size() << endl;

	for (int i(0); i < 4; i++)
	{
		q.Dequeue();
		cout << "\nDequeue";
	}
	
	cout << "\n\nsize is " << q.Size() << endl;

	for (int i(0); i < 5; i++)
	{
		q.Enqueue(i + 4 / 2);
		cout << "\nEnqueue";
	}

	cout << "\n\nsize is " << q.Size() << endl;

	for (int i(0); i < 4; i++)
	{
		q.Dequeue();
		cout << "\nDequeue";
	}

	cout << "\n\nsize is " << q.Size() << endl << endl;

	return 0;
}