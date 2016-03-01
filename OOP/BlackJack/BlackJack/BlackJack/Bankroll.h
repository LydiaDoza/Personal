/************************************************************************
*				And if you ask me how I'm feeling    
* Class: Bankroll
*
* Constructors:
*	Bankroll()
*		initializes m_money to zero
*	Banroll(int start)
*		initializes m_money to start
*
* Destructors:
*	~Bankroll()
*		resets m_money to zero
*
* Public Methods:
*	void SetMoney(int money)
*		Sets m_money to money
*	void AddMoney(int add)
*		Adds add to m_money
*	void SubMoney(int sub)
*		Subtracts sub from m_money
*	int GetMoney()
*		Returns m_money
*	
*************************************************************************/
#ifndef BANKROLL_H
#define BANKROLL_H

#include <iostream>
using std::cout;
using std::endl;

class Bankroll
{
public:
	Bankroll();
	Bankroll(int start);
	~Bankroll();

	void SetMoney(int money);

	void AddMoney(int add);
	void SubMoney(int sub);

	int GetMoney() const;

private:
	int m_money;
};


#endif