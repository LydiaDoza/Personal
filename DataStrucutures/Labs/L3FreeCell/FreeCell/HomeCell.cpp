#include "HomeCell.h"

const int HomeCell::HomeAmount;

/**********************************************************************
* Purpose:	default ctor
* Entry:	none
* Exit:		init
************************************************************************/
HomeCell::HomeCell() : m_home(HomeAmount)
{
	for (int i = 0; i < HomeAmount; i++)
	{
		m_home[i] = new Stack<Card>(13);
	}
}

/**********************************************************************
* Purpose:	copy ctor
* Entry: 	const HomeCell & copy
* Exit:		this = copy
************************************************************************/
HomeCell::HomeCell(const HomeCell & copy)
{
	for (int i = 0; i < HomeAmount; i++)
	{
		m_home[i] = new Stack<Card>(13);
	}

	for (int i = 0; i < HomeAmount; i++)
	{
		*m_home[i] = *copy.m_home[i];
	}
}

/**********************************************************************
* Purpose:	dtor
* Entry:	none
* Exit:		mem dealloc
************************************************************************/
HomeCell::~HomeCell()
{
	for (int i = 0; i < HomeAmount; i++)
		delete m_home[i];
}

/**********************************************************************
* Purpose:	draw
* Entry:	none
* Exit:		void
************************************************************************/
void HomeCell::Draw()
{
	COORD pos = DISPLAY::HOME_UPPER_LEFT;
	for (int i = 0; i < HomeAmount; i++)
	{
		if (m_home[i]->Size() == 0)
			Card::DrawEmpty(pos);
		else
			m_home[i]->Peek().Draw(pos);

		pos.X += 3 + 2;
	}
}

/**********************************************************************
* Purpose:	true if full
* Entry:	none
* Exit:		bool
************************************************************************/
bool HomeCell::IsFull()
{
	bool full = true;

	for (int i = 0; i < HomeAmount && full; i++)
	{
		if (!m_home[i]->IsFull())
		{
			full = false;
		}
	}
	return full;
}

/**********************************************************************
* Purpose:	add card to home cell
* Entry: 	Card card
* Exit:		bool
************************************************************************/
bool HomeCell::Add(Card card)
{
	bool valid = true;

	if (card.GetRank() == Card::ACE ||
		(!m_home[card.GetSuit() - Card::HEART]->IsEmpty() &&
		(card.GetRank() == (m_home[card.GetSuit() - Card::HEART]->Peek().GetRank() + 1))))
	{
		m_home[card.GetSuit() - Card::HEART]->Push(card);
	}
	else
		valid = false;

	return valid;
}

/**********************************************************************
* Purpose:	clears
* Entry:	none
* Exit:		void
************************************************************************/
void HomeCell::Clear()
{
	for (int i = 0; i < HomeAmount; i++)
	{
		while (!m_home[i]->IsEmpty())
		{
			m_home[i]->Pop();
		}
	}
}

/**********************************************************************
* Purpose:	this = rhs
* Entry: 	const HomeCell & rhs
* Exit:		HomeCell&
************************************************************************/
HomeCell& HomeCell::operator=(const HomeCell & rhs)
{
	if (this != &rhs)
	{ 
		for (int i = 0; i < HomeAmount; i++)
		{
			*m_home[i] = *rhs.m_home[i];
		}
	}
	return *this;
}
