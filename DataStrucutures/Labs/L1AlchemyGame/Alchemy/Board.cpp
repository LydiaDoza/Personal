
#include "Board.h"
#include "Exception.h"

/**********************************************************************
* Purpose:	Default constructor. level 1 assumed. to_place is
*			set to random symbol and color.
*
* Entry:	None.
*
* Exit:		Board created.
************************************************************************/
Board::Board() : m_board(8, 9), m_level(1), to_place(1), m_wildcard(168, 115),
m_score(), m_cauldron(), m_bomb(235, 236)
{
	m_board[3][4].SetSymbol(m_wildcard);
	to_place.SetRandom();
	if (to_place.isBomb() || to_place.isWildcard())
	{
		to_place.SetSpecial();
	}
}

/**********************************************************************
* Purpose:	Sets level
*
* Entry:	int level
*
* Exit:
************************************************************************/
Board::Board(int level) : m_board(8, 9), m_level(1), to_place(level), m_wildcard(168, 115),
m_score(), m_cauldron()
{
	m_board[3][4].SetSymbol(m_wildcard);
	to_place.SetRandom();
}



/**********************************************************************
* Purpose:	sets *this to copy.
*
* Entry:	const Board & copy
*
* Exit:		*this is set to copy
************************************************************************/
Board::Board(const Board & copy) : m_board(copy.m_board), m_level(copy.m_level),
to_place(copy.to_place)
{
	*this = copy;
}

/**********************************************************************
* Purpose:	Returns board to initial conditions.
*
* Entry:	None.
*
* Exit:		Board restored.
************************************************************************/
Board::~Board()
{
	ClearBoard();
	// m_cauldron will handle itself
	// m_level and all the symbols will handle themselves.
	// will deal with itself, too, but set it back to initial 
	// empty before cell dtor is called
}

/**********************************************************************
* Purpose:	Sets the level for the board and the symbol to_place
*			so that the right number of characters and colors are
*			chosen from.
*
* Entry:	int level
*
* Exit:		level is set.
************************************************************************/
void Board::SetLevel(int level)
{
	m_level = level;
	to_place.SetLevel(level);
	to_place.SetRandom();
}

/**********************************************************************
* Purpose:	Checks to see if the row is full. If it is, then delete
*			the symbols in the row.
*
* Entry:	int row
*
* Exit:		if row is full, then symbols in that row are set to ' '
************************************************************************/
void Board::Full_Row(int row)
{
	bool check = true;

	for (int col = 0; col < m_board.getColumn() && check == true; col++)
	{
		if (m_board[row][col].IsEmpty())
			check = false;
	}

	if (check)
		Delete_Row(row);
}

/**********************************************************************
* Purpose:	Checks to see if the column is full. If it is, then delete
*			the symbols in the column.
*
* Entry:	int col
*
* Exit:		If the column is full, then the symbols are set to ' '
************************************************************************/
void Board::Full_Col(int col)
{
	bool check = true;
	for (int row = 0; row < m_board.getRow() && check == true; row++)
	{
		if (m_board[row][col].IsEmpty()) // if the character is a space
			check = false;
	}

	if (check)
		Delete_Col(col);
}

/**********************************************************************
* Purpose:	Deletes all the symbols in the row but keeps the background
*			color.
*
* Entry:	int row
*
* Exit:		Row is changed.
************************************************************************/
void Board::Delete_Row(int row)
{
	for (int i = 0; i < m_board.getColumn(); i++)
	{
		m_board[row][i].DeleteSymbol();
	}
}

/**********************************************************************
* Purpose:	Deletes all the symbols in the column but keeps the
*			background color.
*
* Entry:	int col
*
* Exit:		Column symbols are deleted.
************************************************************************/
void Board::Delete_Col(int col)
{
	for (int i = 0; i < m_board.getRow(); i++)
	{
		m_board[i][col].DeleteSymbol();
	}
}

