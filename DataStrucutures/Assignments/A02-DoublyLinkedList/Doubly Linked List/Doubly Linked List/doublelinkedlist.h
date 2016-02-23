/***********************************************************
* Class:		DoubleLinkedList
*
* Managers:
* 	DoubleLinkedList()
* 		Default constructor
*	DoubleLinkedList(const DoubleLinkedList & copy)
* 		Copy Ctor
*	~DoubleLinkedList()
*		Destructor
* 	void operator=(const DoubleLinkedList & rhs)
*		Overload the = operator
*
* Public Methods:
*	void SetHead(Node<T> * head);
*		Set head of linked list
*	void SetTail(Node<T> * tail);
*		Set tail of linked list
*
*	Node<T> * GetHead() const;
*		Get head of linked list
*	Node<T> * GetTail() const;
*		Get tail of linked list
*
*	bool isEmpty();
*		returns true if the linked list is empty
*	const T & First();
*		Returns a const ref to the data in the head node
*	const T & Last();
*		Returns a const ref to the data in the tail node
*	void Prepend(T data);
*		Insert a node before head
*	void Append(T data);
*		Insert a node after tail
*	void Purge();
*		Removes all items from list
*	void Extract(T data);
*		Removes one item from linked list
*	void InsertBefore(T add, T find);
*		Inserts a node created with add before the passed in
*		find
*	void InsertAfter(T add, T find);
*		Inserts a node created with add after the passed in
*		find
*	Node<T> * Search(T data)
*		Returns pointer to found data
************************************************************/
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "Node.h"
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList<T> & copy);
	~DoubleLinkedList();

	DoubleLinkedList<T>& operator=(const DoubleLinkedList<T> & rhs);

	Node<T> * getHead() const;
	Node<T> * getTail() const;

	bool isEmpty() const;
	T & First() const;
	T & Last() const;
	void Prepend(T data);
	void Append(T data);
	void Purge();
	void Extract(T data);
	void InsertBefore(T add, T find);
	void InsertAfter(T add, T find);
	void PrintForwards() const;
	void PrintBackwards() const;

	Node<T> * Search(T data);

private:
	Node<T> * m_head;
	Node<T> * m_tail;
};
/**************************************************************
*	Purpose: 	Creates new instance of doublelinkedlist
*	Entry:		None
*	Exit:		All data members set to zero or nullptr
****************************************************************/
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : m_head(nullptr), m_tail(nullptr)
{}

/**************************************************************
*	Purpose:	Copy Ctor
*	Entry:		data member to be copied
*	Exit:		this is equal to copy
****************************************************************/
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T> & copy) : m_head(nullptr), m_tail(nullptr)
{
	*this = copy;
}

/**************************************************************
*	Purpose:	Dtor
*	Entry:		None
*	Exit:		Memory deallocated, members set back to zero
*				or nullptr
****************************************************************/
template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	Purge();
}

/**************************************************************
*	Purpose:	op equals
*	Entry:		DoubleLinkedList rhs
*	Exit:		this is equal to rhs
****************************************************************/
template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList<T> & rhs)
{
	// even if rhs is empty,  nullptr
	Node<T> * travel = rhs.m_head;

	if (this != &rhs)
	{
		// first populate the list
		while (travel != nullptr)
		{
			Append(travel->m_data);
			travel = travel->m_next;
		}
	}
	return *this;
}

/**********************************************************************
* Purpose:	Returns list head pointer
* Entry:	none
* Exit:		m_head
************************************************************************/
template <typename T>
Node<T> * DoubleLinkedList<T>::getHead() const
{
	return m_head;
}

/**********************************************************************
* Purpose:	Returns list tail pointer
* Entry:	none
* Exit:		m_tail
************************************************************************/
template <typename T>
Node<T> * DoubleLinkedList<T>::getTail() const
{
	return m_tail;
}

/**********************************************************************
* Purpose:	Checks if the list is empty by comparing m_head to nullptr
* Entry:	none
* Exit:		true if m_head is nullptr, false if it is anything else
************************************************************************/
template <typename T>
bool DoubleLinkedList<T>::isEmpty() const
{
	return (m_head == nullptr);
}

/**********************************************************************
* Purpose:	Returns the data from the first node by reference
* Entry:	None
* Exit:		Data from head node
************************************************************************/
template <typename T>
T & DoubleLinkedList<T>::First() const
{
	if (m_head == nullptr)
		throw "List is empty from First().";

	return m_head->m_data;
}

/**********************************************************************
* Purpose:	Returns the data from tail node by reference
* Entry:	None
* Exit:		Data from tail node
************************************************************************/
template <typename T>
T & DoubleLinkedList<T>::Last() const
{
	if (m_head == nullptr)
		throw "List is empty from Last().";

	return m_tail->m_data;
}

/**********************************************************************
* Purpose:	Adds node before head (if head already exists), sets
*			new node to head.
* Entry:	T data to create a new node
* Exit:		New node set to head
************************************************************************/
template <typename T>
void DoubleLinkedList<T>::Prepend(T data)
{
	Node<T> * new_node = new Node < T >(data);

	if (m_head == nullptr)
		m_head = m_tail = new_node;
	else
	{
		m_head->m_prev = new_node;
		new_node->m_next = m_head;
	}
	m_head = new_node;
}

