/***********************************************************
* Author:					Lydia Doza
* Date Created:				2/27/2015
* Last Modification Date:	3/11/2015
* Lab Number:				CST 136 Lab 7
* Filename:					Blackjack
*
* Overview:
*	Blackjack things
*
* Input:
*	choices, bets, stuff
*
* Output:
*	usually losing
************************************************************/

#include "Blackjack.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	const int start = 200; //starting amount in the Players Bankroll
	Blackjack game(start);
	game.StartPrompt();

	return 0;
}