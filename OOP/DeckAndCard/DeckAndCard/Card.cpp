/******************************************************
*	Author:			Lydia Doza
*	Date created:	2/16/2015
*	Date modified:	2/18/2015
*	Title:			Card.cpp
******************************************************/
#include "Card.h"

/**************************************************************
*	Purpose:
*		Sets values in card to be rank of suit.
*	Entry:
*		None.
*	Exit:
*		None.
****************************************************************/
Card::Card(Rank rank, Suit suit) : m_rank(rank), m_suit(suit)
{ }

/**************************************************************
*	Purpose:
*		Resets card to ace of spades
*	Entry:
*		None.
*	Exit:
*		None.
****************************************************************/
Card::~Card()
{
	m_rank = ACE;
	m_suit = SPADE;
}

/**************************************************************
*	Purpose:
*		Sets values in card to values of copy
*	Entry:
*		None.
*	Exit:
*		None.
****************************************************************/
Card::Card(const Card & copy) : m_rank(copy.m_rank), m_suit(copy.m_suit)
{}

/**************************************************************
*	Purpose:
*		Displays card rand and suit
*	Entry:
*		None.
*	Exit:
*		None.
****************************************************************/
void Card::Display() const
{
	const char * rank_txt[] = { "Ace", "Deuce", "Trey", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	cout << setw(10) << rank_txt[m_rank - 1] << " of " << static_cast<char>(m_suit);
}

/**************************************************************
*	Purpose:
*		Sets rank to user specs
*	Entry:
*		None.
*	Exit:
*		None.
****************************************************************/
void Card::SetRank(Rank rank)
{
	m_rank = rank;
}

/**************************************************************
*	Purpose:
*		Sets m_suit to suit.
*	Entry:
*		suit.
*	Exit:
*		m_suit changed to suit.
****************************************************************/
void Card::SetSuit(Suit suit)
{
	m_suit = suit;
}

/**************************************************************
*	Purpose:
*		Allows access to m_rank.
*	Entry:
*		None.
*	Exit:
*		m_rank.
****************************************************************/
Card::Rank Card::GetRank() const
{
	return m_rank;
}

/**************************************************************
*	Purpose:
*		Gets access to m_suit
*	Entry:
*		None.
*	Exit:
*		m_suit
****************************************************************/
Card::Suit Card::GetSuit() const
{
	return m_suit;
}

/**************************************************************
*	Purpose:
*		Sets *this to card
*	Entry:
*		None.
*	Exit:
*		m_suit
****************************************************************/
Card& Card::operator=(const Card & rhs)
{
	if (this != &rhs)
	{
		m_rank = rhs.m_rank;
		m_suit = rhs.m_suit;
	}

	return *this;
}

/**************************************************************
*	Purpose:
*		checks if *this is equal to input card
*	Entry:
*		None.
*	Exit:
*		None.
****************************************************************/
bool Card::operator==(Card & card)
{
	return (m_suit == card.m_suit && m_rank == card.m_rank);
}