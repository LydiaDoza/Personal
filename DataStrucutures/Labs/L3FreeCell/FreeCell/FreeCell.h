/***********************************************************
* Class:			FreeCell
* 		
* Managers:
* 	FreeCell
* 		Default constructor
*	FreeCell(const FreeCell & copy)
* 		Copy Ctor
*	~FreeCell
*		Destructor
* 	void operator=(const FreeCell & rhs)
*		Overload the = operator
*
* Public Methods:
*	int GetEmpty();
*		returns number of empty free cells
*	void Clear();
*		Set back to empty cells
*	void Draw();
*		Draws cards from free cells
*	bool AddCard(Card card, int i);
*		Insert card at i
*	bool IsEmpty(int i);
*		return true if cell at i is empty
*	Card PeekCard(int i);
*		return card at i
*	void EmptyCell(int i);
*		make cell at i empty
************************************************************/
#ifndef FREECELL_H
#define FREECELL_H

#include "Array.h"
#include "Card.h"

class FreeCell
{
public:
	FreeCell();
	FreeCell(const FreeCell & copy);
	~FreeCell();
	
	FreeCell& operator=(const FreeCell & rhs);

	int GetEmpty();
	void Clear();
	void Draw();
	bool AddCard(Card card, int i);
	bool IsEmpty(int i);
	Card PeekCard(int i);
	void EmptyCell(int i);
	
private:
	Array<Card> m_cells;
	Array<bool> m_empty;
};

#endif