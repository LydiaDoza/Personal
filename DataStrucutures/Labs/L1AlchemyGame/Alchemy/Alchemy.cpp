
#include "Alchemy.h"

/**********************************************************************
* Purpose:	Default ctor
*
* Entry:	none
*
* Exit:		alchemy initialized
************************************************************************/
Alchemy::Alchemy() : m_board(), level(1)
{

}

/**********************************************************************
* Purpose:	copy ctor
*
* Entry:	const Alchemy & copy
*
* Exit:		this set to copy
************************************************************************/
Alchemy::Alchemy(const Alchemy & copy)
{
	*this = copy;
}

/**********************************************************************
* Purpose:	Dtor
*
* Entry:	none
*
* Exit:		alchemy set to initial conditions
************************************************************************/
Alchemy::~Alchemy()
{
	level = 1;
	//m_board handles itself
}

/**********************************************************************
* Purpose:	Starts the game. Gets level.
*
* Entry:	none
*
* Exit:		level set.
************************************************************************/
void Alchemy::StartGame()
{
	char in[2] = { '\0' };
	SetConsoleTextAttribute(handle, 7);
	do
	{
		system("cls");
		cout << "\n\n\tWelcome to Alchemy\n"
			<< "\nWhat level would you like to play? (1, 2, 3)"
			<< "\n 4 to quit" << endl;
		cin.clear();
		cin >> in;
	} while (!isdigit(in[0]));

	level = atoi(in);

	if (level != 4)
	{
		m_board.SetLevel(level);
		PromptUser();
	}
	SetConsoleTextAttribute(handle, 7);
	system("cls");
	cout << "\n\tGood bye!" << endl;

}

/**********************************************************************
* Purpose:	Displays board. Gets user input to set symbols.
*
* Entry:	None.
*
* Exit:		menu and user control handled
************************************************************************/
void Alchemy::PromptUser()
{
	char row[2] = { 'a', 'a' };
	char col[2] = { 'a', 'a' };
	int row_num = 0, col_num = 0;

	do
	{
		SetConsoleTextAttribute(handle, 7);
		system("cls");
		DisplayBoard();
		// get input
		do
		{
			SetConsoleTextAttribute(handle, 7);
			cout << "\n\nTo Place A Symbol, type [row number][enter][col number][enter]."
				<< "\nExample: \n05<enter> \n04<enter>"
				<< "\n\nTo Place A Symbol in the Cauldron [9][enter][10][enter]" << endl;
			cin.clear();
			cin >> row >> col;
		} while (!isdigit(row[0]) || !isdigit(col[0]));

		row_num = atoi(row) - 1;
		col_num = atoi(col) - 1;
	} while ((row_num > 8 || row_num < 0) || (col_num > 9 || col_num < 0));

	try
	{
		PlaceSymbol(row_num, col_num);
	}
	catch (Exception e)
	{
		cout << "\n\n" << e << endl;
		system("pause");
		PromptUser();
	}

}

/**********************************************************************
* Purpose:	Displays the board.
*
* Entry:	none
*
* Exit:		m_board displayed
************************************************************************/
void Alchemy::DisplayBoard()
{
	m_board.DisplayBoard();
}

/**********************************************************************
* Purpose:	Places symbol on board
*
* Entry:
*
* Exit:
************************************************************************/
void Alchemy::PlaceSymbol(int row, int col)
{
	m_board.PlaceCell(row, col);
	int discards = m_board.GetCauldron().GetDiscards();
	if (discards == 4)
		Lose();
	else if (m_board.All_Cells_Changed())
		Win();
	else
		PromptUser();
}

/**********************************************************************
* Purpose:	Clears Board
*
* Entry:	none
*
* Exit:		Board is cleared of all symbols and colors.
************************************************************************/
void Alchemy::ClearBoard()
{
	m_board.ClearBoard();
}

/**********************************************************************
* Purpose:	You win the game. Splash screen of You Win. Then goes
*			back to start screen.
*
* Entry:	none
*
* Exit:		splash screen
************************************************************************/
void Alchemy::Win()
{
	SetConsoleTextAttribute(handle, 7);

	system("cls");
	cout << "\n\n\tCongrats! You win!" << endl;
	cout << "\n\nScore: " << m_board.GetScore();
	system("pause");
	ClearBoard();
	StartGame();
}

/**********************************************************************
* Purpose:	Lose the game. Splash screen. Then back to start screen.
*
* Entry:	none
*
* Exit:		splash screen. start game called.
************************************************************************/
void Alchemy::Lose()
{
	SetConsoleTextAttribute(handle, 7);
	system("cls");
	cout << "\n\n\tSorry. You Lose" << endl;
	cout << "\n\nScore: " << m_board.GetScore();
	system("pause");
	ClearBoard();
	StartGame();
}

/**********************************************************************
* Purpose:	op =, sets this to rhs
*
* Entry:	const Alchemy & rhs
*
* Exit:		this is set to rhs
************************************************************************/
Alchemy& Alchemy::operator=(const Alchemy & rhs)
{
	if (this != &rhs)
	{
		m_board = rhs.m_board;
		level = rhs.level;
	}
	return *this;
}
