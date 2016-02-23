
#include "Cell.h"

char m_start = 168;
int start_color = 115;

const char m_bomb = 235;
const int bomb_color = 236;

/**********************************************************************
* Purpose:	Default constructor. sets wildcard and bomb. assumes level
*			1. Sets m_symbol to random symbol.
*
* Entry:	None.
*
* Exit:		Cell created.
************************************************************************/
Cell::Cell() : m_symbol(' ', 7), m_level(1)
{

}

/**********************************************************************
* Purpose:	1 arg ctor. Sets m_level to level. symbol set to space.
*
* Entry:	int level
*
* Exit:		Cell is created.
************************************************************************/
Cell::Cell(int level) : m_level(level), m_symbol(' ')
{

}

/**********************************************************************
* Purpose:	Copy ctor. sets this to copy.
*
* Entry:	const Cell & copy
*
* Exit:		*this is set to copy.
************************************************************************/
Cell::Cell(const Cell & copy) : m_level(copy.m_level), m_symbol(copy.m_level)
{
	*this = copy;
}

/**********************************************************************
* Purpose:	Dtor. Since nothing is being newed, the other dtors handle
*			destroying themselves.
*
* Entry:	None.
*
* Exit:		None.
************************************************************************/
Cell::~Cell()
{
	m_symbol.SetSymbol(' '); 
}

/**********************************************************************
* Purpose:	Returns true if Cell is empty.
*
* Entry:	None.
*
* Exit:		true if empty, false if not.
************************************************************************/
bool Cell::IsEmpty()
{
	return (m_symbol.GetSymbol() == ' ');
}

/**********************************************************************
* Purpose:	Returns true if the symbol is the same as m_symbo.m_symbol
*
* Entry:	Symbol s
*
* Exit:		true or false
************************************************************************/
bool Cell::IsSymbol(char s)
{
	return (m_symbol.GetSymbol() == s);
}

/**********************************************************************
* Purpose:	Returns true if the color is the same as m_symbol.m_color
*
* Entry:	int c
*
* Exit:		true or false
************************************************************************/
bool Cell::IsColor(int c)
{
	return (m_symbol.GetColor() == c);
}

/**********************************************************************
* Purpose:	Returns color of cell.
*
* Entry:	None.
*
* Exit:		int representing color.
************************************************************************/
int Cell::GetColor()
{
	return m_symbol.GetColor();
}

/**********************************************************************
* Purpose:	Sets the color of the symbol and backgroudn
*
* Entry:	int color
*
* Exit:		color is changed.
************************************************************************/
void Cell::SetColor(int color)
{
	m_symbol.SetColor(color);
}

/**********************************************************************
* Purpose:	Sets m_symbol to s.
*
* Entry:	Symbol s
*
* Exit:		m_symbol is set to s.
************************************************************************/
void Cell::SetSymbol(Symbol s)
{
	m_symbol = s;
}

/**********************************************************************
* Purpose:	Sets m_symbol to ' ', essentially deleting it. Color
*			remains the same to keep background color.
*
* Entry:	None.
*
* Exit:		Symbol is set to ' '.
************************************************************************/
void Cell::DeleteSymbol()
{
	m_symbol.SetSymbol(' ');
}

/**********************************************************************
* Purpose:	Sets this to rhs.
*
* Entry:	const Cell & rhs
*
* Exit:		*this is set to rhs.
************************************************************************/
Cell& Cell::operator=(const Cell & rhs)
{
	if (this != &rhs)
	{
		m_symbol = rhs.m_symbol;
		m_level = rhs.m_level;
	}

	return *this;
}

/**********************************************************************
* Purpose:	over rides output operator.
*
* Entry:	ostream& o, const Cell& c
*
* Exit:		m_symbol is displayed.
************************************************************************/
ostream& operator<<(ostream& o, const Cell& c)
{
	o << c.m_symbol;

	return o;
}