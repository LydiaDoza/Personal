/***********************************************************
* Class:			Vertex
* 		
* Managers:
* 	Vertex()
* 		Default constructor
*	Vertex(const Vertex & copy)
* 		Copy Ctor
*	~Vertex()
*		Destructor
* 	void operator=(const Vertex & rhs)
*		Overload the = operator
*
* Public Methods:
*	bool operator ==(const Vertex & rhs)
*		returns true if both vertices are the same
************************************************************/
#ifndef VERTEX_H
#define VERTEX_H

#include "Edge.h"
#include <list>
using std::list;

template <typename V, typename E>
class Vertex
{
	template <typename V, typename E>
	friend class Graph;

public:
	Vertex();
	Vertex(const V & data);
	Vertex(const Vertex<V, E> & copy);
	~Vertex();
	
	Vertex& operator=(const Vertex<V, E> & rhs);
	bool operator==(const Vertex<V, E> & rhs);
	
private:
	list<Edge<V,E>> m_edges;
	V m_data;
	bool m_processed;
};

/**************************************************************
*	Purpose: 	Default Ctor
*	Entry:		None
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename V, typename E>
Vertex<V, E>::Vertex() : m_edges(), m_data(), m_processed(false)
{

}

/**********************************************************************
* Purpose:	1 arg ctor: Create a vertex with data
* Entry: 	const V & data
* Exit:		vertex object created.
************************************************************************/
template <typename V, typename E>
Vertex<V, E>::Vertex(const V & data) : m_data(data), m_edges(), m_processed(false)
{

}

/**************************************************************
*	Purpose:	Copy Ctor
*	Entry:		data member to be copied
*	Exit:		this is equal to copy
****************************************************************/
template <typename V, typename E>
Vertex<V, E>::Vertex(const Vertex<V, E> & copy) : 
m_edges(copy.m_edges), m_data(copy.m_data), m_processed(copy.m_processed)
{
	*this = copy;
}

/**************************************************************
*	Purpose:	Dtor
*	Entry:		None
*	Exit:		Memory deallocated, members set back to zero
*				or nullptr
****************************************************************/
template <typename V, typename E>
Vertex<V, E>::~Vertex()
{
	m_processed = false;
}

/**************************************************************
*	Purpose:	op equals
*	Entry:		Vertex rhs
*	Exit:		this is equal to rhs
****************************************************************/
template <typename V, typename E>
Vertex<V, E>& Vertex<V, E>::operator=(const Vertex<V, E> & rhs)
{
	if (this != &rhs)
	{
		m_edges = rhs.m_edges;
		m_data = rhs.m_data;
		m_processed = rhs.m_processed;
	}

return *this;
}

/**********************************************************************
* Purpose:	Checks to see if two Vertices have the same data
* Entry: 	const Vertex<V, E> & rhs
* Exit:		true or false
************************************************************************/
template <typename V, typename E>
bool Vertex<V, E>::operator==(const Vertex<V, E> & rhs)
{
	return (m_data == rhs.m_data);
}

#endif