/***********************************************************
* Author:					Lydia Doza
* Date Created:				3/30/2015
* Last Modification Date:	3/31/2015
* Lab Number:				Assignment one, 1d array
* Filename:					A01 Lydia Doza
*
* Overview:
*	This program is used to create and test various 1 
*	dimension arrays of any data type, and to throw
*	exceptions 
************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "Array.h"
#include "Exception.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Array<int> integers;
	Array<char *> characters(20);
	Array<double> doubles(10, 25);
	Array<double> doubles2(doubles);
	Array<string> mystring(14, 40);

	/*******************************
	*	test integers
	*******************************/
	cout << "integers:\n\tLength: "
		<< integers.GetLength() << "\n\tStart Index: "
		<< integers.GetStartIndex() << endl;

	cout << "\n***********************\n"
		<< "Changing integers"
		<< "\n***********************\n";

	integers.SetStartIndex(1990);

	try
	{
		integers.SetLength(32);
	}
	catch (Exception e)
	{
		cout << "\nIntegers:" << e;
	}

	cout << "integers:\n\tLength: "
		<< integers.GetLength() << "\n\tStart Index: "
		<< integers.GetStartIndex() << endl;

	try
	{
		cout << integers[5000];
	}
	catch (Exception e)
	{
		cout << "\nIntegers:" << e;
	}

	/*******************************
	*	test characters
	*******************************/
	characters.SetStartIndex(10);
	try
	{
		characters.SetLength(-3);
	}
	catch (Exception e)
	{
		cout << "\nCharacters: " << e;
	}

	/*******************************
	*	test doubles
	*******************************/
	for (int i = 0; i < doubles.GetLength(); i++)
	{
		doubles[i + doubles.GetStartIndex()] = i * 0.3;
	}

	cout << "\ndoubles data\n";
	for (int i = 0; i < doubles.GetLength(); i++)
	{
		cout << doubles[i + doubles.GetStartIndex()] << endl;
	}

	try
	{
		cout << doubles[-3];
	}
	catch (Exception e)
	{
		cout << "\nDoubles: " << e;
	}

	/*******************************
	*	test doubles2
	*******************************/
	cout << "\nDoubles: \n\tLength: "
		<< doubles.GetLength() << "\n\tStart Index: "
		<< doubles.GetStartIndex() << endl;
	cout << "\nDoubles2: \n\tLength: "
		<< doubles2.GetLength() << "\n\tStart Index: "
		<< doubles2.GetStartIndex() << endl;

	cout << "\n**************************\n"
		<< "Changing doubles2."
		<< "\n*************************" << endl;

	try
	{
		doubles2.SetLength(50);
	}
	catch (Exception e)
	{
		cout << "\nDoubles2 Length: " << e;
	}

	try
	{
		doubles2.SetStartIndex(30);
	}
	catch (Exception e)
	{
		cout << "Doubles2 StartIndex: " << e;
	}

	cout << "\nDoubles2: \n\tLength: "
		<< doubles2.GetLength() << " \n\tStart Index: "
		<< doubles2.GetStartIndex() << endl;

	cout << "\nSetting Doubles to Doubles2\n";
	doubles = doubles2;
	cout << "\nDoubles after change: \n\tLength: "
		<< doubles.GetLength() << "\n\tStart Index: "
		<< doubles.GetStartIndex() << endl;

	/*******************************
	*	test mystring
	*******************************/
	cout << "\nmystring:\n\tLength: "
		<< mystring.GetLength() << "\n\tStart Index"
		<< mystring.GetStartIndex() << endl;

	cout << "\n*************************\n"
		<< "Changing mystring"
		<< "\n*************************\n";

	mystring.SetStartIndex(100);

	try
	{
		mystring.SetLength(20);
	}
	catch (Exception e)
	{
		cout << "\nmystring" << e;
	}

	try
	{
		mystring.SetLength(10);
	}
	catch (Exception e)
	{
		cout << "\nmystring" << e;
	}

	cout << "\nmystring:\n\tLength: "
		<< mystring.GetLength() << "\n\tStart Index"
		<< mystring.GetStartIndex() << endl;

	return 0;
}