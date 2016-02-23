#include "PlayCells.h"
#include "Display.h"
#include "Card.h"

const int PlayCells::PlayAmount;

/**********************************************************************
* Purpose:	ctor
* Entry:	none
* Exit:		deck of cards is shuffled and allocated
************************************************************************/
PlayCells::PlayCells() : m_play(PlayAmount)
{}

/**********************************************************************
* Purpose:	copy ctor
* Entry: 	const PlayCells & copy
* Exit:		copied
************************************************************************/
PlayCells::PlayCells(const PlayCells & copy) : m_play(copy.m_play)
{}

/**********************************************************************
* Purpose:	dtor
* Entry:	none
* Exit:		mem dealloc
************************************************************************/
PlayCells::~PlayCells()
{
	Clear();
}

/**********************************************************************
* Purpose:
* Entry:
* Exit:		void
************************************************************************/
void PlayCells::Draw()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = DISPLAY::PLAY_UPPER_LEFT;
	COORD pos = position;
	// draw every column
	for (int i(0); i < PlayAmount; i++)
	{
		//reset position
		pos = position;

		// empty column
		if (m_play[i].Size() == 0)
			Card::DrawEmpty(position);
		else // not empty column
		{
			DStack<Card> temp = m_play[i];
			DStack<Card> to_draw;

			while (!temp.isEmpty())
			{
				to_draw.Push(temp.Pop());
			}
			while (!to_draw.isEmpty())
			{
				to_draw.Pop().Draw(position);
				position.Y += 2;
			}
		}
		// reset position
		position = DISPLAY::PLAY_UPPER_LEFT;
		// spacing
		position.X += ((i + 1) * 3) + ((i + 1) * 2);
	}
}

/**********************************************************************
* Purpose:	Deals cards into play area
* Entry: 	Deck deck
* Exit:		void
************************************************************************/
void PlayCells::DealGame(Deck deck)
{
	COORD pos = DISPLAY::PLAY_UPPER_LEFT;

	for (int i(0); i < Deck::MAXCARDS; i++)
	{
		// push deck at appropriate place
		m_play[i % PlayAmount].Push(deck[i]); 
		deck[i].Draw(pos);
		Sleep(40);

		// space it out
		pos.X = DISPLAY::PLAY_UPPER_LEFT.X + ((i + 1) % PlayAmount) * 3
			+ ((i + 1) % PlayAmount) * 2;

		if ((i % PlayAmount) == PlayAmount - 1)
			pos.Y += 2;
	}
}

/**********************************************************************
* Purpose:	returns stack of cards
* Entry: 	int col, int pos
* Exit:		DStack<Card>
************************************************************************/
DStack<Card> PlayCells::GetCards(int col, int pos)
{
	DStack<Card> ret;

	//empty
	if (m_play[col].Size() == 0)
		throw Exception("Cannot retrieve a card that doesn't exist.");
	else if (m_play[col].Size() <= pos || pos < 0)
		throw Exception("Out of bound getcards");
	// get one card
	else if (pos == m_play[col].Size() - 1)
		ret.Push(m_play[col].Peek()); // copy
	else // mult cards
	{
		DStack<Card> copy = m_play[col];
		Card ccard;

		// go through every card
		while (copy.Size() > pos)
		{
			// insert first
			if (ret.isEmpty())
			{
				ret.Push(copy.Pop());
			}
			else
			{
				ccard = copy.Pop();
				if (ccard.GetRank() == ret.Peek().GetRank() + 1
					&& ccard.IsRed() != ret.Peek().IsRed())
				{
					ret.Push(ccard);
				}
				else
				{
					throw Exception("GetCards: invalid (rank) (color)");
				}
			}
		}
	}
	return ret;
}

/**********************************************************************
* Purpose:	takes card away from m_play
* Entry: 	int col, int pos
* Exit:		void
************************************************************************/
void PlayCells::RemoveCards(int col, int pos)
{
	if (!m_play[col].isEmpty() && pos >= 0)
	{
		while (m_play[col].Size() > pos)
		{
			m_play[col].Pop();
		}
	}
}

/**********************************************************************
* Purpose:	adds stack of cards to play area
* Entry: 	DStack<Card> card, int col, int freecells
* Exit:		bool
************************************************************************/
bool PlayCells::AddCards(DStack<Card> card, int col, int freecells)
{
	bool valid = IsValid(col, card.Size(), freecells);

	// can place
	if (m_play[col].isEmpty() && valid)
	{
		// push to my stack
		while (!card.isEmpty())
			m_play[col].Push(card.Pop());
	}
	else if (valid)
	{
		Card bottom = m_play[col].Peek(), nucard = card.Peek();

		// check that the ranks are one apart from each otehr and that both aren't black/red
		if (bottom.GetRank() == nucard.GetRank() + 1 && bottom.IsRed() != nucard.IsRed())
		{
			while (!card.isEmpty())
				m_play[col].Push(card.Pop());
		}
		else
			valid = false;
	}
	return valid;
}

/**********************************************************************
* Purpose:
* Entry: 	int col, int ncards, int freecells
* Exit:		bool
************************************************************************/
bool PlayCells::IsValid(int col, int ncards, int freecells)
{
	int mt = 0;

	for (int i = 0; i < PlayAmount; i++)
	{
		if (m_play[i].isEmpty() && col != i)
			++mt;
	}

	double max = (freecells + 1) * (pow(2, mt));
	return max >= ncards;
}

/**********************************************************************
* Purpose:	sets all to empty
* Entry:
* Exit:		void
************************************************************************/
void PlayCells::Clear()
{
	DStack<Card> mt;
	for (int i = 0; i < PlayAmount; i++)
		m_play[i] = mt;
}

/**********************************************************************
* Purpose:	returns size of the column
* Entry: 	int col
* Exit:		int
************************************************************************/
int PlayCells::GetSize(int col)
{
	if (col < 0 || col >= PlayAmount)
		throw Exception("Cannot get size outside of stack");
	return m_play[col].Size();
}

/**********************************************************************
* Purpose:	this eqyal to rhs
* Entry: 	const PlayCells & rhs
* Exit:		PlayCells&
************************************************************************/
PlayCells& PlayCells::operator=(const PlayCells & rhs)
{
	if (this != &rhs)
		m_play = rhs.m_play;

	return *this;
}