/**********************************************************************
* Purpose:	Checks to see if all the cells have the desired background
*			color. If yes, then returns true.
*
* Entry:	none
*
* Exit:		true if all cells have the desired background. False if not.
************************************************************************/
bool Board::All_Cells_Changed()
{
	bool all_changed = true;

	for (int row = 0; row < m_board.getRow() && all_changed != false; row++)
	{
		for (int col = 0; col < m_board.getColumn() && all_changed != false; col++)
		{
			// color is out of bounds of desired color.
			if (m_board[row][col].GetColor() < 112 || m_board[row][col].GetColor() > 127)
			{
				all_changed = false;
			}
		}
	}

	return all_changed;
}

/**********************************************************************
* Purpose:	Puts a symbol into a cell. 10,10 discards the symbol.
*
* Entry:	int row and int col the symbol will be placed in.
*
* Exit:		Symbol is placed in desired row and column placement
************************************************************************/
void Board::PlaceCell(int row, int col)
{
	if (row < 0 || col < 0 || row > m_board.getRow() + 1 || col > m_board.getColumn() + 1)
		throw Exception("Cannot Place outside of board");

	if (row == 8 && col == 9)
	{
		m_cauldron.Discard(to_place);
		to_place.SetRandom();
	}
	else
	{
		if (to_place.GetSymbol() != m_bomb.GetSymbol())
		{
			// first check to make sure the cell is empty and symbol not bomb
			if (m_board[row][col].IsEmpty())
			{
				// if it is a valid placement (adjacent cells are empty, same color
				// or same symbol
				if (Can_Place(row, col))
				{
					// at least one of the cells has a symbol
					if (NotEmptyTop(row, col) ||
						NotEmptyBottom(row, col) ||
						NotEmptyLeft(row, col) ||
						NotEmptyRight(row, col))
					{
						// place the symbol
						m_board[row][col].SetSymbol(to_place);
						// get a new random symbol
						m_score.Add(SidesTouched(row, col));
						// re randomize the symbol.
						to_place.SetRandom();
						//get rid of one of them
						m_cauldron.Decrement();

						Full_Col(col);
						Full_Row(row);

					}
				}
			}
		}
		else // bomb
		{
			if (!m_board[row][col].IsEmpty())
			{
				m_board[row][col].DeleteSymbol();
				to_place.SetRandom();
			}
		}
	}
}

/**********************************************************************
* Purpose:	Displays board.
*
* Entry:	None.
*
* Exit:		board is displayed.
************************************************************************/
void Board::DisplayBoard()
{
	SetConsoleTextAttribute(handle, 7);
	cout << "  ";
	for (int i = 0; i < 9; i++)
	{
		SetConsoleTextAttribute(handle, 112);
		cout << (i + 1) << " ";
	}

	cout << endl;

	for (int row = 0; row < m_board.getRow(); row++) // plus because extra 
	{
		for (int col = -1; col < m_board.getColumn(); col++)
		{
			if (col == -1)
			{
				SetConsoleTextAttribute(handle, 112);
				cout << (col + 2 + row) << " ";
			}
			else
			{
				SetConsoleTextAttribute(handle, m_board[row][col].GetColor());
				cout << m_board[row][col] << " ";
			}
		}

		if (row == 0)
		{
			SetConsoleTextAttribute(handle, 7);
			cout << "\t\tCauldron\t\tScore";
		}
		else if (row == 1)
		{
			SetConsoleTextAttribute(handle, 7);
			cout << "\t\t    ";
			SetConsoleTextAttribute(handle, m_cauldron.GetColor(0));
			cout << m_cauldron.GetSymbol(row - 1);
			SetConsoleTextAttribute(handle, 7);
			cout << "\t\t\t  " << m_score;
		}
		else if (row == 2)
		{
			SetConsoleTextAttribute(handle, 7);
			cout << "\t\t    ";
			SetConsoleTextAttribute(handle, m_cauldron.GetColor(1));
			cout << m_cauldron.GetSymbol(row - 1);
		}
		else if (row == 3)
		{
			SetConsoleTextAttribute(handle, 7);
			cout << "\t\t    ";
			SetConsoleTextAttribute(handle, m_cauldron.GetColor(2));
			cout << m_cauldron.GetSymbol(row - 1);
		}
		cout << endl;
	}

	SetConsoleTextAttribute(handle, 7);
	cout << "\nWildCard: " << m_wildcard;

	SetConsoleTextAttribute(handle, 7);
	cout << "\nBomb: " << m_bomb;

	SetConsoleTextAttribute(handle, 7);
	cout << "\nCurrent Symbol: " << to_place << "\n" << endl;

}

