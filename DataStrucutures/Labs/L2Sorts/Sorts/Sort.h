#ifndef SORTS_H
#define SORTS_H

#include <ctime>
using std::clock_t;

#include <vector>
using std::vector;

#include "Array.h"
#include "Exception.h"

#include <fstream>
using std::ofstream;

void PrintTime(clock_t time, ofstream & fout);
void SortRas(int *& ra, int * unsorted, int elms, ofstream &fout);
void SortVecs(vector<int> & vec, int * unsorted, int elms, ofstream &fout);
void SortMyRas(Array<int> & myra, int * unsorted, int elms, ofstream &fout);
void Sort(int * &ra, vector<int> &vec, Array<int> &myra, int * unsorted, int elms, ofstream &fout);

template <typename T>
void BruteBubble(T &m_array, int n);
template <typename T>
void FlagBubble(T &m_array, int n);
template <typename T>
void Selection(T &m_array, int n);
template <typename T>
void Insertion(T &m_array, int n);
template <typename T>
void Shell(T &m_array, int n);
template <typename T>
void Heap(T &m_array, int n);
template <typename T>
void HeapDown(T &m_array, int first, int last);

template <typename T>
void MergeSort(T &m_array, int n);
template <typename T>
void MergeSort(T& m_array, int * temp, int left, int right);
template <typename T>
void Merge(T &m_array, int * temp, int left, int right, int end_right);

template <typename T>
void Quick(T &m_array, int n);
template <typename T>
void Quick(T &m_array, int first, int last);

void Swap(int & first, int & second);

template <typename T>
void Reset(T &m_array, int * unsorted, int elms);

/**************************************************************
*	Purpose:	brute force bubble sort can be applied to
*				3 different container.
*
*	Entry:		m_array by reference and n number of elements
*
*	Exit:		array/vector/myarray is sorted.
****************************************************************/
template <typename T>
void BruteBubble(T &m_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (n - i - 1); j++)
		{
			if (m_array[j] > m_array[j + 1])
			{
				int temp = m_array[j];
				m_array[j] = m_array[j + 1];
				m_array[j + 1] = temp;
			}
		}
	}
}

/**************************************************************
*	Purpose:	Flagged bubble sort can be applied to
*				3 different container.
*
*	Entry:		m_array by reference and n number of elements
*
*	Exit:		array/vector/myarray is sorted.
****************************************************************/
template <typename T>
void FlagBubble(T &m_array, int n)
{
	bool sorted = false;
	for (int i = 0; i < n, sorted == false; i++)
	{
		sorted = true;
		for (int j = 0; j < (n - i - 1); j++)
		{
			if (m_array[j] > m_array[j + 1])
			{
				sorted = false;
				int temp = m_array[j];
				m_array[j] = m_array[j + 1];
				m_array[j + 1] = temp;
			}
		}
	}
}

/**********************************************************************
* Purpose:	Use straight selection
*
* Entry:	T &m_array, int n
*
* Exit:		m_array is sorted
************************************************************************/
template <typename T>
void Selection(T &m_array, int n)
{
	int max = 0;

	for (int i = 0; i < n; i++, max = 0)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (m_array[max] < m_array[j])
			{
				max = j;
			}
		}
		Swap(m_array[max], m_array[(n - 1) - i]);
	}
}

/**********************************************************************
* Purpose:	Uses insertion sort algorithm to sort ints
*
* Entry:	T &m_array, int n
*
* Exit:		ints sorted from smalled to largest
************************************************************************/
template <typename T>
void Insertion(T &m_array, int n)
{
	int temp = 0;

	// m_array[0] is already sorted
	for (int i = 1; i < n; i++)
	{
		temp = m_array[i];
		int j = i;
		// j moves with i because array at i and before are sorted
		// only decrement j while temp < m_array[j - 1]
		for (; j > 0 && temp < m_array[j - 1]; j--)
		{
			m_array[j] = m_array[j - 1];
		}
		// j is changed to where temp >= m_array[j - 1]
		m_array[j] = temp;
	}
}

