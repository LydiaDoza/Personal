/************************************************************************
*				Inside, we both know what's been going on
* Class: Card
*
* Constructors:
*	Card(Rank rank = ACE, Suit suit = SPADE)
*		ctor two, one, 0 arg
*	Card(const Card & card)
*		copy ctor, copies stuff
*
* Destructors:
*	~Card()
*		dtor or whatevs
*
* Public Methods:
*	void Display()
*		Displays contents of *this
*	void SetRank(Rank rank)
*		Sets m_rank to rank
*	void SetSuit(Suit suit)
*		Sets m_suit to suit
*	Rank GetRank()
*		Returns m_rank
*	Suit GetSuit()
*		Returns m_suit for science
*	Card& operator=(const Card & card)
*		sets this to that card
*	bool operator == (const Card & card)
*		Checks if this is the same as that card
*************************************************************************/
#ifndef CARD_H
#define CARD_H
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Display.h"

class Card
{
public:
	enum Rank { ACE = 1, DEUCE, TREY, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum Suit { HEART = 3, DIAMOND, CLUB, SPADE }; // ascii values now match heart, diamond, club, spade

	Card(Rank rank = ACE, Suit suit = SPADE);
	~Card();
	Card(const Card & copy);

	void Display() const;

	void SetRank(Rank rank);
	void SetSuit(Suit suit);

	Rank GetRank() const;
	Suit GetSuit() const;

	Card& operator=(const Card & card);
	bool operator==(Card & card);

	bool IsRed();
	void Draw(COORD upleft);
	static void DrawEmpty(COORD upleft);

private:
	Rank m_rank;
	Suit m_suit;

};
#endif