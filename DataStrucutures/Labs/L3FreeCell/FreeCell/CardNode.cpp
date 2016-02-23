#include "CardNode.h"
#include "Card.h"

/***************************************************************
* Purpose:	m_next set to null ptr and m_card default ctor
* Entry:	None.
* Exit:		None.
****************************************************************/
CardNode::CardNode() : m_next(nullptr), m_card()
{}

/***************************************************************
* Purpose:	m_next set to null ptr and m_card set to input card
* Entry:	None.
* Exit:		None.
****************************************************************/
CardNode::CardNode(Card card) : m_next(nullptr)
{
	m_card.SetRank(card.GetRank());
	m_card.SetSuit(card.GetSuit());
}

/***************************************************************
* Purpose:	m_next set to nullptr and m_card is set to default 
*			ace of spades
* Entry:	None.
* Exit:		None.
****************************************************************/
CardNode::~CardNode()
{
	m_next = nullptr;
	m_card.SetRank(Card::ACE);
	m_card.SetSuit(Card::SPADE);
}

/***************************************************************
* Purpose:	Sets m_next to input next.
* Entry:	CardNode pointer
* Exit:		m_next is set.
****************************************************************/
void CardNode::SetNext(CardNode * next)
{   m_next = next;   }

/***************************************************************
* Purpose:	Returns next pointer
* Entry:	None.
* Exit:		next pointer returned.
****************************************************************/
CardNode * CardNode::GetNext()
{	return m_next;   }

/***************************************************************
* Purpose:	m_player is set to player
* Entry:	None.
* Exit:		None.
****************************************************************/
void CardNode::SetCard(Card card)
{
	m_card.SetRank(card.GetRank());
	m_card.SetSuit(card.GetSuit());
}

/***************************************************************
* Purpose:	sets *this to incoming node data
* Entry:	None.
* Exit:		None.
****************************************************************/
CardNode& CardNode::operator = (const CardNode& node)
{
	if (this != &node)
	{
		m_next = nullptr;
		m_card.SetRank(node.GetCard().GetRank());
		m_card.SetSuit(node.GetCard().GetSuit());
	}
	return *this;
}

/***************************************************************
* Purpose:	Returns m_card
* Entry:	None.
* Exit:		None.
****************************************************************/
Card CardNode::GetCard() const
{	return m_card;   }

/***************************************************************
* Purpose:	Returns rank of card
* Entry:	None.
* Exit:		None.
****************************************************************/
Card::Rank CardNode::GetRank()
{	return m_card.GetRank();   }