/***********************************************************
* Class:			Graph
* 		
* Managers:
* 	Graph()
* 		Default constructor
*	Graph(const Graph & copy)
* 		Copy Ctor
*	~Graph()
*		Destructor
* 	void operator=(const Graph & rhs)
*		Overload the = operator
*
* Public Methods:
*	
*
************************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include <list>
using std::list;

#include "Exception.h"

template <typename V, typename E>
class Graph
{
public:
	Graph();
	Graph(const Graph<V, E> & copy);
	~Graph();
	
	Graph<V, E>& operator=(const Graph<V, E> & rhs);
	
	void InsertVertex(const V & data); // Insert a vertex that stores the data passed in.
	void DeleteVertex(const V & data); // Deletes the vertex that matches the target data
	void InsertArc(const V & from, const V & to, const E & edge); 
			// Add an arc to the graph. The arc connects the two vertices specified by the two parameters.
	void DeleteArc(const V & from, const V & to, const E & edge); // Disconnects the specified vertices.
	void DepthFirst(void(*visit) (const V & data));
	void BreadthFirst(void(*visit) (const V & data));
	bool isEmpty(); // checks to see if graph is empty

private:
	list<Vertex<V, E> *> m_vertices;
	int m_count;
};

/**************************************************************
*	Purpose: 	Default Ctor
*	Entry:		None
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename V, typename E>
Graph<V, E>::Graph() : m_vertices(), m_count(0)
{}

/**************************************************************
*	Purpose:	Copy Ctor
*	Entry:		data member to be copied
*	Exit:		this is equal to copy
****************************************************************/
template <typename V, typename E>
Graph<V, E>::Graph(const Graph<V, E> & copy)
{

}

/**************************************************************
*	Purpose:	Dtor
*	Entry:		None
*	Exit:		Memory deallocated, members set back to zero
*				or nullptr
****************************************************************/
template <typename V, typename E>
Graph<V, E>::~Graph()
{}

/**************************************************************
*	Purpose:	op equals
*	Entry:		Graph rhs
*	Exit:		this is equal to rhs
****************************************************************/
template <typename V, typename E>
Graph<V, E>& Graph<V, E>::operator=(const Graph<V, E> & rhs)
{
	if (this != &rhs)
	{
		
	}

	return *this;
}

/**********************************************************************
* Purpose:	Inserts a new vertex containing V data into graph
* Entry: 	V data
* Exit:		Vertex is inserted into graph
************************************************************************/
template <typename V, typename E>
void Graph<V, E>::InsertVertex(const V & data)
{
	//check to see if vertex already exists
	// iterator starts at beginning of list
	// goes through until end of list
	for (list<V>::iterator it = m_vertices.begin(); it != m_vertices.end(); it++)
		if (data == *it->m_data)
			throw Exception("Data already exists in graph");

	m_vertices.emplace_back(data);
	++m_count;
}

/**********************************************************************
* Purpose:	Deletes a vertex from graph containing V data.
* Entry: 	V data
* Exit:		Vertex containing V data is deleted from graph.
************************************************************************/
template <typename V, typename E>
void Graph<V, E>::DeleteVertex(const V & data)
{

}

/**********************************************************************
* Purpose:
* Entry: 	V from, V to, E edge
* Exit:		
************************************************************************/
template <typename V, typename E>
void Graph<V, E>::InsertArc(const V & from, const V & to, const E & edge)
{

}

/**********************************************************************
* Purpose:
* Entry: 	V from, V to, E edge
* Exit:		
************************************************************************/
template <typename V, typename E>
void Graph<V, E>::DeleteArc(const V & from, const V & to, const E & edge)
{

}

/**********************************************************************
* Purpose:
* Entry: 	void(*visit) (V data)
* Exit:		
************************************************************************/
template <typename V, typename E>
void Graph<V, E>::DepthFirst(void(*visit) (const V & data))
{

}

/**********************************************************************
* Purpose:
* Entry: 	void(*visit) (V data)
* Exit:		
************************************************************************/
template <typename V, typename E>
void Graph<V, E>::BreadthFirst(void(*visit) (const V & data))
{

}

/**********************************************************************
* Purpose:
* Entry:
* Exit:		template <typename V, typename E>
bool
************************************************************************/
template <typename V, typename E>
bool Graph<V, E>::isEmpty()
{

}
#endif