/**********************************************************************
* Purpose:	Checks the symbol to_place against the passed in row and
*			column's symbol. returns true if either it empty, the same
*			color, or the same symbol.
*
* Entry:	int row, int col
*
* Exit:		true or false.
************************************************************************/
bool Board::Col_or_Symb(int row, int col)
{
	bool can_place = false;

	if (m_board[row][col].IsEmpty()
		|| m_board[row][col].IsColor(to_place.GetColor())
		|| m_board[row][col].IsSymbol(to_place.GetSymbol())
		|| m_board[row][col].IsSymbol(m_wildcard.GetSymbol()))
	{
		can_place = true;
	}

	return can_place;
}

/**********************************************************************
* Purpose:	This checks the passed in cell's perimeter to make sure
*			that it can be placed.
*
* Entry:	int row, int col
*
* Exit:		true or false.
************************************************************************/
bool Board::Can_Place(int row, int col)
{
	bool can = false;

	if (MatchTop(row, col) &&
		MatchBottom(row, col) &&
		MatchLeft(row, col) &&
		MatchRight(row, col))
	{
		can = true;
	}

	if (to_place.GetSymbol() == m_wildcard.GetSymbol())
		can = true;	

	return can;
}

/**********************************************************************
* Purpose:	Returns true if the current symbol can be placed against
*			the top cell.
*
* Entry:	int row, int col
*
* Exit:		true or false
************************************************************************/
bool Board::MatchTop(int row, int col)
{
	bool match = false;

	// not on top row
	if (row - 1 >= 0)
	{
		if (Col_or_Symb(row - 1, col))
			match = true;
	}
	// row - 1 is below the array. Can Place against top
	else
		match = true;

	return match;
}

/**********************************************************************
* Purpose:	Returns true if can place against the bottom cell
*
* Entry:	int row, int col of cell symbol is placed in.
*
* Exit:		true or false
************************************************************************/
bool Board::MatchBottom(int row, int col)
{
	bool match = false;

	// within the board
	if (row + 1 < m_board.getRow())
	{
		if (Col_or_Symb(row + 1, col))
			match = true;
	}
	// else cell below is over bounds of array, can place
	else
	{
		match = true;
	}

	return match;
}

/**********************************************************************
* Purpose:	Returns true if symbol can be placed against cell to the
*			left.
*
* Entry:	int row, int col of the cell the symbol is placed in.
*
* Exit:		true or false
************************************************************************/
bool Board::MatchLeft(int row, int col)
{
	bool match = false;

	// cell to the left is within the board
	if (col - 1 >= 0)
	{
		if (Col_or_Symb(row, col - 1))
			match = true;
	}
	//
	else
	{
		match = true;
	}

	return match;
}

/**********************************************************************
* Purpose:	Checks to see if the symbol can be placed against right
*			cell.
*
* Entry:	int row, int col  of the cell symbol is placed in
*
* Exit:		true or false
************************************************************************/
bool Board::MatchRight(int row, int col)
{
	bool match = false;

	if (col + 1 < m_board.getColumn())
	{
		if (Col_or_Symb(row, col + 1))
		{
			match = true;
		}
	}
	// column to the right is out of board, can place
	else
	{
		match = true;
	}

	return match;
}

