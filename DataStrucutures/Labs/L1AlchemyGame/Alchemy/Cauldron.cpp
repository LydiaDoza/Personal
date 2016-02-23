#include "Cauldron.h"

/**********************************************************************
* Purpose:	Defulat ctor. Sets initial conditions. m_cauldron symbols
*			set to  ' '.
*
* Entry:	None.
*
* Exit:		m_discard uses symbol default ctor, discards set to 0
************************************************************************/
Cauldron::Cauldron() : m_discard(), discards(0)
{
	for (int i = 0; i < 4; i++)
	{
		m_discard[i].SetSymbol(' ');
		m_discard[i].SetColor(7);
	}
}

/**********************************************************************
* Purpose:	copy ctor
*
* Entry:	const Cauldron & copy
*
* Exit:		this is set to copy
************************************************************************/
Cauldron::Cauldron(const Cauldron & copy) : discards(copy.discards)
{
	*this = copy;
}

/**********************************************************************
* Purpose:	dtor. resets initial conditions. color is light grey on
*			black. character is space.
*
* Entry:	none
*
* Exit:		initial conditions set
************************************************************************/
Cauldron::~Cauldron()
{
	ClearCauldron();
}

/**********************************************************************
* Purpose:	Gets symbol at index
*
* Entry:	int index
*
* Exit:		symbol at index
************************************************************************/
char Cauldron::GetSymbol(int index)
{
	return m_discard[index].GetSymbol();
}

/**********************************************************************
* Purpose:	returns color of symbol at index in array m_discard
*
* Entry:	int index
*
* Exit:		int
************************************************************************/
int Cauldron::GetColor(int index)
{
	return m_discard[index].GetColor();
}

/**********************************************************************
* Purpose:	returns discards.
*
* Entry:	none
*
* Exit:		number of symbols discarded.
************************************************************************/
int Cauldron::GetDiscards()
{
	return discards;
}

/**********************************************************************
* Purpose:	Adds symbol to the cauldron
*
* Entry:	Symbol s
*
* Exit:		symbol added to the cauldron
************************************************************************/
void Cauldron::Discard(Symbol s)
{
	bool flag = false;
	for (int i = 0; i < 4 && !flag; i++)
	{
		if (m_discard[i].GetSymbol() == ' ')
		{
			m_discard[i].SetSymbol(s.GetSymbol());
			m_discard[i].SetColor(s.GetColor());
			discards++;
			flag = true;
		}
	}
}

/**********************************************************************
* Purpose:	Removes a symbol from the cauldron
*
* Entry:	None.
*
* Exit:		symbol removed
************************************************************************/
void Cauldron::Decrement()
{
	bool deleted = false;
	// check if there are symbols
	if (discards > 0)
	{
		// start from the large end
		for (int i = 3; i >= 0 && !deleted; i--)
		{
			// if a symbol is in the array
			if (m_discard[i].GetSymbol() != ' ')
			{
				deleted = true;
				m_discard[i].SetColor(7);
				m_discard[i].SetSymbol(' ');
			}
		}
	}
}

/**********************************************************************
* Purpose:	Clears Cauldron of all symbols and colors
*
* Entry:	none
*
* Exit:		cauldron emptied
************************************************************************/
void Cauldron::ClearCauldron()
{
	for (int i = 0; i < 4; i++)
	{
		m_discard[i].SetSymbol(' ');
		m_discard[i].SetColor(7);
	}
	discards = 0;
}

/**********************************************************************
* Purpose:	Sets this to rhs.
*
* Entry:	const Cauldron & rhs
*
* Exit:		this is set to rhs.
************************************************************************/
Cauldron& Cauldron::operator=(const Cauldron & rhs)
{
	if (this != &rhs)
	{
		discards = rhs.discards;
		for (int i = 0; i < 3; i++)
		{
			m_discard[i] = rhs.m_discard[i];
		}
	}

	return *this;
}
