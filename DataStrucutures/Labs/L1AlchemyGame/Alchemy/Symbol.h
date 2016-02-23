/***********************************************************
* Class:			Symbol
*
* Managers:
* 	Symbol
* 		Default constructor
*	Symbol(char sym, int col);
*		2 arg ctor. sets symbol and color.
*	Symbol(char sym, int col, int level);
*		3 arg ctor. Sets symbol and color and level.
*	Symbol(int level);
*		1 arg ctor. Sets level.
*	Symbol(const Symbol & copy)
* 		Copy Ctor
*	~Symbol
*		Destructor
* 	void operator=(const Symbol & rhs)
*		Overload the = operator
*
* Public Methods:
*	ostream& operator<<(ostream& o, const Symbol& s)
*		prints the symbol with the right color.
*	void SetRandom()
*		Sets the symbol to a random char and color based on
*		level.
*	void SetSymbol(char sym)
*		Sets the symbol to a random character and random
*		color.
*	void SetColor(int color)
*		Sets the color of the symbol
*	void SetLevel(int level)
*		Sets the level of the symbol
*	char GetSymbol()
*		Returns m_symbol as char
*	int GetColor()
*		Returns int color
*	bool isWildcard()
*		Checks if wildcard. true yes, false no.
*	bool isBomb()
*		Checks if bomb. True yes, false no.
*	void SetSpecial()
*		Sets the bomb or wildcard color.
************************************************************/
#ifndef SYMBOL_H
#define SYMBOL_H

#include "Random.h"
#include <iostream>
using std::ostream;

#include <windows.h>

class Symbol
{
public:
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	Symbol();
	Symbol(char sym, int col);
	Symbol(char sym, int col, int level);
	Symbol(int level);
	Symbol(const Symbol & copy);
	~Symbol();

	Symbol& operator=(const Symbol & rhs);
	friend ostream& operator<<(ostream& o, const Symbol & s);

	void SetRandom();
	void SetSymbol(char sym);
	void SetColor(int color);
	void SetLevel(int level);

	char GetSymbol();
	int GetColor();
	bool isWildcard();
	bool isBomb();
	void SetSpecial();
private:
	int m_level;
	int m_color;
	char m_symbol;
	Random rand;



};

#endif