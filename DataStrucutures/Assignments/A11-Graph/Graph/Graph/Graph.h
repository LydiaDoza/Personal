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
*	void InsertVertex(const V & data)
*		Insert a vertex that stores the data passed in.
*	void DeleteVertex(const V & data)
*		Deletes the vertex that matches the target data
*	void InsertEdge(const V & from, const V & to, const E & edge, int weight)
*		Add an arc to the graph. The arc connects the two vertices specified by the two parameters.
*	void DeleteEdge(const V & from, const V & to, const E & edge, int weight)
*		Disconnects the specified vertices.
*	void DepthFirst(void(*visit) (const V & data))
*
*	void BreadthFirst(void(*visit) (const V & data))
*		Performs Breadthfirst traversal of graph
*	bool isEmpty();
*		Returns true if there are no vertices in list
************************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include <stack>
using std::stack;

#include <queue>
using std::queue;

#include "Exception.h"
#include "Vertex.h"

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
	void InsertEdge(const V & from, const V & to, const E & edge, int weight);
	// Add an arc to the graph. The arc connects the two vertices specified by the two parameters.
	void DeleteEdge(const V & from, const V & to, const E & edge, int weight); // Disconnects the specified vertices.
	void DepthFirst(void(*visit) (const V & data));
	void BreadthFirst(void(*visit) (const V & data));
	bool isEmpty(); // checks to see if graph is empty
	

private:
	list<Vertex<V, E>> m_vertices;
};

/**************************************************************
*	Purpose: 	Default Ctor
*	Entry:		None
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename V, typename E>
Graph<V, E>::Graph() : m_vertices()
{}

/**************************************************************
*	Purpose:	Copy Ctor
*	Entry:		data member to be copied
*	Exit:		this is equal to copy
****************************************************************/
template <typename V, typename E>
Graph<V, E>::Graph(const Graph<V, E> & copy)
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
Graph<V, E>::~Graph()
{

}

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
		m_vertices.clear();
		// Vertices first
		for (Vertex<V, E> v : rhs.m_vertices)
			// create new vertices
			InsertVertex(v.m_data);

		//Then Edges
		for (Vertex<V, E> v : rhs.m_vertices) // go through all the vertices
			for (Edge<V, E> e : v.m_edges)
				InsertEdge(v.m_data, e.m_destination->m_data, e.m_data, e.m_weight);
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
	for (list<Vertex<V, E>>::iterator it = m_vertices.begin(); it != m_vertices.end(); it++)
		if (it->m_data == data)
			throw Exception("Data already exists in graph");

	m_vertices.emplace_back(data);
}

/**********************************************************************
* Purpose:	Deletes a vertex from graph containing V data.
* Entry: 	V data
* Exit:		Vertex containing V data is deleted from graph.
************************************************************************/
template <typename V, typename E>
void Graph<V, E>::DeleteVertex(const V & data)
{
	list<Edge<V, E>> edgesToDelete;

	// go through all the vertices to see if vertex in question exists
	for (Vertex<V, E> & v : m_vertices)
		// check every edge
		for (Edge<V, E> & e : v.m_edges)
			if (e.m_destination->m_data == data)
				edgesToDelete.emplace_back(&v, e.m_destination, e.m_weight, e.m_data);

	for (Edge<V, E> & e : edgesToDelete)
		DeleteEdge(e.m_origin->m_data, e.m_destination->m_data, e.m_data, e.m_weight);

	m_vertices.remove(data);
}

