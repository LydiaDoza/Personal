/***********************************************************
* Class:			Edge
* 		
* Managers:
* 	Edge()
* 		Default constructor
*	Edge(Vertex<V, E>* dest, int weight, E data)
*		initialize data members
*	Edge(const Edge & copy)
* 		Copy Ctor
*	~Edge()
*		Destructor
* 	void operator=(const Edge & rhs)
*		Overload the = operator
*
* Public Methods:
*	
*
************************************************************/
#ifndef EDGE_H
#define EDGE_H

template <typename V, typename E>
class Vertex;

template <typename V, typename E>
class Edge
{
	template <typename V, typename E>
	friend class Graph;

public:
	Edge();
	Edge(Vertex<V, E>* dest, int weight, E data);
	Edge(const Edge<V, E> & copy);
	~Edge();
	
	Edge& operator=(const Edge<V, E> & rhs);
	
private:
	Vertex<V, E> * m_destination;
	int m_weight;
	E m_data;
};

/**************************************************************
*	Purpose: 	Default Ctor
*
*	Entry:		None
*
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename V, typename E>
Edge<V, E>::Edge() : m_destination(nullptr), m_weight(0), m_data()
{

}

/**********************************************************************
* Purpose:	Create an edge specifying values
*
* Entry: 	Vertex<V, E>* dest, int weight, E data
*
* Exit:		Edge created with passed in values
************************************************************************/
template <typename V, typename E>
Edge<V, E>::Edge(Vertex<V, E>* dest, int weight, E data) :
m_data(data), m_destination(dest), m_weight(weight)
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
Edge<V, E>::Edge(const Edge<V, E> & copy) : m_destination(nullptr), m_weight(0), m_data()
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
Edge<V, E>::~Edge()
{

}

/**************************************************************
*	Purpose:	op equals
*
*	Entry:		Edge rhs
*
*	Exit:		this is equal to rhs
****************************************************************/
template <typename V, E>
Edge<V, E>& Edge<V, E>::operator=(const Edge<V, E> & rhs)
{
	if (this != &rhs)
	{
	
	}

return *this;

}

#endif