/**********************************************************************
* Purpose:	Uses Shell Sort algorithm to sort an array of ints
*
* Entry:	T &m_array, int n
*
* Exit:		m_array is sorted from smallest to largest
************************************************************************/
template <typename T>
void Shell(T &m_array, int n)
{
	// http://en.wikipedia.org/wiki/Shellsort#Gap_sequences
	// Tokuda sequence as described in last line of section
	// h = ceiling(2.25h + 1)

	// index of seq to represent subarrays
	// shell_val takes val in seq
	int seq[26];
	int i = 0;
	int gap = 1;

	for (i = 0, gap = 1; gap < n; i++)
	{
		seq[i] = gap;
		gap = ceil(2.25 * gap + 1);
	}

	//after this loop, i is one bigger than what we are interested in

	for (i--; i >= 0; i--)
	{
		gap = seq[i];
		for (int gapcnt = gap; gapcnt < 2 * gap; gapcnt++)
		{
			int j = gapcnt;
			for (j; j < n;)
			{
				int temp = m_array[j];
				int insert = j;

				while (insert - gap >= 0 && temp < m_array[insert - gap])
				{
					m_array[insert] = m_array[insert - gap];

					insert -= gap;
				}
				m_array[insert] = temp;
				j += gap;
			}
		}

	} // decrement i until seq[i] is less than n
}

/**********************************************************************
* Purpose:	Use the heap algorithm to sort an array of INTS
*
* Entry:	T &m_array, int n
*
* Exit:		array of ints is sorted
************************************************************************/
template <typename T>
void Heap(T &m_array, int n)
{
	int last = n - 1;
	int first = n / 2 - 1;

	// Create our heap
	for (first; first >= 0; first--)
	{
		HeapDown(m_array, first, last);
	}

	// Now do sort things
	for (last; last >= 1; last--)
	{
		Swap(m_array[0], m_array[last]);
		// move the largest to the last
		HeapDown(m_array, 0, last - 1);
	}
}

/**********************************************************************
* Purpose:	Used by HeapSort to make heap
*
* Entry:	T &m_array, int first, int last
*
* Exit:		array is now a proper heap
************************************************************************/
template <typename T>
void HeapDown(T &m_array, int first, int last)
{
	int largest = first * 2 + 1;

	while (largest <= last)
	{
		if (largest < last && m_array[largest] < m_array[largest + 1])
			++largest;

		if (m_array[largest] > m_array[first])
		{
			Swap(m_array[largest], m_array[first]);
			first = largest;
			largest = first * 2 + 1;
		}
		else
			largest = last + 1; // to exit loop
	}
}

/**********************************************************************
* Purpose:	2 arg mergesort. Creates a temp array of ints to store
*			sorted elements copied from m_array
*
* Entry:	T &m_array, int elms
*
* Exit:		m_array is sorted from smallest to largest
************************************************************************/
template <typename T>
void MergeSort(T &m_array, int elms)
{
	int * temp = new int[elms];

	for (int i = 0; i < elms; i++)
		temp[i] = m_array[i];

	MergeSort(m_array, temp, 0, elms - 1);

	delete temp;
}

/**********************************************************************
* Purpose:	4 parameter mergesort to sort left to right-1, right to end
*
* Entry:	T &m_array, T &temp, int left, int right
*
* Exit:		recursion until one element, then slowly sorts double
*			the number of elements until whole m_array is sorted.
************************************************************************/
template <typename T>
void MergeSort(T& m_array, int * temp, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		MergeSort(m_array, temp, left, mid);
		MergeSort(m_array, temp, mid + 1, right);
		Merge(m_array, temp, left, mid + 1, right);
	}
}

/**********************************************************************
* Purpose:	used by mergesort to merge two arrays
*
* Entry:	T &m_array, T &temp, int left, int mid, int right
*
* Exit:		m_array is set to temp from left to end_right
************************************************************************/
template <typename T>
void Merge(T &m_array, int * temp, int left, int right, int end_right)
{
	int orig_left = left;	// to keep track of where in the m_array we copy temp
	int end_left = right - 1;
	int travel = left;
	int num_elms = end_right - left + 1; // + 1 because we want the number of
	// elements, not the index

	while (left <= end_left && right <= end_right)
	{
		if (m_array[left] <= m_array[right])
		{
			temp[travel] = m_array[left];
			++left;
			++travel;
		}
		else
		{
			temp[travel] = m_array[right];
			++right;
			++travel;
		}
	}

	for (; left <= end_left; travel++, left++)
	{
		temp[travel] = m_array[left];
	}

	for (; right <= end_right; travel++, right++)
	{
		temp[travel] = m_array[right];
	}

	for (int i = orig_left; i <= end_right; i++)
		m_array[i] = temp[i];
}

