
#include "Score.h"


/**********************************************************************
* Purpose:	Default constructor
*
* Entry:	None
*
* Exit:		Score created
************************************************************************/
Score::Score() : m_score(0)
{

}

/**********************************************************************
* Purpose:	copy constructor. This is set equal to copy.
*
* Entry:	const Score & copy
*
* Exit:		this is set to copy.
************************************************************************/
Score::Score(const Score & copy)
{
	*this = copy;
}

/**********************************************************************
* Purpose:	Destructor
*
* Entry:	None
*
* Exit:		Set to initial conditions
************************************************************************/
Score::~Score()
{
	m_score = 0;
}

/**********************************************************************
* Purpose:	Adds to score 5 * sides_touched
*
* Entry:	int sides_touched
*
* Exit:		m_score changed.
************************************************************************/
void Score::Add(int sides_touched)
{
	m_score += (sides_touched * 5);
}

/**********************************************************************
* Purpose:	Returns score
*
* Entry:	none
*
* Exit:		int score
************************************************************************/
int Score::GetScore()
{
	return m_score;
}

/**********************************************************************
* Purpose:	Sets this to rhs
*
* Entry:	const Score & rhs
*
* Exit:		this is set to rhs
************************************************************************/
Score& Score::operator=(const Score & rhs)
{
	if (this != &rhs)
	{
		m_score = rhs.m_score;
	}

	return *this;
}

/**********************************************************************
* Purpose:	overloads the output operator so that score can be
*			printed using native syntax.
*
* Entry:	const Score & rhs
*
* Exit:		m_score printed to screen.
************************************************************************/
ostream& operator<<(ostream& o, const Score & s)
{
	o << s.m_score;

	return o;
}