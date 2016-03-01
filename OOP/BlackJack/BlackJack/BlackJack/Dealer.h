/************************************************************************
*						Never gonna let you down
* Class: Dealer
*
* Constructors:
*	Dealer()
*		calls default ctors for m_hand and m_purse (from player)
*
* Destructors:
*	~Dealer()
*		calls dtors for m_hand and m_purse (from player)
*
* Public methods are commented below.
*************************************************************************/
#ifndef DEALER_H
#define DEALER_H

#include "Hand.h"
#include "Player.h"

class Dealer : public Player
{
public:
	Dealer();
	~Dealer();

	void DisplayOneCard() const;	// shows only first card face up
	void ShowFaceDown();			// shows face down cards

};

#endif