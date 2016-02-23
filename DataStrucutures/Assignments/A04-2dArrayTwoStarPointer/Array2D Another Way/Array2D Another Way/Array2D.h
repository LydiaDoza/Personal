/***********************************************************
* Class:			Array2D
*
* Managers:
* 	Array2D()
* 		Default constructor
*	Array2D(int row, int col = 0)
*		Two/One arg ctor, sets m_row to row, m_col to col
*		if not col input, col = 0, deletes everything in
*		m_array and sets it to nullptr
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
*	void Purge()
*		Deletes all of the rows in m_array, then deletes
*		m_array. Sets m_array to nullptr, m_row and m_col=0
************************************************************/
#ifndef ARRAY2D_H
#define ARRAY2D_H

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

	void Purge();

protected:
	T** m_array;
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
Array2D<T>::Array2D() : m_row(0), m_col(0), m_array(nullptr)
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
Array2D<T>::Array2D(int row, int col /* = 0 */) : m_row(row), m_col(col), m_array(nullptr)
{
	m_array = new T*[row]();

	// fill the rows with the right number of columns
	for (int i = 0; i < row; i++)
	{
		m_array[i] = new T[col]();
	}

}

/**************************************************************
*	Purpose:	Copy Ctor
*
*	Entry:		data member to be copied
*
*	Exit:		this is equal to copy
****************************************************************/
template <typename T>
Array2D<T>::Array2D(const Array2D<T> & copy) : m_row(0), m_col(0), m_array(nullptr)
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
	Purge();
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
		Purge();
		m_row = rhs.m_row;
		m_col = rhs.m_col;

		m_array = new T*[m_row];

		// deep copy
		for (int i_row = 0; i_row < m_row; i_row++)
		{
			m_array[i_row] = new T[m_col];

			for (int i_col = 0; i_col < m_col; i_col++)
			{
				m_array[i_row][i_col] = rhs[i_row][i_col];
			}
		}
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
	int smaller = (m_row < rows) ? m_row : rows;
	int old_col = m_col;

	// can't have negative rows
	if (rows < 0)
	{
		throw Exception("You cannot set the number of rows to a negative number.");
	}

	// rows is 0
	if (rows == 0)
	{
		Purge();
		m_col = old_col;
	}
	// a different size
	else if (rows != m_row)
	{
		T** temp = new T*[rows]();

		// copy back data from original m_array
		// and pointers to data
		for (int i = 0; i < smaller; i++)
		{
			temp[i] = m_array[i];
		}

		for (int i_row = smaller; i_row < m_row; i_row++)
		{
			delete[] m_array[i_row];
			m_array[i_row] = nullptr;
		}

		// allocate memory for the new rows only if old_row
		for (int i_row = m_row; i_row < rows; i_row++)
		{
			temp[i_row] = new T[m_col]();
		}

		delete[] m_array;
		m_array = temp;
		m_row = rows;
		m_col = old_col;
	}
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
	int small_col = (columns < m_col) ? columns : m_col;
	int old_row = m_row;

	if (columns < 0)
	{
		throw Exception("You cannot set your column to a negative size.");
	}

	if (columns == 0)
	{
		Purge();
		m_row = old_row;
	}
	else if (columns != m_col)
	{
		T** copy = new T*[m_row]();

		for (int i_row = 0; i_row < m_row; i_row++)
		{
			copy[i_row] = new T[columns]();

			for (int i_col = 0; i_col < small_col; i_col++)
			{
				copy[i_row][i_col] = m_array[i_row][i_col];
			}
		}

		Purge();
		m_array = copy;
		m_row = old_row;
		m_col = columns;

	}
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
	return m_array[row][col];
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
	return m_array[row][col];
}


/**********************************************************************
* Purpose:	Gets rid of everything in m_array and resets m_row and
*			m_col
*
* Entry:	None
*
* Exit:		m_array is nullptr, m_row and m_col set to 0
************************************************************************/
template <typename T>
void Array2D<T>::Purge()
{
	// first delete the innermost pointer
	for (int i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
		m_array[i] = nullptr;
	}

	//finally delete m_array
	delete[] m_array;

	m_array = nullptr;

	m_row = 0;
	m_col = 0;
}

#endif