/**********************************************************************
* Purpose:	uses quicksort algorithm to sort m_array
*
* Entry:	T &m_array, int elms
*
* Exit:		m_array is sorted
************************************************************************/
template<typename T>
void Quick(T &m_array, int elms)
{
	int max = 0;

	if (elms >= 2) // we have more than 1 element
	{
		for (int i = 1; i < elms; i++)
		{
			// move max to end
			if (m_array[max] < m_array[i])
				max = i;
		}
		Swap(m_array[max], m_array[elms - 1]);
		Quick(m_array, 0, elms - 2); // pass in position before last element
		// in array
	}
}

/**********************************************************************
* Purpose:	Implements quicksort algorithm to sort elements in array
*
* Entry:	T &m_array, int first, int last
*
* Exit:		elements of passed in sort are sorted
************************************************************************/
template<typename T>
void Quick(T &m_array, int first, int last)
{
	int pivot = m_array[first];
	int small = first + 1;
	int large = last;

	while (small <= large)
	{
		while (m_array[small] < pivot)
			small++;

		while (m_array[large] > pivot)
			large--;

		if (small < large)
			Swap(m_array[small++], m_array[large--]);
		else
			small++;
	}

	Swap(m_array[first], m_array[large]);

	if (first < large - 1)
		Quick(m_array, first, large - 1);

	if (last > large + 1)
		Quick(m_array, large + 1, last);
}

/**********************************************************************
* Purpose:	Swaps two values
*
* Entry:	int &first, int &second
*
* Exit:		first is now second, second is now first
************************************************************************/
void Swap(int &first, int &second)
{
	int temp = first;
	first = second;
	second = temp;
}

/**********************************************************************
* Purpose:	resets the array to unsorted state
*
* Entry:	T &m_array, int * unsorted
*
* Exit:		array/vector/Array is again unsorted
************************************************************************/
template <typename T>
void Reset(T &m_array, int * unsorted, int elms)
{
	for (int i = 0; i < elms; i++)
		m_array[i] = unsorted[i];
}

/**********************************************************************
* Purpose:	Calls sorts for the arrays
*
* Entry:	int * ra, vector<int> vec, int * unsorted, int elms
*
* Exit:		ra is sorted, vector is sorted, myra is sorted, all timed
************************************************************************/
void Sort(int *& ra, vector<int> &vec, Array<int> &myra, int * unsorted, int elms, ofstream &fout)
{
	SortRas(ra, unsorted, elms, fout);
	SortVecs(vec, unsorted, elms, fout);
	SortMyRas(myra, unsorted, elms, fout);
}

