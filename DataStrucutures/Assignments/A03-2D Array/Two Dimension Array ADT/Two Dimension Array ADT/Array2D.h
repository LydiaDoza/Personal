/***********************************************************
* Class:			Array2D
*
* Managers:
* 	Array2D()
* 		Default constructor
*	Array2D(int row, int col = 0)
*		Two/One arg ctor, sets m_row to row, m_col to col 
*		if not col input, col = 0
*	Array2D(const Array2D & copy)
* 		Copy Ctor
*	~Array2D()
*		Destructor
* 	Array2D& operator=(const Array2D & rhs)
*		Overload the = operator
*
* Public Methods:
*	Row<T> operator[](int row)
*		Overloads operator to use native 2D array notation
*	const Row<T> operator[](int row) const
*		Same as above but called from const objects
*	int getRow() const
*		Returns m_row from this
*	void setRow(int rows)
*		Sets this m_row
*	int getColumn() const
*		Returns m_col from this
*	void setColumn(int columns)
*		Sets this m_col
*	T & Select(int row, int col)
*		Returns value in element of array using row major
*		order
*	const T & Select(int row, int col) const
*		same as above but handles const
************************************************************/
#ifndef ARRAY2D_H
#define ARRAY2D_H

#include "Array.h"
#include "Row.h"
#include "Exception.h"

template <typename T>
class Array2D
{
public:
	Array2D();
	Array2D(int row, int col = 0);
	Array2D(const Array2D & copy);
	~Array2D();
	Array2D& operator=(const Array2D & rhs);

	Row<T> operator[](int row);	// DO NOT return by reference
	const Row<T> operator[](int row) const;

	int getRow() const;
	void setRow(int rows);

	int getColumn() const;
	void setColumn(int columns);

	T & Select(int row, int col);
	const T & Select(int row, int col) const;

protected:
	Array<T> m_array;
	int m_row;
	int m_col;
};

/**************************************************************
*	Purpose: 	Default Ctor
*
*	Entry:		None
*
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename T>
Array2D<T>::Array2D() : m_row(0), m_col(0), m_array()
{

}

/**************************************************************
*	Purpose: 	Two argument Ctor
*
*	Entry:		None
*
*	Exit:		All data members set to passed in values or
*				nullptr.
****************************************************************/
template <typename T>
Array2D<T>::Array2D(int row, int col /* = 0 */) : m_row(row), m_col(col), m_array(row*col)
{

}

/**************************************************************
*	Purpose:	Copy Ctor
*
*	Entry:		data member to be copied
*
*	Exit:		this is equal to copy
****************************************************************/
template <typename T>
Array2D<T>::Array2D(const Array2D<T> & copy)
{
	*this = copy;
}

/**************************************************************
*	Purpose:	Dtor
*
*	Entry:		None
*
*	Exit:		Memory deallocated, members set back to zero
*				or nullptr
****************************************************************/
template <typename T>
Array2D<T>::~Array2D()
{
	m_row = 0;
	m_col = 0;
}

/**************************************************************
*	Purpose:	op equals
*
*	Entry:		Array2D rhs
*
*	Exit:		this is equal to rhs
****************************************************************/
template <typename T>
Array2D<T>& Array2D<T>::operator=(const Array2D<T> & rhs)
{
	if (this != &rhs)
	{
		m_array = rhs.m_array;
		m_row = rhs.m_row;
		m_col = rhs.m_col;
	}

	return *this;
}

/**********************************************************************
* Purpose:	overload
*
* Entry:	int row
*
* Exit:		Row created by *this and input row
************************************************************************/
template <typename T>
Row<T> Array2D<T>::operator[](int row)
{
	if (row >= m_row)
		throw Exception("Access denied. Index is larger than array is.");
	else if (row < 0)
		throw Exception("Access denied. Index is below start index.");

	return Row<T>(*this, row);
}

