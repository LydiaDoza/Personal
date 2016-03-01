/**************************************************************
*			Don't tell me you're too blind to see
****************************************************************/
#include "Bankroll.h"

/**************************************************************
*	Name:
*		Bankroll()
*
*	Purpose:
*		Sets m_money to zero.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Bankroll::Bankroll() : m_money(0)
{

}

/**************************************************************
*	Name:
*		~Bankroll()
*
*	Purpose:
*		Resets m_money to zero.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Bankroll::~Bankroll()
{
	m_money = 0;
}

/**************************************************************
*	Name:
*		SetMoney(int money)
*
*	Purpose:
*		sets money in purse
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Bankroll::SetMoney(int money)
{
	m_money = money;
}

/**************************************************************
*	Name:
*		AddMoney(int add)
*
*	Purpose:
*		adds money to purse
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Bankroll::AddMoney(int add)
{
	m_money += add;
}

/**************************************************************
*	Name:
*		SubMoney(int sub)
*
*	Purpose:
*		Subtracts money from purse
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Bankroll::SubMoney(int sub)
{
	// CONSIDER USING RETURN VALUES TO DEAL WITH NEGATIVE VALUES

	if (sub <= m_money)
		m_money -= sub;
	else // sub is greater than money
	{
		cout << "\nYou don't have enough money so I took the rest."
			<< "\nYou have nothing now and you can no longer play.\n" << endl;
	}
}

/**************************************************************
*	Name:
*		GetMoney()
*
*	Purpose:
*		Returns m_money.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
int Bankroll::GetMoney() const
{
	return m_money;
}