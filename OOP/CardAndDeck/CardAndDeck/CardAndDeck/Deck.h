/************************************************************************
* Class: Deck
*
* Constructors:
*	Deck()
*		ctor. Makes an instance of Deck
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
	~Deck();
	void Shuffle();
	const Card & Deal();

	int GetCardsDealt() const;

	void DisplayAll();


	static int GetCount();

private:
	static const int MAXCARDS = 52;
	static void IncCount();

	Card * m_deck[MAXCARDS];

	Random rand;
	int m_current_card;
	static int m_count;
};

#endif 