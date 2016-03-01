/**************************************************************
*			Never gonna run around and desert you
****************************************************************/
#include "Dealer.h"

/**************************************************************
*	Name:
*		Dealer()
*
*	Purpose:
*		Uses Player Default ctor
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Dealer::Dealer() 
{

}

/**************************************************************
*	Name:
*		~Dealer()
*
*	Purpose:
*		Uses Player destructor
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Dealer::~Dealer()
{

}

/**************************************************************
*	Name:
*		DisplayOneCard() const
*
*	Purpose:
*		Displays one card face up
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Dealer::DisplayOneCard() const
{
	m_hand.DisplayFirstCard();
}

/**************************************************************
*	Name:
*		ShowFaceDown()
*
*	Purpose:
*		Displays one card face up
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Dealer::ShowFaceDown()
{
	// starts at 1 so that it doesn't count the face up card
	for (int i = 1; i < m_hand.GetCardCount(); i++)
	{
		cout << "\nDealer Card Face Down" << endl;
	}
}