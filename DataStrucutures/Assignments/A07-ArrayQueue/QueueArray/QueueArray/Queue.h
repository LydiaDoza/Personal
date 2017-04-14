/***********************************************************
* Class:			Queue
* Managers:
* 	Queue()
* 		Default constructor
*	Queue(const Queue & copy)
* 		Copy Ctor
*	~Queue()
*		Destructor
* 	void operator=(const Queue & rhs)
*		Overload the = operator
*
* Public Methods:
*	void Enqueue(T toadd)
*		adds T type toadd to queue's array
*	T Dequeue()
*		returns T type from head of queue
*	T& Front()
*		allows user to change what is at the head of queue
*	int Size()
*		returns the number of items in queue
*	bool isEmpty()
*		returns true if there are no items in queue
*	bool isFull()
*		returns true if the queue is full
************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include "Array.h"
#include "Exception.h"

template <typename T>
class Queue
{
public:
	Queue();
	Queue(int size);
	Queue(const Queue & copy);
	~Queue();

	Queue& operator=(const Queue & rhs);

	void Enqueue(T toadd);
	T Dequeue();
	T& Front();
	int Size();

private:
	Array<T> m_array;
	int m_size;
	int m_items;
	int m_head;
	int m_tail;
	bool isEmpty();
	bool isFull();
};

/**************************************************************
* Purpose: 	Default Ctor
* Entry:	None
* Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename T>
Queue<T>::Queue() : m_array(), m_size(0), m_items(0), m_head(0), m_tail(0)
{}

/**********************************************************************
* Purpose:	1 arg ctor initializes Queue size
* Entry:	int size
* Exit:		Data member initialized.
************************************************************************/
template <typename T>
Queue<T>::Queue(int size) :m_array(size), m_size(size), m_items(0), m_head(0), m_tail(0)
{}

/**************************************************************
* Purpose:	Copy Ctor
* Entry:		data member to be copied
* Exit:		this is equal to copy
****************************************************************/
template <typename T>
Queue<T>::Queue(const Queue<T> & copy)
{
	*this = copy;
}

/**************************************************************
* Purpose:	op equals
* Entry:	Queue rhs
* Exit:		this is equal to rhs
****************************************************************/
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T> & rhs)
{
	if (this != &rhs)
	{
		m_array = rhs.m_array;	// Array class handles deep copy
		m_size = rhs.m_size;
		m_tail = rhs.m_tail;
		m_head = rhs.m_head;
		m_items = rhs.m_items;
	}

	return *this;
}

/**************************************************************
* Purpose:	Dtor
* Entry:	None
* Exit:		Memory deallocated, members set back to zero
*			or nullptr
****************************************************************/
template <typename T>
Queue<T>::~Queue()
{
	// nothing is dynamically allocated
}

/**********************************************************************
* Purpose:	Adds T toadd to end of queue
* Entry:	T toadd
* Exit:		toadd is added to end of queue
************************************************************************/
template <typename T>
void Queue<T>::Enqueue(T toadd)
{
	if (isFull())
		throw Exception("ERROR: Cannot add an item to a full Queue");
	else
	{
		if (m_tail == (m_size - 1))
			m_tail = 0;
		else
			++m_tail;

		m_array[m_tail] = toadd;
		++m_items;
	}
}

/**********************************************************************
* Purpose:	pops head from queue
* Entry:	None.
* Exit:		T head is returned
************************************************************************/
template <typename T>
T Queue<T>::Dequeue()
{
	int temp(0);
	if (isEmpty())
		throw Exception("ERROR: Cannot remove item from empty Queue");
	else
	{
		temp = m_array[m_head];

		if (m_head == m_size - 1)
			m_head = 0;
		else
			++m_head;

		--m_items;
	}
	return temp;
}

/**********************************************************************
* Purpose:	head of queue is accessed by reference so that it can be
*			changed.
* Entry:	None.
* Exit:		Head is returned by reference so that it can be changed
************************************************************************/
template <typename T>
T& Queue<T>::Front()
{
	return m_array[m_head];
}

/**********************************************************************
* Purpose:	returns number of items
* Entry:	None.
* Exit:		number of items is returned
************************************************************************/
template <typename T>
int Queue<T>::Size()
{
	return m_items;
}

/**********************************************************************
* Purpose:	returns true if empty, false otherwise
* Entry:	None.
* Exit:		True or False
************************************************************************/
template <typename T>
bool Queue<T>::isEmpty()
{
	return (m_items == 0);
}

/**********************************************************************
* Purpose:	true when full, false otherwise
* Entry:	None.
* Exit:		True or False
************************************************************************/
template <typename T>
bool Queue<T>::isFull()
{
	return (m_items == m_size);
}

#endif
