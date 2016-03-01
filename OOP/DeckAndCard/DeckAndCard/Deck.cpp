/******************************************************
*	Author:			Lydia Doza
*	Date created:	2/16/2015
*	Date modified:	2/18`/2015
*	Title:			Deck.cpp
******************************************************/
#include "Deck.h"
int Deck::m_count(0);
/**************************************************************
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
	{
		for (int rank = 0; rank < 13; rank++) // rank goes to 13 (King)
		{
			m_deck[suit * 13 + rank] = 
				new Card(static_cast<Card::Rank>(rank + 1), static_cast<Card::Suit>(suit + 3));
		}
	}
}

/**************************************************************
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
	m_current_card = 0;
	int number;


	//	srand( static_cast<unsigned>(time( 0 )) );

	for (int i = 0; i < 3; i++) // for superior shuffling
	{
		for (int cur = 0; cur < MAXCARDS; cur++)
		{
			number = this->rand.GetRandom(52);
			temp = m_deck[cur];
			m_deck[cur] = m_deck[number];
			m_deck[number] = temp;
		}
	}
	cout << "\nEveryday I'm Shuffling.\n\n";
}

/**************************************************************
*	Purpose:
*		Returns current card then increments the card location
*		for next card.
*	Entry:
*		None.
*	Exit:
*		None.
****************************************************************/
const Card& Deck::Deal()
{
	if (m_current_card >= MAXCARDS) // is card not in deck?
	{
		Shuffle();
	}

	IncCount();

	return *m_deck[m_current_card++];	// returns current card, increments 
										// current card for next card
}

/**************************************************************
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
	for (int row = 0; row < 13; row++)
	{
		for (int col = 0; col < 4; col++) // rank goes to 13 (King)
		{
			m_deck[row * 4 + col]->Display();
			IncCount();
		}
		cout << endl;
	}
}

/**************************************************************
*	Purpose:
*		Increments count.
*	Entry:
*		None.
*	Exit:
*		None.
****************************************************************/
void Deck::IncCount()
{
	++m_count;
}

/**************************************************************
*	Purpose:
*		returns count.
*	Entry:
*		None.
*	Exit:
*		None.
****************************************************************/
int Deck::GetCount()
{
	return m_count;
}