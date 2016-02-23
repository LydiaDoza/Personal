/***********************************************************
* Author:					Lydia Doza
* Date Created:				31/5/2015
* Last Modification Date:	1/6/2015
* Lab Number:				6
* Filename:					HashTable
*
* Overview:
*	This tests the Hash Table. Wow. Much Data STructs.
*	So testing.
*
* Input:
*	Tests my Hash Table using hard coded input testing 
*	every function in hash table class
*
* Output:
*	Every function is tested and the results are printed
*	to the console window
************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#include <string>
using std::string;

#include "HashTable.h"
#include "Exception.h"

struct Book
{
	Book(string title, string author, int pages) :
		m_title(title), m_author(author), m_pages(pages) {}

	Book() {}

	string m_title;
	string m_author;
	int m_pages;
};

int AsciiHash(string ISBN);
int XORHash(string ISBN);
void DispBook(const Book & b);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	HashTable<string, Book> table(10);
	HashTable<string, Book> table2(table);
	HashTable<string, Book> table3(1);

	table3 = table2;

	table.SetHash(AsciiHash);

	Book temp = { "C++: An Active Learning Approach", "Randal Albert", 635 };
	Book temp1 = { "Rodeo for Dummies", "Calvin Caldwell", 1 };
	Book temp3 = { "And That n There", "Ralph Carestia", 1 };

	table.Insert("0763757233", temp);
	table.Insert("7063757233", temp1);
	table.Insert("7063757234", temp3);
	table.Insert("0001", Book("title", "author", 1)); //insert
	table.Insert("0082", Book("title2", "author2", 2));
	table.Insert("0003", Book("title3", "author3", 3));
	table.Insert("0934", Book("title4", "author4", 4));
	table.Insert("0005", Book("title5", "author5", 5));
	table.Insert("0006", Book("title6", "author6", 6));
	table.Insert("0307", Book("title7", "author7", 7));
	table.Insert("0008", Book("title8", "author8", 8));

	try // same ISBN 
	{
		table.Insert("0008", Book("title9", "author9", 9));
	}
	catch (Exception e)
	{
		cout << "\n\n" << e << endl;
	}

	cout << table["0763757233"].m_title << endl;
	cout << table["7063757233"].m_title << endl;
	cout << table["7063757234"].m_title << endl;

	table.Traverse(DispBook);

	cout << "\n\n\nSetHash\n\n" << endl;

	table.SetHash(XORHash);
	table.Traverse(DispBook);
	
	table.Delete("0001");

	try // delete a thing not in table
	{
		table.Delete("0001");
	}
	catch (Exception e)
	{
		cout << "\n\n" << e << endl;
	}

	try // negative size
	{
		table.SetSize(-12312);
	}
	catch (Exception e)
	{
		cout << "\n\n" << e << endl;
	}

	table.SetSize(5);

	cout << "\n\n\nSet Size to 5 \n\n\n\n" << endl;
	table.Traverse(DispBook);

	
	return 0;
}

/**********************************************************************
* Purpose:	Returns int
* Entry: 	string ISBN
* Exit:		int
************************************************************************/
int AsciiHash(string ISBN)
{
	int num(0), size(ISBN.length());
	for (int i(0); i < size; i++)
		num += ISBN[i];

	return num;
}

/**********************************************************************
* Purpose:	Returns int
* Entry: 	string ISBN
* Exit:		int
************************************************************************/
int XORHash(string ISBN)
{
	int num(0), size(ISBN.length());

	for (int i(0); i < size; i++)
		num ^= ISBN[i];

	return num;
}

/**********************************************************************
* Purpose:	displays book
* Entry: 	const Book & b
* Exit:		void
************************************************************************/
void DispBook(const Book & b)
{
	cout << "\nTitle: " << b.m_title
		<< "\n\tAuthor: " << b.m_author
		<< "\n\tPages: " << b.m_pages << endl;
}

