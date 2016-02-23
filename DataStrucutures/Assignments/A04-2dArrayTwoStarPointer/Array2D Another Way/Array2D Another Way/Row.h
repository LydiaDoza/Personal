/***********************************************************
* Class:			Row
* 		
* Managers:
* 	Row(Array2D<T> in_array, int row)
* 		Two argument constructor
*	~Row()
*		Destructor
*
*	Array2D ref needs to be initialized, not assigned so
*	no operator=
*
* Public Methods:
*	T& operator[](int column)
*		overloads [] so that the element in the 2D array
*		can be accessed.
*	const T& operator[](int column) const
*		this is to be called by constant objects
************************************************************/
#ifndef ROW_H
#define ROW_H

template <typename T>
class Row
{
	template <typename T>
	friend class Array2D;

public:
	Row(const Array2D<T>& in_array, int row);
	T& operator[](int column);
	const T& operator[](int column) const;
protected:
	Array2D<T>& m_array2D;
	int m_row;
};

/**********************************************************************
* Purpose:	2 argument ctor
*
* Entry:	Array2D in_array and int row
*
* Exit:		m_row is set to row and m_array is set to in_array
************************************************************************/
template <typename T>
Row<T>::Row(const Array2D<T>& in_array, int row) : m_array2D(const_cast<Array2D<T> &>(in_array)), m_row(row)
{

}

/**********************************************************************
* Purpose:	Overload the [] operator so that access can be granted
*			to the flattened 2D array
*
* Entry:	column index
*
* Exit:		element in the array at position (row)(column)
************************************************************************/
template <typename T>
T& Row<T>::operator[](int column)
{
	return m_array2D.Select(m_row, column);
}


/**********************************************************************
* Purpose:	Overload the [] operator so that access can be granted
*			to the flattened 2D array
*
* Entry:	column index
*
* Exit:		element in the array at position (row)(column)
************************************************************************/
template <typename T>
const T& Row<T>::operator[](int column) const
{
	return m_array2D.Select(m_row, column);
}

#endif
