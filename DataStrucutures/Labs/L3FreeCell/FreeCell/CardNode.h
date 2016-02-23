/************************************************************************
* Class: CardNode
*
*	CardNode()
*		m_next is set to nullptr and m_player has name set to \0, 0, 0
*	CardNode(Player player)
*		m_next is set to nullptr and m_player is set to player data
*	~CardNode()
*		DTOR
*	void operator=(const CardNode& node)
*		overloads assignment operator so that this* can be set
*
* Public Methods:
*	void SetNext(CardNode * next)
*		sets next node
*	CardNode * GetNext()
*		returns node* to next node in list
*	void SetPlayer(Player player)
*		sets m_player to player
*	void SetPlayer(String name, int grade, double gpa)
*		sets m_player.name to name, m_player.grade to grade, and m_gpa to
*		gpa.
*	Player GetPlayer() const
*		returns m_player
*************************************************************************/
#ifndef CARDNODE_H
#define CARDNODE_H
#include "Card.h"
class CardNode
{
public:
	CardNode();
	CardNode(Card card);
	~CardNode();
	CardNode& operator = (const CardNode& node);

	void SetNext(CardNode * next);
	CardNode * GetNext();

	void SetCard(Card card);

	Card GetCard() const;
	Card::Rank GetRank();

private:
	CardNode * m_next;
	Card m_card;
};
#endif