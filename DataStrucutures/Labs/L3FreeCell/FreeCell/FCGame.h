/***********************************************************
* Class:			FCGame
*	 		
*	This class is where the game is actually called from
*	and where the functionality lies.
*
* Managers:
* 	FCGame
* 		Default constructor
*	FCGame(const FCGame & copy)
* 		Copy Ctor
*	~FCGame
*		Destructor
* 	void operator=(const FCGame & rhs)
*		Overload the = operator
*
* Public Methods:
*	
*
************************************************************/
#ifndef FCGAME_H
#define FCGAME_H

#include "Deck.h"
#include "FreeCell.h"
#include "HomeCell.h"
#include "PlayCells.h"

class FCGame
{
public:
	FCGame();
	FCGame(const FCGame & copy);
	~FCGame();
	
	FCGame& operator=(const FCGame & rhs);

	void StartGame();
	void Play();
	void DrawInitial();
	void DrawInitCells(COORD position, int number);
	void DoOver();
	void DealGame();
	void DrawInvalidMove(bool msg = true);
	
private:
	Deck m_deck;
	FreeCell m_free;
	HomeCell m_home;
	PlayCells m_play;
};

#endif