/**********************************************************************
* Purpose:	overload
*
* Entry:	int row
*
* Exit:		Row created by *this and input row
************************************************************************/
template <typename T>
 const Row<T> Array2D<T>::operator[](int row) const
{
	if (row >= m_row)
		throw Exception("Access denied. Index is larger than array is.");
	else if (row < 0)
		throw Exception("Access denied. Index is below start index.");

	return Row<T>(*this, row);
}



/**********************************************************************
* Purpose:	Gets m_row from Array2D
*
* Entry:	none
*
* Exit:		m_row
************************************************************************/
template <typename T>
int Array2D<T>::getRow() const
{
	return m_row;
}

/**********************************************************************
* Purpose:	Set m_rows of Array2D object. Warning: If you set the array
*			to a smaller size, there will be a possible loss of data.
*
* Entry:	int rows
*
* Exit:		m_row is set to rows
************************************************************************/
template <typename T>
void Array2D<T>::setRow(int rows)
{
	int new_size = rows * m_col;

	if (rows < 0)
	{
		throw Exception("You cannot set the number of rows to a negative number.");
	}

	m_array.SetLength(new_size);
	m_row = rows;
}

/**********************************************************************
* Purpose:	Returns m_col from calling Array2D object
*
* Entry:	None.
*
* Exit:		m_col
************************************************************************/
template <typename T>
int Array2D<T>::getColumn() const
{
	return m_col;
}

/**********************************************************************
* Purpose:	Set m_col in calling Array2D object to input columns
*
* Entry:	int columns
*
* Exit:		m_col is set to columns
************************************************************************/
template <typename T>
void Array2D<T>::setColumn(int columns)
{
	int new_size = m_row * columns;
	int smallest_col = (columns < m_col) ? columns : m_col;

	if (columns < 0)
	{
		throw Exception("You cannot set your column to a negative size.");
	}

	Array<T> toArray(new_size);

	// make sure to copy all rows
	for (int i_row = 0; i_row < m_row; i_row++)
	{
		// smallest col takes care of whether or not the 
		// input columns is smaller or larger than m_col
		for (int i_col = 0; i_col < smallest_col; i_col++)
		{
			// to copy it to the desired element in the copy array
			// determine what row we're in with the right number of
			// new columns, and copy
			toArray[i_row * columns + i_col] = m_array[i_row * m_col + i_col];
		}
	}
	
	// now set the new size
	m_array.SetLength(new_size);

	// make sure to copy it all back
	for (int i = 0; i < new_size; i++)
		m_array[i] = toArray[i];

	m_col = columns;
}

/**********************************************************************
* Purpose:	accesses element in m_array so that it can be changed in
*			test code using conventional array[][] notation
*
* Entry:	row and col for desired access.
*
* Exit:		Element in the desired array
************************************************************************/
template <typename T>
T & Array2D<T>::Select(int row, int col)
{
	// called from row subscript operator
	// error checking

	if (col >= m_col || row >= m_row)
		throw Exception("Access Denied. Index is above start index.");
	else if (col < 0 || row < 0)
		throw Exception("Access denied. Index is below start index.");

	// m_row is the passed in row value aka the desired row
	// column is desired column
	// d_row * m_col + d_col
	return m_array[(row * m_col) + col];
}

/**********************************************************************
* Purpose:	accesses element in m_array so that it can be changed in
*			test code using conventional array[][] notation
*
* Entry:	row and col for desired access.
*
* Exit:		Element in the desired array
************************************************************************/
template <typename T>
const T & Array2D<T>::Select(int row, int col) const
{
	// called from row subscript operator
	// error checking

	if (col >= m_col || row >= m_row)
		throw Exception("Access Denied. Index is above start index.");
	else if (col < 0 || row < 0)
		throw Exception("Access denied. Index is below start index.");

	// m_row is the passed in row value aka the desired row
	// column is desired column
	// d_row * m_col + d_col
	return m_array[(row * m_col) + col];
}

#endif