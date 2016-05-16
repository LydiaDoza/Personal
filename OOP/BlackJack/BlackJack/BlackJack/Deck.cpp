/**************************************************************
*		You wouldn't get this from any other guy
****************************************************************/

/******************************************************
*	Author:			Lydia Doza
*	Date created:	2/20/2015
*	Date modified:	3/4/2015
*	Title:			Deck.cpp
******************************************************/
#include "Deck.h"
/**************************************************************
*	Name:
*		Deck()
*	Purpose:
*		Creates a deck full of cards in order
*	Entry:
*		None.
*	Exit:
*		None.
****************************************************************/
Deck::Deck() : m_current_card(0)
{
	for (int suit = 0; suit < 4; suit++)
		for (int rank = 0; rank < 13; rank++) // rank goes to 13 (King)
			m_deck[suit * 13 + rank] = new Card(static_cast<Card::Rank>(rank + 1), static_cast<Card::Suit>(suit + 3));
}
/**************************************************************
*	Name:
*		Deck(const Deck & deck)
*	Purpose:
*		copy ctor
*	Entry:
*		None.
*	Exit:
*		None.
****************************************************************/
Deck::Deck(const Deck & deck)
{
	for (int i = 0; i < MAXCARDS; i++)
	{
		m_deck[i] = deck.m_deck[i];
	}

	m_current_card = 0;
}

/**************************************************************
*	Name:
*		~Deck()
*	Purpose:
*		Deallocates memory
*	Entry:
*		None.
*	Exit:
*		None.
****************************************************************/
Deck::~Deck()
{
	for (int i = 0; i < MAXCARDS; i++)
		delete m_deck[i];
}

/**************************************************************
*	Name:
*		Shuffle()
*	Purpose:
*		Randomizes/shuffles Deck. Cards will no longer be in
*		order. Yay.
*	Entry:
*		None.
*	Exit:
*		None
****************************************************************/
void Deck::Shuffle()
{
	Card * temp = nullptr;
	m_current_card = 0; // set card to top of deck
	int number = 0;

	//	srand( static_cast<unsigned>(time( 0 )) );

	for (int i = 0; i < 4; i++) // for superior shuffling
	{
		for (int cur = 0; cur < MAXCARDS; cur++)
		{
			number = this->rand.GetRandom(52);
			temp = m_deck[cur];
			m_deck[cur] = m_deck[number];
			m_deck[number] = temp;
		}
	}
	// cout << "\nEveryday I'm Shuffling.\n\n";
}

/**************************************************************
*	Name:
*		Deal()
*	Purpose:
*		Returns current card then increments the card location
*		for next card.
*	Entry:
*		None.
*	Exit:
*		None.
****************************************************************/
Card& Deck::Deal()
{
	if (m_current_card >= MAXCARDS) // is card not in deck?
	{
		Shuffle();
	}

	return *m_deck[m_current_card++];	// returns current card, increments 
	// current card for next card
}

/**************************************************************
*	Name:
*		GetCardsDealt()
*	Purpose:
*		Returns current card then increments the card location
*		for next card.
*	Entry:
*		None.
*	Exit:
*		None.
****************************************************************/
int Deck::GetCardsDealt() const
{
	return m_current_card;
}

/**************************************************************
*	Name:
*		DisplayAll()
*	Purpose:
*		Returns current card then increments the card location
*		for next card.
*	Entry:
*		None.
*	Exit:
*		None.
****************************************************************/
void Deck::DisplayAll()
{
	for (int i = 0; i < 52; i++)
	{
		m_deck[i]->Display();
	}
}
