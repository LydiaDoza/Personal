/***********************************************************
* Author:					Lydia Doza
* Date Created:				4/1/2015
* Last Modification Date:	4/4/2015
* Lab Number:				Assignment tow, 2d array with
*								arrays
* Filename:					A03 Lydia Doza
*
* Overview:
*	This program is used to test the ins and outs of the
*	Array2D class. It checks to make sure that the necessary
*	exceptions are thrown and caught.
************************************************************/
#include "Array2D.h"
#include "Exception.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int num = 1;

	Array2D<int> arrayA(3, 4);		// 2 arg ctor
	Array2D<int>  arrayB(arrayA);	// no arg ctor
	Array2D<int> arrayC(2);			// copy ctor
	Array2D<string> arrayD(1);		// 1 arg ctor string
	Array2D<int> arrayE(1, 1);		// used for const casting

	arrayC = arrayB;				// op equals

	// fill the array with stuff
	for (int iRow = 0; iRow < 3; iRow++)
	{
		for (int iCol = 0; iCol < 4; iCol++)
		{
			arrayA[iRow][iCol] = iCol + iRow;
		}
	}

	/************************************************************************/
	/*						Test constant stuff                             */
	/************************************************************************/
	arrayE = arrayA;
	const_cast<Array2D<int> &>(arrayE);
	cout << "Print const stuff: arrayE" << endl;
	for (int iRow = 0; iRow < 3; iRow++)
	{
		for (int iCol = 0; iCol < 4; iCol++)
		{
			cout << arrayE[iRow][iCol] << " ";
		}
		cout << endl;
	}

	/************************************************************************/
	/*						Test stuff out of scope                         */
	/************************************************************************/
	cout << "\nTry to access an element out of scope: " << endl;
	try
	{
		cout << arrayA[5][1];
	}
	catch (Exception e)
	{
		cout << "arrayA: " << e << endl;
	}

	cout << "Try to access an element out of scope: " << endl;
	try
	{
		cout << arrayA[0][-2];
	}
	catch (Exception e)
	{
		cout << "arrayA: " << e;
	}

	/************************************************************************/
	/*						Op Equals with diff size                        */
	/************************************************************************/

	cout << "\n\n******  Set arrayB equal to arrayA  ******\n";
	
	arrayB = arrayA;	//a assignment

	for (int iRow = 0; iRow < 3; iRow++)
	{
		for (int iCol = 0; iCol < 4; iCol++)
		{
			cout << arrayB[iRow][iCol] << "\t";
		}
		cout << endl;
	}



	/************************************************************************/
	/*						Set new rows/cols to negative                   */
	/************************************************************************/
	cout << "\n\n*** Try setting rows to negative in arrayA ***\n";
	try
	{
		arrayA.setRow(-2);
	}
	catch (Exception e)
	{
		cout << '\n' << e;
	}

	cout << "\n\n*** Try setting cols to negative in arrayA ***\n";
	try
	{
		arrayA.setColumn(-8);
	}
	catch (Exception e)
	{
		cout << '\n' << e;
	}

	/************************************************************************/
	/*						Set rows/cols to smaller                        */
	/************************************************************************/
	cout << "\n\nGet arrayA row: " << arrayA.getRow()
		<< "\nGet arrayA col: " << arrayA.getColumn() << endl;

	cout << "\n\n**********  Set arrayA rows to 2  **********\n";
	arrayA.setRow(2);

	for (int iRow = 0; iRow < 2; iRow++)
	{
		for (int iCol = 0; iCol < 4; iCol++)
		{
			cout << arrayA[iRow][iCol] << "\t";
		}
		cout << endl;
	}

	cout << "\n\n**********  Set arrayA cols to 3  **********\n";
	arrayA.setColumn(3);

	for (int iRow = 0; iRow < 2; iRow++)
	{
		for (int iCol = 0; iCol < 3; iCol++)
		{
			cout << arrayA[iRow][iCol] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	/************************************************************************/
	/*						Set rows/cols to larger                         */
	/************************************************************************/
	// row = 1, col = 0
	cout << "\n\nGet arrayD row: " << arrayD.getRow()
		<< "\nGet arrayD col: " << arrayD.getColumn() << endl;
	
	cout << "\n\n**********  Set arrayD cols to 4  **********\n";
	arrayD.setColumn(4);
	string a = "stuff";

	for (int iRow = 0; iRow < 1; iRow++)
	{
		for (int iCol = 0; iCol < 4; iCol++)
		{
			try
			{
				arrayD[iRow][iCol] = a;
				cout << arrayD[iRow][iCol] << "\t";
			}
			catch (Exception e)
			{
				cout << "\n" << e;
			}
		}
		cout << endl;
	}
	cout << endl;

	cout << "\n\n**********  Set arrayD rows to 3  **********\n";
	try
	{
		arrayD.setRow(3);
	}
	catch (Exception e)
	{
		cout << "\n" << e;
	}

	for (int iRow = 0; iRow < 3; iRow++)
	{
		for (int iCol = 0; iCol < 4; iCol++)
		{
			try
			{
				arrayD[iRow][iCol] = a;
				cout << arrayD[iRow][iCol] << "\t";
			}
			catch (Exception e)
			{
				cout << "\n" << e;
			}

		}
		cout << endl;
	}

	return 0;
}