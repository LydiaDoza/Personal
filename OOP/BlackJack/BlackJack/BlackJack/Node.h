/************************************************************************
*					Your heart's been aching, but
* Class: Node
*
* Constructors:
*	Node()
*		m_next is set to nullptr and m_player has name set to \0, 0, 0
*	Node(Player player)
*		m_next is set to nullptr and m_player is set to player data
*
* Destructor:
*	~Node()
*
* Operator:
*	void operator=(const Node& node)
*		overloads assignment operator so that this* can be set
*
* Public Methods:
*	void SetNext(Node * next)
*		sets next node*

*	Node * GetNext()
*		returns node* to next node in list
*		
*	void SetPlayer(Player player)
*		sets m_player to player
*
*	void SetPlayer(String name, int grade, double gpa)
*		sets m_player.name to name, m_player.grade to grade, and m_gpa to
*		gpa.
*
*	Player GetPlayer() const
*		returns m_player
*************************************************************************/
#ifndef NODE_H
#define NODE_H
#include "Card.h"
class Node
{
public:
	Node();
	Node(Card card);
	~Node();
	Node& operator = (const Node& node);

	void SetNext(Node * next);
	Node * GetNext();

	void SetCard(Card card);

	Card GetCard() const;
	Card::Rank GetRank();

private:
	Node * m_next;

	Card m_card;
};
#endif