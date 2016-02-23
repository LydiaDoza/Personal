/***********************************************************
* Class:			HomeCell
* 		
* Managers:
* 	HomeCell
* 		Default constructor
*	HomeCell(const HomeCell & copy)
* 		Copy Ctor
*	~HomeCell
*		Destructor
* 	void operator=(const HomeCell & rhs)
*		Overload the = operator
*
* Public Methods:
*	
*
************************************************************/
#ifndef HOMECELL_H
#define HOMECELL_H

#include "Card.h"
#include "Stack.h"

class HomeCell
{
public:
	static const int HomeAmount = 4;

	HomeCell();
	HomeCell(const HomeCell & copy);
	~HomeCell();
	
	HomeCell& operator=(const HomeCell & rhs);

	void Draw();
	bool IsFull();
	bool Add(Card card);
	void Clear();

private:
	Array<Stack<Card> *> m_home;
};

#endif