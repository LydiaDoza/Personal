/***********************************************************
* Class:			DLLQueue
* 		
* Managers:
* 	DLLQueue()
* 		Default constructor
*	DLLQueue(const DLLQueue & copy)
* 		Copy Ctor
*	~DLLQueue()
*		Destructor
* 	void operator=(const DLLQueue & rhs)
*		Overload the = operator
*
* Public Methods:
*	void Enqueue(T data)
*		Add T data to end of queue
*	T Dequeue()
*		Returns the front of the queue and removes it from
*		queue.
*	T& Front()
*		Returns data from front of queue but keeps it in 
*		queue
*	int Size()
*		Returns number of items in queue
*	bool isEmpty();
*		Returns true if there are no items in queue
************************************************************/
#ifndef DLLQUEUE_H
#define DLLQUEUE_H

#include "doublelinkedlist.h"
#include "Exception.h"
#include "Node.h"
#include "ThreadBSTNode.h"

template <typename T>
class DLLQueue
{
public:
	DLLQueue();
	DLLQueue(const DLLQueue<T> & copy);
	~DLLQueue();
	
	DLLQueue<T>& operator=(const DLLQueue<T> & rhs);

	void Enqueue(T data);
	T Dequeue();
	Node<T>* Front();
	int Size();
	bool isEmpty();

private:
	DoubleLinkedList<T> m_list;
	int m_items;
};

/**************************************************************
*	Purpose: 	Default Ctor
*	Entry:		None
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename T>
DLLQueue<T>::DLLQueue() : m_list(), m_items(0) { }

/**************************************************************
*	Purpose:	Copy Ctor
*	Entry:		data member to be copied
*	Exit:		this is equal to copy
****************************************************************/
template <typename T>
DLLQueue<T>::DLLQueue(const DLLQueue<T> & copy) 
	: m_list(copy.m_list), m_items(0) {}

/**************************************************************
*	Purpose:	Dtor
*	Entry:		None
*	Exit:		Memory deallocated, members set back to zero
*				or nullptr
****************************************************************/
template <typename T>
DLLQueue<T>::~DLLQueue() { m_items = 0; }

/**************************************************************
*	Purpose:	op equals
*	Entry:		DLLQueue rhs
*	Exit:		this is equal to rhs
****************************************************************/
template <typename T>
DLLQueue<T>& DLLQueue<T>::operator=(const DLLQueue<T> & rhs)
{
	if (this != &rhs)
	{
		m_items = rhs.m_items;
		m_list = rhs.m_list;
	}

return *this;
}

/**********************************************************************
* Purpose:	Adds T data to end of queue.
* Entry:	T data
* Exit:		queue grows by one, data is appended to linked list
************************************************************************/
template <typename T>
void DLLQueue<T>::Enqueue(T data)
{
	m_list.Append(data);
	++m_items;
}

/**********************************************************************
* Purpose:	Removes and returns head of queue.
* Entry:	None.
* Exit:		Head of queue.
************************************************************************/
template <typename T>
T DLLQueue<T>::Dequeue()
{
	T temp(0);

	if (isEmpty())
		throw Exception("Cannot dequeue from empty queue");
	else
	{
		temp = m_list.First();
		--m_items;
		m_list.Extract(m_list.First());
	}
	return temp;
}

/**********************************************************************
* Purpose:	Allows user to see and manipulate data in front of list.
* Entry:	None.
* Exit:		Data is returned by reference so that it can be manipulated
************************************************************************/
template <typename T>
Node<T>* DLLQueue<T>::Front() {	return m_list.getHead(); }

/**********************************************************************
* Purpose:	See number of items in queue.
* Entry:	None.
* Exit:		Number of items in queue.
************************************************************************/
template <typename T>
int DLLQueue<T>::Size() { return m_items; }

/**********************************************************************
* Purpose:	Returns true if there are no items in queue
* Entry:	None.
* Exit:		True or false.
************************************************************************/
template <typename T>
bool DLLQueue<T>::isEmpty() { return (m_items == 0); }

#endif