/**************************************************************
*			        You're too shy to say it
****************************************************************/
#include "Node.h"
#include "Card.h"

/***************************************************************
*	Name:
*		Node()
*
*	Purpose:
*		m_next set to null ptr and m_card default ctor
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Node::Node() : m_next(nullptr), m_card()
{

}

/***************************************************************
*	Name:
*		Search(Card card)
*
*	Purpose:
*		m_next set to null ptr and m_card set to input card
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Node::Node(Card card) : m_next(nullptr)
{
	m_card.SetRank(card.GetRank());
	m_card.SetSuit(card.GetSuit());
}

/***************************************************************
*	Name:
*		~Node()
*
*	Purpose:
*		m_next set to nullptr and m_card is set to default 
*		ace of spades
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Node::~Node()
{
	m_next = nullptr;
	m_card.SetRank(Card::ACE);
	m_card.SetSuit(Card::SPADE);
}

/***************************************************************
*	Name:
*		SetNext(Node * next)
*
*	Purpose:
*		Sets m_next to input next.
*
*	Entry:
*		Node pointer
*
*	Exit:
*		m_next is set.
****************************************************************/
void Node::SetNext(Node * next)
{
	m_next = next;
}

/***************************************************************
*	Name:
*		GetNext()
*
*	Purpose:
*		Returns next pointer
*
*	Entry:
*		None.
*
*	Exit:
*		next pointer returned.
****************************************************************/
Node * Node::GetNext()
{
	return m_next;
}

/***************************************************************
*	Name:
*		SetPlayer(Player player)
*
*	Purpose:
*		m_player is set to player
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Node::SetCard(Card card)
{
	m_card.SetRank(card.GetRank());
	m_card.SetSuit(card.GetSuit());
}

/***************************************************************
*	Name:
*		operator = (const Node& node)
*
*	Purpose:
*		sets *this to incoming node data
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Node& Node::operator = (const Node& node)
{
	if (this != &node)
	{
		m_next = nullptr;
		m_card.SetRank(node.GetCard().GetRank());
		m_card.SetSuit(node.GetCard().GetSuit());
	}
	return *this;
}

Card Node::GetCard() const
{
	return m_card;
}

/***************************************************************
*	Name:
*		GetRank()
*
*	Purpose:
*		Returns rank of card
*
*	Entry:	
*		None.
*
*	Exit:
*		None.
****************************************************************/
Card::Rank Node::GetRank()
{
	return m_card.GetRank();
}