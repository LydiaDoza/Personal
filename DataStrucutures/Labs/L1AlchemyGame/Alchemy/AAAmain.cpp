/***********************************************************
* Author:					Lydia Doza
* Date Created:				12/4/2015
* Last Modification Date:	12/4/2015
* Lab Number:				Lab 1
* Filename:					Alchemy
*
* Overview:
*	This is the game alchemy.
*
* Input:
*	User places symbols on the board.
*
* Output:
*	You can win or lose. You win by changing the background
*	of all the cells. You lose by discarding 4 symbols.
************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#include "Alchemy.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Alchemy game;

	game.StartGame();


	return 0;
}