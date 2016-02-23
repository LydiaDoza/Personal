
#include "Symbol.h"

const char m_symbols[8] = { 1, 3, 15, 235, 168, 30, 240, 145 };	// level 3
const int m_colors[7] = { 115, 117, 124, 125, 127, 112, 121 };	// level 3

/**********************************************************************
* Purpose:	Default Ctor. Sets the color to black on black. That way
*			no matter the symbol printed on the board will be black.
* Entry:	None.
* Exit:		None.
************************************************************************/
Symbol::Symbol() : m_color(7), m_symbol(' '), m_level(1)
{}

/**********************************************************************
* Purpose:	Sets m_symbol to sym and m_color to col
* Entry:	char sym, int col
* Exit:		Set symbol.
************************************************************************/
Symbol::Symbol(char sym, int col) : m_symbol(sym), m_color(col)
{}

/**********************************************************************
* Purpose:	3 arg constructor. sets m_symbol to sym, m_color to col,
*			m_level to level
* Entry:	char sym, int col, int level
* Exit:		Symbol Set.
************************************************************************/
Symbol::Symbol(char sym, int col, int level) : m_symbol(sym), m_color(col)
{}

/**********************************************************************
* Purpose:	One arg ctor. same as default, but initializes m_level to
*			level.
* Entry:	int level
* Exit:		None.
************************************************************************/
Symbol::Symbol(int level) : m_color(7), m_symbol(' '), m_level(level)
{	SetRandom();   }

/**********************************************************************
* Purpose:	Copy ctor. Copies data from copy to this.
* Entry:	const Symbol & copy
* Exit:		Members in this is set to copy.
************************************************************************/
Symbol::Symbol(const Symbol & copy) : m_color(115), m_symbol(3), m_level(1)
{	*this = copy;   }

/**********************************************************************
* Purpose:	dtor. Returns data members to original state.
* Entry:	None.
* Exit:		Members set to original state.
************************************************************************/
Symbol::~Symbol()
{
	m_color = 115;
	m_symbol = 3;
	m_level = 1;

	SetConsoleTextAttribute(handle, 7); // reset color to 7
}

/**********************************************************************
* Purpose:	Sets the symbol to a random symbol. Only allowed levels 1,
*			2, and 3 (other)
* Entry:	None.
* Exit:		Symbol set to random symbol. If a special symbol, the
*			color is set to special color.
************************************************************************/
void Symbol::SetRandom()
{
	int col = 0, sym = 0;
	char wildcard = 168;
	char bomb = 235;
	// do it a few times to get a real random number
	for (int i = 0; i < 4; i++)
	{
		if (m_level == 1)
		{
			col = rand.GetRandom(5); // 5 because we have 5 colors
			sym = rand.GetRandom(5);
		}
		else if (m_level == 2)
		{
			col = rand.GetRandom(6);
			sym = rand.GetRandom(6);
		}
		else
		{
			col = rand.GetRandom(7);
			sym = rand.GetRandom(7);
		}
	}

	m_symbol = m_symbols[sym];

	if (m_symbol == wildcard || m_symbol == bomb)
		SetSpecial();
	else
		m_color = m_colors[col];

	SetConsoleTextAttribute(handle, m_color);
}

/**********************************************************************
* Purpose:	Sets Symbols m_symbol to sym
* Entry:	char sym
* Exit:		m_symbol is set to sym.
************************************************************************/
void Symbol::SetSymbol(char sym)
{	m_symbol = sym;   }

/**********************************************************************
* Purpose:	Sets Symbol's m_color to color
* Entry:	int color
* Exit:		m_color is set to color
************************************************************************/
void Symbol::SetColor(int color)
{	m_color = color;   }

/**********************************************************************
* Purpose:	Sets level so that the appropriate number of charcters
*			and colors is chosen.
* Entry:	int level
* Exit:		level is set.
************************************************************************/
void Symbol::SetLevel(int level)
{	m_level = level;   }

/**********************************************************************
* Purpose:	Returns char Symbol
* Entry:	none
* Exit:		char symbol
************************************************************************/
char Symbol::GetSymbol()
{	return m_symbol;   }

/**********************************************************************
* Purpose:	Returns int color
* Entry:	none
* Exit:		int color
************************************************************************/
int Symbol::GetColor()
{	return m_color;   }

/**********************************************************************
* Purpose:	Sets m_color to bomb color or wildcard color
* Entry:	none.
* Exit:		m_color is set to bomb or wildcard color.
************************************************************************/
void Symbol::SetSpecial()
{
	char wildcard = 168;

	if (m_symbol == wildcard)
		m_color = 115;
	else
		m_color = 236;
}

/**********************************************************************
* Purpose:	returns true if wildcard.
* Entry:	char c
* Exit:		true or false
************************************************************************/
bool Symbol::isWildcard()
{	return (m_symbol == 168);   }

/**********************************************************************
* Purpose:	Returns true if bomb.
* Entry:	char c
* Exit:		true if bomb.
************************************************************************/
bool Symbol::isBomb()
{	return (m_symbol == 235);   }

/**********************************************************************
* Purpose:	Sets this to rhs
* Entry:	const Symbol & rhs
* Exit:		*this is set to rhs.
************************************************************************/
Symbol& Symbol::operator=(const Symbol & rhs)
{
	if (this != &rhs)
	{
		m_symbol = rhs.m_symbol;
		m_color = rhs.m_color;
		m_level = rhs.m_level;

		SetConsoleTextAttribute(handle, m_color);
	}
	return *this;
}

/**********************************************************************
* Purpose:	overloads ostream operator so that the symbols can be
*			printed using native syntax.
* Entry:	ostream& s, const Symbol & s
* Exit:		symbol is printed with it's right color.
************************************************************************/
ostream& operator<<(ostream& o, const Symbol& s)
{
	SetConsoleTextAttribute(s.handle, s.m_color);
	o << s.m_symbol;

	return o;
}