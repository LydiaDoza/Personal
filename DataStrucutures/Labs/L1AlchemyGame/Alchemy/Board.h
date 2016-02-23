/***********************************************************
* Class:			Board
* 		
* Managers:
* 	Board
* 		Default constructor
*	Board(int level)
*		1 arg ctor ets level of board.
*	Board(const Board & copy)
* 		Copy Ctor
*	~Board
*		Destructor
* 	void operator=(const Board & rhs)
*		Overload the = operator
*
* Public:
* void SetLevel(int level);
*	Sets the level for the board and the symbol.
* void Full_Row(int row);
*	If row is full, delete it
* void Full_Col(int col);
*	If col is full, delete it
* void Delete_Row(int row);
*	Called from Full_Row
* void Delete_Col(int col);
*	Called from Full_Col
* bool All_Cells_Changed();
*	Checks if all the background is grey for win
* void PlaceCell(int row, int col);
*	Handles placing a symbol on the board
* void DisplayBoard();
*	Displays board, cauldron, and score
* bool Col_or_Symb(int row, int col);
*	Checks if to_place is the same color, symbol,
*	or if wildcard
* bool Can_Place(int row, int col);
*	if wildcard, can place anywhere. Checks
*	all adjacent tiles to make sure that to_place
*	can be placed
* bool MatchTop(int row, int col);
*	Checks if to_place can be placed against the top
*	tile.
* bool MatchBottom(int row, int col);
*	Checks if to_place can be placed against the bottom
*	tile.
* bool MatchLeft(int row, int col);
*	Checks if to_place can be placed against the left
*	tile.
* bool MatchRight(int row, int col);
*	Checks if to_place can be placed against the right
*	tile.
* bool NotEmptyTop(int row, int col);
*	Checks if top tile is not empty.
* bool NotEmptyBottom(int row, int col);
*	Checks if bottom tile is not empty.
* bool NotEmptyLeft(int row, int col);
*	Checks if left tile is not empty.
* bool NotEmptyRight(int row, int col);
*	Checks if right tile is not empty.
* int SidesTouched(int row, int col);
*	Returns number of sides that the to_place touches and
*	increments score
* Cauldron GetCauldron();
*	returns m_cauldron
* void ClearBoard();
*	Clears the board of all symbols. randomizes to_place
*	and sets center wildcard
* int GetScore();
*	returns m_score from score class
************************************************************/
#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include "Array2D.h"
#include "Score.h"
#include "Cauldron.h"
#include "Symbol.h"


class Board
{
public:
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	Board();
	Board(int level);
	Board(const Board & copy);
	~Board();
	
	Board& operator=(const Board & rhs);

	void SetLevel(int level);

	void Full_Row(int row);
	void Full_Col(int col);

	void Delete_Row(int row);
	void Delete_Col(int col);

	bool All_Cells_Changed();

	void PlaceCell(int row, int col);
	void DisplayBoard();

	bool Col_or_Symb(int row, int col);
	bool Can_Place(int row, int col);

	bool MatchTop(int row, int col);
	bool MatchBottom(int row, int col);
	bool MatchLeft(int row, int col);
	bool MatchRight(int row, int col);
	bool NotEmptyTop(int row, int col);
	bool NotEmptyBottom(int row, int col);
	bool NotEmptyLeft(int row, int col);
	bool NotEmptyRight(int row, int col);

	int SidesTouched(int row, int col);
	Cauldron GetCauldron();

	void ClearBoard();
	int GetScore();

private:
	Array2D<Cell> m_board;
	Symbol m_wildcard;
	Symbol m_bomb;
	Symbol to_place;
	int m_level;
	Score m_score;
	Cauldron m_cauldron;
};

#endif