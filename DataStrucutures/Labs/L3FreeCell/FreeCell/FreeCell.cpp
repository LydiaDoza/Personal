#include "FreeCell.h"
#include "Exception.h"
/**********************************************************************
* Purpose:	Default ctor
* Entry:	initializes member data
* Exit:		data members initialized
************************************************************************/
FreeCell::FreeCell() : m_cells(4), m_empty(4)
{
	for (int i(0); i < m_empty.GetLength(); i++)
		m_empty[i] = true; // starts all true
}

/**********************************************************************
* Purpose:	copy ctor
* Entry: 	const FreeCell & copy
* Exit:
************************************************************************/
FreeCell::FreeCell(const FreeCell & copy)
{	*this = copy;   }

/**********************************************************************
* Purpose:	dtor
* Entry:	none
* Exit:		memory deallocated
************************************************************************/
FreeCell::~FreeCell()
{
	Clear();
}

/**********************************************************************
* Purpose:	returns the number of empty free cells
* Entry:	none
* Exit:		int
************************************************************************/
int FreeCell::GetEmpty()
{
	int numEmpty(0);

	for (int i(0); i < 4; i++)
		if (m_empty[i])
			++numEmpty;

	return numEmpty;
}

/**********************************************************************
* Purpose:	Clears all free cells
* Entry:	None
* Exit:		void
************************************************************************/
void FreeCell::Clear()
{
	for (int i(0); i < 4; i++)
		m_empty[i] = true;
}

/**********************************************************************
* Purpose:	Displays the free cells to the board.
* Entry:	None.
* Exit:		free cells drawn to board.
************************************************************************/
void FreeCell::Draw()
{
	
}

/**********************************************************************
* Purpose:	adds card to cell. returns if success.
* Entry: 	Card card, int i
* Exit:		bool
************************************************************************/
bool FreeCell::AddCard(Card card, int i)
{
	bool success = m_empty[i];
	if (success)
	{
		// add card
		m_cells[i] = card;
		// no longer empty
		m_empty[i] = false;
	}
	return success;
}

/**********************************************************************
* Purpose:	returns true if cell is empty
* Entry: 	int i
* Exit:		bool
************************************************************************/
bool FreeCell::IsEmpty(int i)
{
	return m_empty[i];
}

/**********************************************************************
* Purpose:	Returns card at i without turning to empty
* Entry: 	int i
* Exit:		Card
************************************************************************/
Card FreeCell::PeekCard(int i)
{
	if (m_empty[i])
		throw Exception("ERROR: cell is empty, cannot PeekCard.");
	
	return m_cells[i];
}

/**********************************************************************
* Purpose:	makes cell at i empty
* Entry: 	int i
* Exit:		void
************************************************************************/
void FreeCell::EmptyCell(int i)
{
	m_empty[i] = true;
}

/**********************************************************************
* Purpose:	copies rhs into this.
* Entry: 	const FreeCell & rhs
* Exit:		FreeCell&
************************************************************************/
FreeCell& FreeCell::operator=(const FreeCell & rhs)
{
	if (this != &rhs)
	{
		m_cells = rhs.m_cells;
		m_empty = rhs.m_empty;
	}
	return *this;
}
