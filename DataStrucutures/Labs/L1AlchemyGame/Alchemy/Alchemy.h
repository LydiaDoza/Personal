/***********************************************************
* Class:			Alchemy
* 		
* Managers:
* 	Alchemy
* 		Default constructor
*	Alchemy(const Alchemy & copy)
* 		Copy Ctor
*	~Alchemy
*		Destructor
* 	void operator=(const Alchemy & rhs)
*		Overload the = operator
*
* Public Methods:
*	void StartGame();
*		Splash screen. Sets level.		
*	void PromptUser();
*		Displays board.Gets user input to place symbol on 
*		board.
*	void DisplayBoard();
*		Displays the board, cauldron, and score.
*	void PlaceSymbol(int row, int col);
*		Calls board's PlaceCell. Places symbol for user.
*	void ClearBoard();
*		Clears the board after a win or lose. 
*	void Win();
*		Splash screen. Displays "win" and score.
*	void Lose();
*		Splash scree. Displays "lose" and score.
************************************************************/
#ifndef ALCHEMY_H
#define ALCHEMY_H

#include "Board.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Alchemy
{
public:
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	Alchemy();
	Alchemy(const Alchemy & copy);
	~Alchemy();
	
	Alchemy& operator=(const Alchemy & rhs);

	void StartGame();
	void PromptUser();
	void DisplayBoard();
	void PlaceSymbol(int row, int col);
	void ClearBoard();
	void Win();
	void Lose();
	
private:
	Board m_board;
	int level;
};

#endif