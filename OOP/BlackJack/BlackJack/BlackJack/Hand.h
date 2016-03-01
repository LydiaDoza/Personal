/************************************************************************
*					Never gonna tell a lie and hurt you
* Class: Hand
*
* Constructors:
*	Hand()
*		sets m_face_value to 0
*	Hand(const Hand & hand)
*		sets this to hand
*
* Destructors:
*	~Hand()
*		Resets m_face_value to 0
*
* Public methods are commented below.
*************************************************************************/
#ifndef HAND_H
#define HAND_H

#include "Linked.h"
#include "Card.h"

class Hand
{
public:
	Hand();
	~Hand();
	Hand(const Hand & hand);

	int GetFaceValue();		//returns sum of face values of cards
	void DisplayCards();	//displays all cards in hand

	void DisplayFirstCard() const;	//displays first card in hand

	void Add(Card card); // adds a card to hand
	void RemoveAll();	//removes all cards in hand

	int GetCardCount();	//returns number of cards in hand

private:
	Linked m_cards;		// hand of cards
	int m_face_value;	// sum of face values
};

#endif