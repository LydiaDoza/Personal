/***********************************************************
* Author:					Lydia Doza
* Date Created:				1/5/2015
* Last Modification Date:	1/6/2015
* Lab Number:				Assignment 6
* Filename:					StackArray
*
* Overview:
*	Tests Doubly Linked List based Stack
************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#include "Stack.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Stack<int> stack;
	Stack<int> otherStack;
	Stack<int> aStack(otherStack);

	stack.Push(5);
	stack.Push(6);
	stack.Push(2);
	stack.Push(5);
	stack.Push(9);

	cout << "size: " << stack.Size() << endl;

	otherStack = stack;

	cout << "Top: " << otherStack.Pop() << endl;
	cout << "Top: " << otherStack.Pop() << endl;
	cout << "Top: " << otherStack.Pop() << endl;

	cout << "stack size: " << stack.Size() << endl;
	cout << "otherStack size: " << otherStack.Size() << endl;

	try
	{
		aStack.Pop();
	}
	catch (Exception e)
	{
		cout << '\n' << e << endl;
	}

	stack.Push(53);
	stack.Push(62);
	stack.Push(21);
	stack.Push(56);
	stack.Push(98);

	try
	{
		stack.Push(100);
	}
	catch (Exception e)
	{
		cout << '\n' << e << endl;
	}

	return 0;
}