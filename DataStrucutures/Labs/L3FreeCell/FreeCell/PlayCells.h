/***********************************************************
* Class:			PlayCells
* 		
* Managers:
* 	PlayCells
* 		Default constructor
*	PlayCells(const PlayCells & copy)
* 		Copy Ctor
*	~PlayCells
*		Destructor
* 	void operator=(const PlayCells & rhs)
*		Overload the = operator
*
* Public Methods:
*	
*
************************************************************/
#ifndef PLAYCELLS_H
#define PLAYCELLS_H

#include "Array.h"
#include "DStack.h"
#include "Card.h"
#include "Deck.h"

class PlayCells
{
public:
	static const int PlayAmount = 8;
	PlayCells();
	PlayCells(const PlayCells & copy);
	~PlayCells();
	
	PlayCells& operator=(const PlayCells & rhs);

	void Draw();
	void DealGame(Deck deck);
	DStack<Card> GetCards(int col, int pos);
	void RemoveCards(int col, int pos);
	bool AddCards(DStack<Card> card, int col, int freecells);
	bool IsValid(int col, int ncards, int freecells);
	void Clear();
	int GetSize(int col);
	
private:
	Array<DStack<Card>> m_play;
};

#endif