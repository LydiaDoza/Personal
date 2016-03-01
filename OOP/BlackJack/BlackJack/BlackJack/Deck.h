/************************************************************************
*				A full commitment's what I'm thinking of
* Class: Deck
*
* Constructors:
*	Deck()
*		ctor. Makes an instance of Deck
*	Deck(const Deck & deck)
*		copy ctor
*
* Destructors:
*	~Deck()
*		dtor. deallocates dynamically allocated memory.
*
* Public Methods:
*	void Shuffle()
*		Shuffles order of cards.
*	Card Deal()
*		Deals card. increments m_current_card.
*	int GetCardsDealt() const
*		returns m_current_card.
*
*************************************************************************/
#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "Random.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <stdlib.h>
#include <ctime>

class Deck
{
public:
	Deck();
	Deck(const Deck & deck);
	~Deck();
	void Shuffle();
	Card & Deal();

	int GetCardsDealt() const;

	void DisplayAll();


private:
	static const int MAXCARDS = 52;

	Card * m_deck[MAXCARDS];

	Random rand;
	int m_current_card;
};

#endif 