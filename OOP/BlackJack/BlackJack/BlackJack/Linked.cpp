/**************************************************************
*				Never gonna say goodbye
****************************************************************/
#include "Node.h"
#include "Player.h"
#include "Linked.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/***************************************************************
*	Name:
*		Linked()
*
*	Purpose:
*		m_head and m_num_nodes are set to nullptr and zero
*
*	Entry:
*		nothing
*
*	Exit:
*		Linked instance created
****************************************************************/
Linked::Linked() : m_head(nullptr), m_num_nodes(0)
{
}

/***************************************************************
*	Name:
*		~Linked()
*
*	Purpose:
*		m_head and m_num_nodes are set to default null and zero
*
*	Entry:
*		nothing
*
*	Exit:
*		memory deallocated
****************************************************************/
Linked::~Linked()
{
	Node * travel = m_head;
	Node * trail = travel;

	while (travel != nullptr)
	{
		travel = travel->GetNext();
		delete trail;
		trail = travel;
	}

	m_head = nullptr;
	m_num_nodes = 0;
}

/***************************************************************
*	Name:
*		operator=(const Linked & linked)
*
*	Purpose:
*		Sets this to linked.
*
*	Entry:
*		nothing
*
*	Exit:
*		None.
****************************************************************/
Linked& Linked::operator=(const Linked& linked)
{
	Node * travel_list = linked.m_head;

	if (this != &linked)
	{
		// Delete everything in current list
		DeleteAllNodes();

		// Go through linked list and make copies
		while (travel_list != nullptr)
		{
			// add a new node to current list
			Add(travel_list->GetCard());

			// set travel to next
			travel_list = travel_list->GetNext();
		}
	}

	return *this;
}

/***************************************************************
*	Name:
*		Linked(const Linked & linked)
*
*	Purpose:
*		Sets this to linked.
*
*	Entry:
*		nothing
*
*	Exit:
*		None.
****************************************************************/
Linked::Linked(const Linked & linked)
{
	this->operator=(linked); // :D
}

/***************************************************************
*	Name:
*		Add()
*
*	Purpose:
*		Creates new node to add to an ordered (by grade)
*		Linked list.
*
*	Entry:
*		None.
*
*	Exit:
*		New node created and added list.
****************************************************************/
void Linked::Add(Card card)
{
	Node * travel = m_head;

	Node * new_node = new Node;

	// ADD A CARD TO NEW NODE
	new_node->SetCard(card);

	//list is empty
	if (m_head == nullptr)
	{
		m_head = new_node;
		new_node->SetNext(nullptr);
	}

	//append node to end of list
	else
	{
		while (travel->GetNext() != nullptr)
		{
			travel = travel->GetNext();
			//set travel to next
		}

		//set travel's next to new node
		travel->SetNext(new_node);
		new_node->SetNext(nullptr);
	}
	++m_num_nodes;
}

/***************************************************************
*	Name:
*		DisplayNodes()
*
*	Purpose:
*		Lists all nodes in Linked list.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Linked::DisplayNodes() const
{
	Node * travel = m_head;

	while (travel != nullptr)
	{
		// display this node.
		travel->GetCard().Display();

		//get next node
		travel = travel->GetNext();
	}
}

/**************************************************************
*	Name:
*		DisplayFirstNode() const
*
*	Purpose:
*		Displays the first node in list.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Linked::DisplayFirstNode() const
{
	if (m_head != nullptr)
		m_head->GetCard().Display();
	else
		cout << "\n\tThere are no cards to display.\n";
}

/***************************************************************
*	Name:
*		DeleteAllNodes()
*
*	Purpose:
*		Finds and deletes node if found, if not found, error
*		message is displayed
*
*	Entry:
*		None.
*
*	Exit:
*		Number of nodes is returned.
****************************************************************/
void Linked::DeleteAllNodes()
{
	//set travel and trail to m_head
	Node * travel = m_head;
	Node * trail = travel;

	//list is not empty
	while (travel != nullptr)
	{
		//change travel to next
		travel = travel->GetNext();

		delete trail;
		//change trail to travel again
		trail = travel;
	}
	//reset number of nodes to zero.
	m_num_nodes = 0;
	m_head = nullptr;
}

/***************************************************************
*	Name:
*		GetNumNodes()
*
*	Purpose:
*		Returns number of nodes in list.
*
*	Entry:
*		None.
*
*	Exit:
*		Number of nodes is returned.
****************************************************************/
int Linked::GetNumNodes() const
{
	return m_num_nodes;
}

/***************************************************************
*	Name:
*		GetCard()
*
*	Purpose:
*		Returns the card data
*
*	Entry:
*		None.
*
*	Exit:
*		Number of nodes is returned.
****************************************************************/
Card Linked::GetCard(int index)
{
	Node * travel = m_head;

	//make sure that index is within bounds of linked list
	if (index >= 0 && index < m_num_nodes)
	{
		for (int i = 0; i < index; i++)
		{
			travel = travel->GetNext();
		}
	}

	return travel->GetCard();
}