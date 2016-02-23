
#include "Display.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include "FCGame.h"
#include "Card.h"
#include "PlayCells.h"
/**********************************************************************
* Purpose:	Default ctor
* Entry:	none
* Exit:		data members are initialized
************************************************************************/
FCGame::FCGame()
{

}

/**********************************************************************
* Purpose:	copy ctor
* Entry: 	const FCGame & copy
* Exit:		this = copy
************************************************************************/
FCGame::FCGame(const FCGame & copy)
{
	*this = copy;
}

/**********************************************************************
* Purpose:	dtor
* Entry:	none
* Exit:		deallocates memory
************************************************************************/
FCGame::~FCGame()
{   }

/**********************************************************************
* Purpose:	Starts game
* Entry:	none
* Exit:		void
************************************************************************/
void FCGame::StartGame()
{
	string temp = "123";
	char choice = '1';
	cout << "\tWelcome to Free Cell!\n\n";

	cout << "1. Start Game\n"
		<< "2. cheat\n"
		<< "3. quit\n" << endl;

	do
	{
		getline(cin, temp);
		choice = temp[0];
		if (choice == '1')
			m_deck.Shuffle();
		else if (choice == '2')
		{
			// put all the cards in order
			for (int i(Card::KING), j(0); i >= Card::ACE; i--)
			{
				for (int k(Card::HEART); k <= Card::SPADE; k++, j++)
				{
					m_deck[j] = Card(Card::Rank(i), Card::Suit(k));
				}
			}
		}
		Play();
		DoOver();
	} while (choice != '3');

	cout << endl << "Good bye!" << endl;
}

/**********************************************************************
* Purpose:	game stuff
* Entry:	none
* Exit:		void
************************************************************************/
void FCGame::Play()
{
	bool win = false;
	string from, to;

	DrawInitial();
	DealGame();
	cout << "\nH - home, P - play, F - free, E - exit"
		"\nfrom<enter>to<enter>" << endl;
	do
	{
		getline(cin, from);
		DrawInvalidMove(false);


	} while (!win && from[0] != 'E');
}

/**********************************************************************
* Purpose:	draw board
* Entry:	none
* Exit:		void
************************************************************************/
void FCGame::DrawInitial()
{
	system("CLS");
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	DrawInitCells(DISPLAY::FREE_UPPER_LEFT, 4);
	DrawInitCells(DISPLAY::HOME_UPPER_LEFT, 4);

	COORD pos = DISPLAY::PLAY_UPPER_LEFT;

	for (int i(0); i < PlayCells::PlayAmount; i++)
	{
		Card::DrawEmpty(pos);
		pos.X += 2;
	}


}

/**********************************************************************
* Purpose:	draws empty cells
* Entry: 	COORD position, int number
* Exit:		void
************************************************************************/
void FCGame::DrawInitCells(COORD position, int number)
{
	for (int i = 0; i < number; i++)
	{
		Card::DrawEmpty(position);
	}
}

/**********************************************************************
* Purpose:	clears everything
* Entry:
* Exit:		void
************************************************************************/
void FCGame::DoOver()
{
	m_free.Clear();
	m_home.Clear();
	m_play.Clear();
}

/**********************************************************************
* Purpose:	deals cards
* Entry:	none
* Exit:		void
************************************************************************/
void FCGame::DealGame()
{
	m_play.DealGame(m_deck);
}

/**********************************************************************
* Purpose:	displays invalid move
* Entry: 	bool msg = true
* Exit:		void
************************************************************************/
void FCGame::DrawInvalidMove(bool invalid /*= true*/)
{
	if (invalid)
		cout << "\n\nINVALID MOVE" << endl << endl;
	else
		cout << "\n\n      " << endl << endl;

	_flushall();
}

/**********************************************************************
* Purpose:
* Entry: 	const FCGame & rhs
* Exit:		FCGame&
************************************************************************/
FCGame& FCGame::operator=(const FCGame & rhs)
{
	if (this != &rhs)
	{

	}
	return *this;
}

