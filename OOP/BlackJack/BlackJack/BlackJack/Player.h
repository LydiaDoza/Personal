/************************************************************************
*                I just want to tell you how I'm feeling
* Class: Player
*
* Constructors:
*	Player()
*		calls default ctors for m_hand and m_purse
*	Plyaer(int bankroll)
*		calls default ctor for m_hand and sets m_purse to bankroll
*
* Destructors:
*	~Player()
*		calls dtors for m_hand and m_purse
*
* Public methods are commented below.
*************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Bankroll.h"

class Player
{
public:
	Player();
	Player(int money);
	~Player();

	void SetPurse(int money);		// sets purse to money
	int GetPurse() const;			// gets money from purse
	void AddToPurse(int money);		// adds money to purse
	void SubFromPurse(int money);	// subtracts money from purse

	void DisplayCards();			// displays all cards

	void AddCard(Card card);		// adds card to hand
	void DeleteCards();				// deletes all cards in hand

	int GetHandValue();				// returns hand value

protected:
	Hand m_hand;
	Bankroll purse;
};

#endif