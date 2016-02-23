/***********************************************************
* Author:					Lydia Doza
* Date Created:				13/4/2015
* Last Modification Date:	27/4/2015
* Lab Number:				Lab 2
* Filename:					Sorts
*
* Overview:
*	This lab tests the different sorts shown below:
*		Bubble sort (brute force and flagged)
*		Selection Sort
*		Insertion Sort
*		Shell Sort
*		Heap Sort
*		Merge Sort
*		Quick Sort
*	The functions are in Sort.h.
*
* Input:
*	elms - number of total records to sort
*
* Output:
*	time it takes for each sort to complete it's sorting
*		routine next to sort name. This is written to the
*		screen and to the file. Each time it is run, the
*		data is appended to end of file.
*
************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#include <ctime>
#include <iomanip>
using std::left;
using std::right;
using std::fixed;
using std::setfill;
using std::flush;
using std::setw;

#include "Sort.h"
#include "Array.h"
#include "Exception.h"

#include <vector>
using std::vector;

#include <fstream>
using std::ofstream;

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(0));
	int temp(0);
	int elms(0); // n will be used as the total number of records to sort
	ofstream fout("SortResults.txt");

	int * unsorted = nullptr;
	int * ra = nullptr;

	if (argc != 2) {
		cout << "How many elements do you want to sort?";
		cin >> elms;
	}
	else
		elms = atoi(argv[1]);

	unsorted = new int[elms];
	ra = new int[elms];
	vector<int> vec(elms);
	Array<int> myra(elms);

	for (int i(0); i < elms; i++)
	{
		temp = rand() % 1000;
		ra[i] = temp;
		vec[i] = temp;
		myra[i] = temp;
		unsorted[i] = temp;
	}
	if (fout.is_open())
	{
		Sort(ra, vec, myra, unsorted, elms, fout);
	}

	fout.close();

	delete[] unsorted;
	delete[] ra;

	return 0;
}