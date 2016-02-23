/***********************************************************
* Class:			Cell
* 		
* Managers:
* 	Cell
* 		Default constructor
*	Cell(const Cell & copy)
* 		Copy Ctor
*	~Cell
*		Destructor
* 	void operator=(const Cell & rhs)
*		Overload the = operator
*
* Public Methods:
*	bool IsEmpty()
*		Checks if cell is empty
*	bool IsSymbol(char c);
*		Checks if same symbol
*	bool IsColor(int c);
*		Checks if same color
*	int GetColor();
*		returns color
*	void SetColor(int color);
*		sets color in cell
*	void SetSymbol(Symbol s);
*		sets symbol in cell
*	void DeleteSymbol();
*		Deletes symbol in cell
*	friend ostream& operator<<(ostream& o, const Cell& c);
*		overloads output operator so that the cell
*		can be printed using native syntax
************************************************************/
#ifndef CELL_H
#define CELL_H

#include "Symbol.h"
#include "Array2D.h"

#include <iostream>
using std::ostream;

class Cell
{
public:
	Cell();
	Cell(int level);
	Cell(const Cell & copy);
	~Cell();
	
	Cell& operator=(const Cell & rhs);

	bool IsEmpty();
	bool IsSymbol(char c);
	bool IsColor(int c);

	int GetColor();
	void SetColor(int color);

	void SetSymbol(Symbol s);
	void DeleteSymbol();

	friend ostream& operator<<(ostream& o, const Cell& c);
	
private:
	Symbol m_symbol;
	int m_level;
};

#endif