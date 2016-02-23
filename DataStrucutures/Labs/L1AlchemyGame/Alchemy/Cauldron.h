/***********************************************************
* Class:			Cauldron
* 		
* Managers:
* 	Cauldron
* 		Default constructor
*	Cauldron(const Cauldron & copy)
* 		Copy Ctor
*	~Cauldron
*		Destructor
* 	void operator=(const Cauldron & rhs)
*		Overload the = operator
*
* Public Methods:
*	char GetSymbol(int index);
*		Returns symbol as char from cauldron at index
*	int GetColor(int index);
*		Returns color int
*	int GetDiscards();
*		Returns number of symbols in cauldron
*	void Discard(Symbol s);
*		Adds symbol to cauldron
*	void Decrement();
*		Removes symbol from cauldron
*	void ClearCauldron();
*		Clears cauldron. Sets number to 0.
************************************************************/
#ifndef CAULDRON_H
#define CAULDRON_H

#include "Symbol.h"

class Cauldron
{
public:
	Cauldron();
	Cauldron(const Cauldron & copy);
	~Cauldron();
	
	Cauldron& operator=(const Cauldron & rhs);

	char GetSymbol(int index);
	int GetColor(int index);
	int GetDiscards();
	void Discard(Symbol s);
	void Decrement();
	void ClearCauldron();
	
	
private:
	Symbol m_discard[4];
	int discards;
};

#endif