/**********************************************************************
* Purpose:	Adds a new node to the end of the linked list
* Entry:	T data for node
* Exit:		new node containing data is set to tail
************************************************************************/
template <typename T>
void DoubleLinkedList<T>::Append(T data)
{
	Node<T> * new_node = new Node<T>(data);

	if (m_head == nullptr)
		m_head = m_tail = new_node;
	else
	{
		m_tail->m_next = new_node;
		new_node->m_prev = m_tail;
		m_tail = new_node;
	}
}

/**********************************************************************
* Purpose:	Deletes everything in the doubly linked list
* Entry:	None
* Exit:		Linked list is empty
************************************************************************/
template <typename T>
void DoubleLinkedList<T>::Purge()
{
	Node<T> * trail = m_head;

	while (m_head != nullptr)
	{
		trail = m_head;
		m_head = m_head->m_next;
		delete trail;
	}
	m_head = m_tail = nullptr;
}

/**********************************************************************
* Purpose:	Finds node with same data (assumes only one data exists)
* Entry:	T data used to search and delete node
* Exit:		if found, node with matching data is deleted, else
*			error message is thrown
************************************************************************/
template <typename T>
void DoubleLinkedList<T>::Extract(T data)
{
	Node<T> * to_delete = Search(data);

	if (to_delete != nullptr)
	{
		// one item in list
		if (to_delete == m_head && to_delete == m_tail)
		{
			// set next, prev, head and tail
			to_delete->m_next = to_delete->m_prev = nullptr;
			m_head = m_tail = nullptr;
		}
		// first node in list
		else if (to_delete == m_head)
		{
			// set next
			m_head->m_next->m_prev = nullptr;
			m_head = m_head->m_next;
		}
		else if (to_delete == m_tail)
		{
			// set prev
			m_tail->m_prev->m_next = nullptr;
			m_tail = m_tail->m_prev;
		}
		else
		{
			// the previous node's next is set to trail's next
			to_delete->m_prev->m_next = to_delete->m_next;

			// the next node's previous is set to trail's previous
			to_delete->m_next->m_prev = to_delete->m_prev;
		}
		delete to_delete;
	}
	else
		throw "Data is not in list.";
}

/**********************************************************************
* Purpose:	Place new node "add" before "find" node
* Entry:	T add (to create new node) and T find
* Exit:		Node containing add is inserted before node containing find
************************************************************************/
template <typename T>
void DoubleLinkedList<T>::InsertBefore(T add, T find)
{
	Node<T> * found = Search(find);

	if (found)
	{
		if (found == m_head)
			Prepend(add);
		else
		{
			Node<T> * to_add = new Node<T>(add);
			// assign proper pointers for to_add
			to_add->m_prev = found->m_prev; // if head, just null
			to_add->m_next = found;

			// assign the previous node's next pointer
			// to to_add
			found->m_prev->m_next = to_add;
			found->m_prev = to_add;
		}
	}
	else
		throw "Data is not in list.";
}

/**********************************************************************
* Purpose:	Insert a node containing "add" after node containing find
* Entry:	T add, T find
* Exit:		node containing add is inserted after find
************************************************************************/
template <typename T>
void DoubleLinkedList<T>::InsertAfter(T add, T find)
{
	Node<T> * found = Search(find);

	if (found)
	{
		if (found == m_tail)
			Append(add);
		else
		{
			Node<T> * to_add = new Node<T>(add);

			// assign proper pointers for to_add
			to_add->m_prev = found;
			to_add->m_next = found->m_next;

			// assign the next node's previous pointer
			// to to_add
			found->m_next->m_prev = to_add;

			// assign the previous node's next pointer
			// to to_add
			found->m_next = to_add;
		}
	}
	else
		throw "Data is not in list.";
}

/**********************************************************************
* Purpose:	Prints nodes from head to tail
* Entry:	None
* Exit:		Data from each node is printed on the same line
************************************************************************/
template <typename T>
void DoubleLinkedList<T>::PrintForwards() const
{
	Node<T> * travel = m_head;

	cout << endl;

	while (travel != nullptr)
	{
		cout << travel->m_data << " ";
		travel = travel->m_next;
	}
	cout << endl;
}

/**********************************************************************
* Purpose:	Prints nodes from tail to head
* Entry:	None.
* Exit:		Data from each node in list is printed on the same line
************************************************************************/
template <typename T>
void DoubleLinkedList<T>::PrintBackwards() const
{
	Node<T> * travel = m_tail;

	cout << endl;

	while (travel != nullptr)
	{
		cout << travel->m_data << " ";
		travel = travel->m_prev; // go backwards
	}
	cout << endl;
}

/**********************************************************************
* Purpose:	Goes through list to find data in node
* Entry:	T data to compare/find
* Exit:		Pointer to the node that contains the data
************************************************************************/
template <typename T>
Node<T> * DoubleLinkedList<T>::Search(T data)
{
	bool found = false;
	Node<T>*travel = m_head;
	Node<T>*trail = travel;

	Node<T> * found_node = nullptr;

	if (m_head == nullptr)
		throw "List is empty";

	// while within list and not found
	while (travel != nullptr && !found)
	{
		// when data matches, found :D
		if (travel->m_data == data)
		{
			found = true;
			found_node = travel;
		}
		trail = travel;				// set trail to travel
		travel = travel->m_next;	// then travel to next
	}
	return found_node;
}

#endif