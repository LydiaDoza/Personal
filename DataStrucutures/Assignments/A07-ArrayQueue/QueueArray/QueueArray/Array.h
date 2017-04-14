#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template <typename T>
class Array
{
public:
	Array();
	Array(int length, int start_index = 0);
	Array(const Array & copy);
	~Array();

	Array& operator=(const Array & rhs);
	T& operator[](int index);

	int GetStartIndex();
	void SetStartIndex(int start_index);

	int GetLength();
	void SetLength(int length);

private:
	T* m_array;
	int m_length;
	int m_start_index;

};
/**********************************************************************
* Purpose:	Default constructor
* Entry:	None
* Exit:		All members set to zero or nullptr
************************************************************************/
template <typename T>
Array<T>::Array() : m_array(nullptr), m_length(0), m_start_index(0)
{}

/**********************************************************************
* Purpose:	2/1 argument constructor
* Entry:	int length and int start index
* Exit:		sets m_length to length and m_start_index to start_index,
*			if one argument is passed: m_length to length and
*			m_start_index to zero.
************************************************************************/
template <typename T>
Array<T>::Array(int length, int start_index /*= 0*/) :
m_array(nullptr), m_length(0), m_start_index(0)
{
	if (length < 0)
		throw Exception("\nCannot have a negative length\n");
	else if (length == 0)
		m_start_index = start_index;
	else
	{
		m_length = length;
		m_start_index = start_index;
		m_array = new T[length]();
	}
}

/**********************************************************************
* Purpose:	Copy Ctor
* Entry:	const Array & copy
* Exit:		this is equal to copy
************************************************************************/
template <typename T>
Array<T>::Array(const Array<T> & copy) :
m_array(nullptr), m_length(copy.m_length), m_start_index(copy.m_start_index)
{
	m_array = new T[copy.m_length](); 
	// the () allows the default values to be stored

	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = copy.m_array[i];
	}
}

/**********************************************************************
* Purpose:	Dtor
* Entry:	None.
* Exit:		Data members set to zero or nullptr
************************************************************************/
template <typename T>
Array<T>::~Array()
{
	delete[] m_array;
	m_array = nullptr;

	m_length = 0;
	m_start_index = 0;
}

/**********************************************************************
* Purpose:	op equals does stuff
* Entry:	const ARray & rhs
* Exit:		this is equal to rhs.
************************************************************************/
template <typename T>
Array<T>& Array<T>::operator=(const Array<T> & rhs)
{
	if (this != &rhs)
	{
		// if this array is not the same length
		// of rhs array, delete this array and make
		// a new one of the same length
		if (m_length != rhs.m_length)
		{
			delete[] m_array;
			m_array = new T[rhs.m_length]();
			m_length = rhs.m_length;
		}

		for (int i = 0; i < m_length; i++)
		{
			m_array[i] = rhs.m_array[i];
		}

		m_start_index = rhs.m_start_index;
	}
	return *this;
}

/**********************************************************************
* Purpose:	overloads the [] operator.
* Entry:	int index for the array
* Exit:		returns data member in array at the index
************************************************************************/
template <typename T>
T& Array<T>::operator[](int index)
{
	if ((index - m_start_index) >= m_length)
		throw Exception("Access denied. Index is larger than array is.");
	else if ((index - m_start_index) < 0)
		throw Exception("Access denied. Index is below start index.");

	return m_array[index - m_start_index];
}

/**********************************************************************
* Purpose:	returns start index
* Entry:	None.
* Exit:		start index is returned
************************************************************************/
template <typename T>
int Array<T>::GetStartIndex()
{ return m_start_index; }

/**********************************************************************
* Purpose:	Sets start index
* Entry:	int for start index
* Exit:		m_start_index is set to start_index
************************************************************************/
template <typename T>
void Array<T>::SetStartIndex(int start_index)
{ m_start_index = start_index; }

/**********************************************************************
* Purpose:	Returns m_length
* Entry:	None.
* Exit:		m_length is returned
************************************************************************/
template <typename T>
int Array<T>::GetLength()
{ return m_length; }

/**********************************************************************
* Purpose:	sets m_length
* Entry:	int for length of array
* Exit:		m_length is set to length
************************************************************************/
template <typename T>
void Array<T>::SetLength(int length)
{
	int shortest = (length < m_length) ? length : m_length;
	// create a temp array of size length
	if (length > 0)
	{
		T * temp = new T[length]();
		// Array temp(length, start_index);
		
		for (int i = 0; i < shortest; i++)
		{
			temp[i] = m_array[i];
		}

		m_length = length;
		delete[] m_array;
		m_array = new T[m_length]();

		//*****************************
		// instead of this
		for (int i = 0; i < m_length; i++)
			m_array[i] = temp[i];

		delete[] temp;
		// can do this
		// *this = temp;
		//*****************************
	}
	else if (length = 0)
	{
		m_length = length;
		delete[] m_array;
		m_array = nullptr;
	}
	else
		throw Exception("Cannot have a negative length");
}
#endif
