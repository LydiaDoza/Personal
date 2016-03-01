/**************************************************************
*                Never gonna give you up
****************************************************************/
#include "Player.h"

/**************************************************************
*	Name:
*		Player()
*
*	Purpose:
*		sets purse to zero, calls m_hands default ctor, no 
*		cards in hand
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Player::Player() : m_hand(), purse()
{
	
}

/**************************************************************
*	Name:
*		Player(int money)
*
*	Purpose:
*		puts money in purse, no cards in hand
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Player::Player(int money) : m_hand()
{
	purse.SetMoney(money);
}

/**************************************************************
*	Name:
*		~Player()
*
*	Purpose:
*		Remove the moneys from the purse
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Player::~Player()
{
	// REMOVE ALL THE MONEY FROM THE PURSE
	//purse.SubMoney(purse.GetMoney());
}

/**************************************************************
*	Name:
*		SetPurse(int money)
*
*	Purpose:
*		Adds money to purse
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Player::SetPurse(int money)
{
	purse.AddMoney(money);
}

/**************************************************************
*	Name:
*		GetPurse()
*
*	Purpose:
*		Returns the amount of money in purse
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
int Player::GetPurse() const
{
	return purse.GetMoney();
}

/**************************************************************
*	Name:
*		AddToPurse(int money)
*
*	Purpose:
*		Adds money to purse.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Player::AddToPurse(int money)
{
	purse.AddMoney(money);
}

/**************************************************************
*	Name:
*		SubFromPurse(int money)
*
*	Purpose:
*		Subtracts money from purse.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Player::SubFromPurse(int money)
{
	purse.SubMoney(money);
}

/**************************************************************
*	Name:
*		DisplayCards()
*
*	Purpose:
*		Displays all cards.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Player::DisplayCards()
{
	m_hand.DisplayCards();
}

/**************************************************************
*	Name:
*		DealCard()
*
*	Purpose:
*		Adds a card to the hand.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Player::AddCard(Card card)
{
	m_hand.Add(card);
}

/**************************************************************
*	Name:
*		DeleteCards()
*
*	Purpose:
*		Removes all the cards in the hand.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Player::DeleteCards()
{
	m_hand.RemoveAll();
}

/**************************************************************
*	Name:
*		GetHandValue()
*
*	Purpose:
*		Returns face value in all of hand
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
int Player::GetHandValue()
{
	return m_hand.GetFaceValue();
}