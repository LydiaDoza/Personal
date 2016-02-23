/***********************************************************
* Author:					Lydia Doza
* Date Created:				4/6/2015
* Last Modification Date:	4/6/2015
* Lab Number:				
* Filename:					FreeCell
*
* Overview:
*	
*
* Input:
*
*
* Output:
*
************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#include "FCGame.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	FCGame freecell;
	freecell.StartGame();

	return 0;
}