/**********************************************************************
* Purpose:	Insert an edge between V from and V to.
* Entry: 	V from, V to, E edge
* Exit:		edge inserted.
************************************************************************/
template <typename V, typename E>
void Graph<V, E>::InsertEdge(const V & from, const V & to, const E & edge, int weight)
{
	bool findFrom = false, findTo = false;
	// temp iterators
	list<Vertex<V, E>>::iterator iteratorFrom = m_vertices.begin(), iteratorTo = m_vertices.begin();


	// go through list while "from" isn't found and "to" isn't found
	for (list<Vertex<V, E>>::iterator it = m_vertices.begin();
	it != m_vertices.end() && !(findFrom && findTo);
		++it)
	{
		if (it->m_data == from)
		{
			findFrom = true;
			iteratorFrom = it;
		}
		if (it->m_data == to)
		{
			findTo = true;
			iteratorTo = it;
		}
	}

	if (!findFrom)
		throw Exception("Data \"from\" is not valid.");
	else if (!findTo)
		throw Exception("Data \"to\" is not valid");
	// both are valid
	else
	{
		for (Edge<V, E> & e : iteratorFrom->m_edges)

			// check that the edge doesn't already exist
			// if it does, stahhhhhhp it
			if (e.m_data == edge && 
				e.m_destination->m_data == to)
			{
				cout << iteratorFrom->m_data << " with edge " << edge << " --- ";
				throw Exception("Edge already exists. Edge not inserted");
			}

		//not a directional graph, so insert edges to both
		//Edge(Vertex<V, E>*orig, Vertex<V, E> * dest, int weight, E data)
		iteratorFrom->m_edges.emplace_back(&(*iteratorFrom), &(*iteratorTo), weight, edge); //
		iteratorTo->m_edges.emplace_back(&(*iteratorTo), &(*iteratorFrom), weight, edge);
	}
}

/**********************************************************************
* Purpose:	Deletes an edge between V from and V to.
* Entry: 	V from, V to, E edge
* Exit:		Edge deleted between V from and V to.
************************************************************************/
template <typename V, typename E>
void Graph<V, E>::DeleteEdge(const V & from, const V & to, const E & edge, int weight)
{
	Vertex<V, E> *fromPtr = nullptr, *toPtr = nullptr;

	for (Vertex<V, E> & v : m_vertices)
	{
		if (v.m_data == from)
			fromPtr = &v;
		if (v.m_data == to)
			toPtr = &v;
	}

	if (fromPtr == nullptr)
		throw Exception("\"From\" data does not exist.");
	if (toPtr == nullptr)
		throw Exception("\"To\" data doesn't exist.");

	fromPtr->m_edges.remove(Edge<V, E>(fromPtr, toPtr, weight, edge));
	toPtr->m_edges.remove(Edge<V, E>(toPtr, fromPtr, weight, edge));
}

/**********************************************************************
* Purpose:	Depth First Traversal
* Entry: 	void(*visit) (V data)
* Exit:		Each vertex in graph is visited once.
************************************************************************/
template <typename V, typename E>
void Graph<V, E>::DepthFirst(void(*visit) (const V & data))
{
	stack<Vertex<V, E> *> stac;
	Vertex<V, E> * top = nullptr;

	stac.push(&m_vertices.front()); // put first item in stack
	stac.top()->m_processed = true;

	while (!stac.empty())
	{
		top = stac.top();
		visit(top->m_data);
		stac.pop();

		for (Edge<V, E> & e : top->m_edges)
		{
			if (!e.m_destination->m_processed)
			{
				stac.push(e.m_destination);
				e.m_destination->m_processed = true;
			}
		}
	}

	// set everything back to unprocessed
	for (Vertex<V, E> & v : m_vertices)
		v.m_processed = false;
}

/**********************************************************************
* Purpose:	Breadth First traversal
* Entry: 	void(*visit) (V data)
* Exit:		Each Vertex in graph is visited once.
************************************************************************/
template <typename V, typename E>
void Graph<V, E>::BreadthFirst(void(*visit) (const V & data))
{
	queue<Vertex<V, E> *> q;
	Vertex<V, E> * first = nullptr;

	q.push(&m_vertices.front()); // put first item in stack
	q.front()->m_processed = true;

	while (!q.empty())
	{
		visit(q.front()->m_data);

		// fill queue
		for (Edge<V, E> & e : q.front()->m_edges)
		{
			if (!e.m_destination->m_processed)
			{
				q.push(e.m_destination);
				e.m_destination->m_processed = true;
			}
		}
		q.pop();
	}

	// set everything back to unprocessed
	for (Vertex<V, E> & v : m_vertices)
		v.m_processed = false;
}

/**********************************************************************
* Purpose:	Checks to see if the Graph is empty.
* Entry:	None.
* Exit:		True or False
************************************************************************/
template <typename V, typename E>
bool Graph<V, E>::isEmpty()
{
	return m_vertices.empty();
}

#endif