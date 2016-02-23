/************************************************************************
*						Never gonna make you cry
* Class: LinkedList
*
* Constructors:
*	LinkedList()
*	~LinkedList()
*		Deallocates memory from node and player
* Public Methods:
*	void Add()
*		Adds a new node to linked list ordered by grade
*	void DisplayNodes() const
*		Displays all nodes in linked list
*	CardNode * Search(String name) const
*		Searches all nodes for desired player name, returns a pointer to
*		that node
*	void Delete(String name)
*		deletes node from linked list.
*	int GetNumNodes() const
*		returns m_num_nodes
*************************************************************************/
#ifndef LINKED_H
#define LINKED_H
#include "CardNode.h"
#include "Deck.h"
#include "Card.h"
class Linked
{
public:
	Linked();
	Linked(const Linked & linked);
	~Linked();

	Linked& operator = (const Linked & linked);

	void Add(Card card);
	void DisplayNodes() const;
	void DisplayFirstNode() const;
	int GetNumNodes() const;
	void DeleteAllNodes();

	Card GetCard(int index);

private:
	CardNode * m_head;
	int m_num_nodes;
};

#endif