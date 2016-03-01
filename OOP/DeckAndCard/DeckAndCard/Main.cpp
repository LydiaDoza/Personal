/***********************************************************
* Author:					Lydia Doza
* Date Created:				2/16/2015
* Last Modification Date:	2/18/2015
* Lab Number:				CST 136 Lab 6
* Filename:					Main.cpp
* Overview:
*	Tests Card and Deck and Random classes.
************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "Card.h"
#include "Deck.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Deck deck;

	deck.DisplayAll();
	cout << "--------------------------------------\n";

	deck.Shuffle();
	deck.DisplayAll();

	cout << "\nStatic function test: " << Deck::GetCount() << " cards dealt/displayed.\n" << endl;

	for (int r = 0; r < 3; r++)
	{
		for (int i = 0; i < 4; i++)
			deck.Deal().Display();
		cout << endl;
	}
	cout << "\nCards dealt: " << deck.GetCardsDealt() << endl;


	return 0;
}