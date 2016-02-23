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
*	
*
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
	Vertex(const Vertex<V, E> & copy);
	~Vertex();
	
	Vertex& operator=(const Vertex<V, E> & rhs);
	
private:
	list<Edge<V,E>> m_edges;
	V m_data;
	bool m_processed;
};

/**************************************************************
*	Purpose: 	Default Ctor
*
*	Entry:		None
*
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename V, typename E>
Vertex<V, E>::Vertex() : m_edges(), m_data(), m_processed(false)
{

}

/**************************************************************
*	Purpose:	Copy Ctor
*
*	Entry:		data member to be copied
*
*	Exit:		this is equal to copy
****************************************************************/
template <typename V, typename E>
Vertex<V, E>::Vertex(const Vertex<V, E> & copy)
{

}

/**************************************************************
*	Purpose:	Dtor
*
*	Entry:		None
*
*	Exit:		Memory deallocated, members set back to zero
*				or nullptr
****************************************************************/
template <typename V, typename E>
Vertex<V, E>::~Vertex()
{

}

/**************************************************************
*	Purpose:	op equals
*
*	Entry:		Vertex rhs
*
*	Exit:		this is equal to rhs
****************************************************************/
template <typename V, typename E>
Vertex<V, E>& Vertex<V, E>::operator=(const Vertex<V, E> & rhs)
{
	if (this != &rhs)
	{
	
	}

return *this;

}

#endif