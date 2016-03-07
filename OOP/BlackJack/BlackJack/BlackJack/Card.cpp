/**************************************************************
*			We know the game and we're gonna play it
****************************************************************/

/******************************************************
*	Author:			Lydia Doza
*	Date created:	2/16/2015
*	Date modified:	2/18/2015
*	Title:			Card.cpp
******************************************************/
#include "Card.h"

/**************************************************************
*	Name:
*		Card(Rank rank, Suit suit)
*
*	Purpose:
*		Sets values in card to be rank of suit.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Card::Card(Rank rank, Suit suit) : m_rank(rank), m_suit(suit)
{

}

/**************************************************************
*	Name:
*		~Card()
*
*	Purpose:
*		Resets card to ace of spades
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Card::~Card()
{
	m_rank = ACE;
	m_suit = SPADE;
}

/**************************************************************
*	Name:
*		Card(const Card & copy)
*
*	Purpose:
*		Sets values in card to values of copy
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Card::Card(const Card & copy) : m_rank(copy.m_rank), m_suit(copy.m_suit)
{

}

/**************************************************************
*	Name:
*		Display()
*
*	Purpose:
*		Displays card rand and suit
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Card::Display() const
{
	const char * rank_txt[] = { "Ace", "Deuce", "Trey", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	cout <<  rank_txt[m_rank - 1] << " of " << static_cast<char>(m_suit) << endl;
}

/**************************************************************
*	Name:
*		SetRank(Rank rank)
*
*	Purpose:
*		Sets rank to user specs
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Card::SetRank(Rank rank)
{
	m_rank = rank;
}

/**************************************************************
*	Name:
*		SetSuit(Suit suit)
*
*	Purpose:
*		Sets m_suit to suit.
*
*	Entry:
*		suit.
*
*	Exit:
*		m_suit changed to suit.
****************************************************************/
void Card::SetSuit(Suit suit)
{
	m_suit = suit;
}

/**************************************************************
*	Name:
*		GetRank()
*
*	Purpose:
*		Allows access to m_rank.
*
*	Entry:
*		None.
*
*	Exit:
*		m_rank.
****************************************************************/
Card::Rank Card::GetRank() const
{
	return m_rank;
}

/**************************************************************
*	Name:
*		GetSuit()
*
*	Purpose:
*		Gets access to m_suit
*
*	Entry:
*		None.
*
*	Exit:
*		m_suit
****************************************************************/
Card::Suit Card::GetSuit() const
{
	return m_suit;
}

/**************************************************************
*	Name:
*		operator=()
*
*	Purpose:
*		Sets *this to card
*
*	Entry:
*		None.
*
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
*	Name:
*		operator==()
*
*	Purpose:
*		checks if *this is equal to input card
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
bool Card::operator==(Card & card)
{
	return (m_suit == card.m_suit && m_rank == card.m_rank);
}