/***********************************************************
* Class:			Edge
*
* Managers:
* 	Edge()
* 		Default constructor
*	Edge(Vertex<V, E>* dest, int weight, E data)
*		initialize data members
*	Edge(Vertex<V, E>* dest, int weight, E data)
*		initializes data members
*	Edge(const Edge & copy)
* 		Copy Ctor
*	~Edge()
*		Destructor
* 	Edge& operator=(const Edge & rhs)
*		Overload the = operator
*
* Public Methods:
*	bool operator==(const Edge & rhs)
*		returns true if both edges are the same
************************************************************/
#ifndef EDGE_H
#define EDGE_H

template <typename V, typename E>
class Edge
{
	template <typename V, typename E>
	friend class Graph;
	template <typename V, typename E>
	friend class Vertex;

public:
	Edge();
	Edge(Vertex<V, E>* dest, int weight, E data);
	Edge(Vertex<V, E>*orig, Vertex<V, E> * dest, int weight, E data);
	Edge(const Edge<V, E> & copy);
	~Edge();

	Edge& operator=(const Edge<V, E> & rhs);
	bool operator==(const Edge<V, E> & rhs);

private:
	Vertex<V, E> * m_destination;
	Vertex<V, E>*m_origin;
	int m_weight;
	E m_data;
};

/**************************************************************
*	Purpose: 	Default Ctor
*	Entry:		None
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename V, typename E>
Edge<V, E>::Edge() : m_destination(nullptr), m_origin(nullptr), m_weight(0), m_data()
{

}

/**********************************************************************
* Purpose:	Create an edge specifying values
* Entry: 	Vertex<V, E>* dest, int weight, E data
* Exit:		Edge created with passed in values
************************************************************************/
template <typename V, typename E>
Edge<V, E>::Edge(Vertex<V, E>* dest, int weight, E data) :
m_data(data), m_destination(dest), m_origin(nullptr), m_weight(weight)
{

}

/**********************************************************************
* Purpose:	4 arg ctor
* Entry: 	Vertex<V, E>*orig, Vertex<V, E> * dest, int weight, E data
* Exit:		template <typename V, typename E>
************************************************************************/
template <typename V, typename E>
Edge<V, E>::Edge(Vertex<V, E>*orig, Vertex<V, E> * dest, int weight, E data) :
m_origin(orig), m_destination(dest), m_weight(weight), m_data(data)
{

}

/**************************************************************
*	Purpose:	Copy Ctor
*	Entry:		data member to be copied
*	Exit:		this is equal to copy
****************************************************************/
template <typename V, typename E>
Edge<V, E>::Edge(const Edge<V, E> & copy) : 
m_destination(nullptr), m_origin(nullptr), m_weight(0), m_data()
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
Edge<V, E>::~Edge()
{

}

/**************************************************************
*	Purpose:	op equals
*	Entry:		Edge rhs
*	Exit:		this is equal to rhs
****************************************************************/
template <typename V, typename E>
Edge<V, E>& Edge<V, E>::operator=(const Edge<V, E> & rhs)
{
	if (this != &rhs)
	{
		m_origin = rhs.m_origin;
		m_destination = rhs.m_destination;
		m_data = rhs.m_data;
		m_weight = rhs.m_weight;
	}
	return *this;
}

/**********************************************************************
* Purpose:	compares this data to rhs's data
* Entry: 	const Edge<V, E> & rhs
* Exit:		true or false
************************************************************************/
template <typename V, typename E>
bool Edge<V, E>::operator==(const Edge<V, E> & rhs)
{
	return (m_data == rhs.m_data && m_destination == rhs.m_destination && m_weight == rhs.m_weight);
}

#endif