/**********************************************************************
* Purpose:	Checks if top is not empty
*
* Entry:	int row, int col
*
* Exit:		true or false
************************************************************************/
bool Board::NotEmptyTop(int row, int col)
{
	bool notEmpty = false;

	// not on top row
	if (row - 1 >= 0)
	{
		// if top is not empty
		if (!m_board[row - 1][col].IsEmpty())
			notEmpty = true;
	}

	return notEmpty;
}

/**********************************************************************
* Purpose:	Checks that bottom is not empty. If it has a symbol, then
*			true.
*
* Entry:	int row, int col
*
* Exit:		true or false
************************************************************************/
bool Board::NotEmptyBottom(int row, int col)
{
	bool notEmpty = false;

	// within the board
	if (row + 1 < m_board.getRow())
	{
		// bottom is not empty
		if (!m_board[row + 1][col].IsEmpty())
			notEmpty = true;
	}

	return notEmpty;
}

/**********************************************************************
* Purpose:	Checks if left is empty. True if not empty, false if empty
*
* Entry:	int row, int col
*
* Exit:		true or false
************************************************************************/
bool Board::NotEmptyLeft(int row, int col)
{
	bool notEmpty = false;

	// cell to the left is within the board
	if (col - 1 >= 0)
	{
		// left is not empty
		if (!m_board[row][col - 1].IsEmpty())
			notEmpty = true;
	}
	return notEmpty;
}

/**********************************************************************
* Purpose:	Checks if right is empty. If empty, false, if not empty,
*			true
*
* Entry:	int row, int col
*
* Exit:		true or false
************************************************************************/
bool Board::NotEmptyRight(int row, int col)
{
	bool notEmpty = false;

	if (col + 1 < m_board.getColumn())
	{
		// not empty
		if (!m_board[row][col + 1].IsEmpty())
		{
			notEmpty = true;
		}
	}

	return notEmpty;
}

/**********************************************************************
* Purpose:	returns the number of sides the cell placed is touching
*			used for the incrementing the score.
*
* Entry:	int row, int col
*
* Exit:		number of sides touched.
************************************************************************/
int Board::SidesTouched(int row, int col)
{
	int sides(0);

	if (MatchTop(row, col) && NotEmptyTop(row, col))
		++sides;

	if (MatchBottom(row, col) && NotEmptyBottom(row, col))
		++sides;

	if (MatchLeft(row, col) && NotEmptyLeft(row, col))
		++sides;

	if (MatchRight(row, col) && NotEmptyRight(row, col))
		++sides;

	return sides;
}

/**********************************************************************
* Purpose:	returns cauldron
*
* Entry:	none
*
* Exit:		m_caulrdon is returned
************************************************************************/
Cauldron Board::GetCauldron()
{
	return m_cauldron;
}

/**********************************************************************
* Purpose:	Clears the board
*
* Entry:	none
*
* Exit:		board is cleared
************************************************************************/
void Board::ClearBoard()
{
	for (int row = 0; row < m_board.getRow(); row++)
	{
		for (int col = 0; col < m_board.getColumn(); col++)
		{
			m_board[row][col].DeleteSymbol();
			m_board[row][col].SetColor(7);
		}
	}

	m_cauldron.ClearCauldron();

	m_board[3][4].SetSymbol(m_wildcard);
	to_place.SetRandom();
	if (to_place.isBomb() || to_place.isWildcard())
	{
		to_place.SetSpecial();
	}
}

/**********************************************************************
* Purpose:	returns score
*
* Entry:	none
*
* Exit:		int score returned
************************************************************************/
int Board::GetScore()
{
	return m_score.GetScore();
}

/**********************************************************************
* Purpose:	sets *this to rhs
*
* Entry:	const Board & rhs
*
* Exit:		this is set to rhs
************************************************************************/
Board& Board::operator=(const Board & rhs)
{
	if (this != &rhs)
	{
		m_board = rhs.m_board;
		m_level = rhs.m_level;
		to_place = rhs.to_place;
	}

	return *this;
}