/**********************************************************************
* Purpose:	Calls all sorts passing in the native array
*
* Entry:	int * ra, int * unsorted, int elms
*
* Exit:		native array is sorted.
************************************************************************/
void SortRas(int * &ra, int * unsorted, int elms, ofstream &fout)
{
	clock_t startTime, endTime;

	cout << "Native Array Results\n";
	fout << "Native Array Results\n";

	cout << '\n' << "BruteBubble: ";
	fout << '\n' << "BruteBubble: ";
	startTime = clock();
	BruteBubble(ra, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(ra, unsorted, elms);

	cout << '\n' << "FlagBubble: ";
	fout << '\n' << "FlagBubble: ";
	startTime = clock();
	FlagBubble(ra, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(ra, unsorted, elms);

	cout << '\n' << "Selection: ";
	fout << '\n' << "Selection: ";
	startTime = clock();
	Selection(ra, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(ra, unsorted, elms);

	cout << '\n' << "Insertion: ";
	fout << '\n' << "Insertion: ";
	startTime = clock();
	Insertion(ra, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(ra, unsorted, elms);

	cout << '\n' << "Shell: ";
	fout << '\n' << "Shell: ";
	startTime = clock();
	Shell(ra, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(ra, unsorted, elms);

	cout << '\n' << "Heap: ";
	fout << '\n' << "Heap: ";
	startTime = clock();
	Heap(ra, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(ra, unsorted, elms);

	cout << '\n' << "MergeSort: ";
	fout << '\n' << "MergeSort: ";
	startTime = clock();
	MergeSort(ra, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(ra, unsorted, elms);

	cout << '\n' << "Quick: ";
	fout << '\n' << "Quick: ";
	startTime = clock();
	Quick(ra, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(ra, unsorted, elms);
}


/**********************************************************************
* Purpose:	each sort is called on vector
*
* Entry:	vector<int> vec, int * unsorted, int elms
*
* Exit:		time results are printed to file and to screen.
************************************************************************/
void SortVecs(vector<int> &vec, int * unsorted, int elms, ofstream& fout)
{
	clock_t startTime, endTime;

	cout << "\n\nVector Results\n";
	fout << "\n\nVector Results\n";

	cout << '\n' << "BruteBubble: ";
	fout << '\n' << "BruteBubble: ";
	startTime = clock();
	BruteBubble(vec, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(vec, unsorted, elms);

	cout << '\n' << "FlagBubble: ";
	fout << '\n' << "FlagBubble: ";
	startTime = clock();
	FlagBubble(vec, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(vec, unsorted, elms);

	cout << '\n' << "Selection: ";
	fout << '\n' << "Selection: ";
	startTime = clock();
	Selection(vec, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(vec, unsorted, elms);

	cout << '\n' << "Insertion: ";
	fout << '\n' << "Insertion: ";
	startTime = clock();
	Insertion(vec, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(vec, unsorted, elms);

	cout << '\n' << "Shell: ";
	fout << '\n' << "Shell: ";
	startTime = clock();
	Shell(vec, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(vec, unsorted, elms);

	cout << '\n' << "Heap: ";
	fout << '\n' << "Heap: ";
	startTime = clock();
	Heap(vec, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(vec, unsorted, elms);

	cout << '\n' << "MergeSort: ";
	fout << '\n' << "MergeSort: ";
	startTime = clock();
	MergeSort(vec, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(vec, unsorted, elms);

	cout << '\n' << "Quick: ";
	fout << '\n' << "Quick: ";
	startTime = clock();
	Quick(vec, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(vec, unsorted, elms);
}

/**********************************************************************
* Purpose:	Uses all sorts on Array
*
* Entry: 	Array<int> myra, int * unsorted, int elms
*
* Exit:		results are printed of time taken to use each sort
************************************************************************/
void SortMyRas(Array<int>& myra, int * unsorted, int elms, ofstream &fout)
{
	clock_t startTime, endTime;

	cout << "\n\nMy Array Results\n";
	fout << "\n\nMy Array Results\n";

	cout << '\n' << "BruteBubble: ";
	fout << '\n' << "BruteBubble: ";
	startTime = clock();
	BruteBubble(myra, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(myra, unsorted, elms);

	cout << '\n' << "FlagBubble: ";
	fout << '\n' << "FlagBubble: ";
	startTime = clock();
	FlagBubble(myra, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(myra, unsorted, elms);

	cout << '\n' << "Selection: ";
	fout << '\n' << "Selection: ";
	startTime = clock();
	Selection(myra, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(myra, unsorted, elms);

	cout << '\n' << "Insertion: ";
	fout << '\n' << "Insertion: ";
	startTime = clock();
	Insertion(myra, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(myra, unsorted, elms);

	cout << '\n' << "Shell: ";
	fout << '\n' << "Shell: ";
	startTime = clock();
	Shell(myra, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(myra, unsorted, elms);

	cout << '\n' << "Heap: ";
	fout << '\n' << "Heap: ";
	startTime = clock();
	Heap(myra, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(myra, unsorted, elms);

	cout << '\n' << "MergeSort: ";
	fout << '\n' << "MergeSort: ";
	startTime = clock();
	MergeSort(myra, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(myra, unsorted, elms);

	cout << '\n' << "Quick: ";
	fout << '\n' << "Quick: ";
	startTime = clock();
	Quick(myra, elms);
	endTime = clock();
	PrintTime(endTime - startTime, fout);

	Reset(myra, unsorted, elms);
}

/**********************************************************
* Purpose:	Measure time elapsed for sort
*
* Entry:	No entry
*
* Exit:		Print time elapsed
**********************************************************/
void PrintTime(clock_t time, ofstream &fout)
{
	// this takes the time and formats it.

	int min = time / (CLOCKS_PER_SEC) / 60;
	int sec = (time / CLOCKS_PER_SEC) - (min * 60);
	int milli = time - (sec * 1000) - (min * 60 * 1000);
	cout << right << setfill('0') << setw(3) << min << ":"
		<< right << setfill('0') << setw(2) << sec << left << ":"
		<< right << setfill('0') << setw(3) << milli << flush;

	fout << right << setfill('0') << setw(3) << min << ":"
		<< right << setfill('0') << setw(2) << sec << left << ":"
		<< right << setfill('0') << setw(3) << milli << flush;
}
#endif