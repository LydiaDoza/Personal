/**************************************************************
*			We've known each other for so long
****************************************************************/
#include "Hand.h"

/**************************************************************
*	Name:
*		Hand()
*
*	Purpose:
*		Sets m_face_value to zero and calls the default ctor
*		for Linked m_cards
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Hand::Hand() : m_face_value(0), m_cards()
{

}

/**************************************************************
*	Name:
*		~Hand()
*
*	Purpose:
*		Deletes all nodes in hand and sets m_face_value to 0.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Hand::~Hand()
{
	m_cards.DeleteAllNodes();
	m_face_value = 0;
}

/**************************************************************
*	Name:
*		Hand(const Hand & hand)
*
*	Purpose:
*		Copy ctor. Copies stuff from hand to this.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Hand::Hand(const Hand & hand)
{
	m_cards = hand.m_cards;

}

/**************************************************************
*	Name:
*		GetFaceValue()
*
*	Purpose:
*		Returns value of all cards in hand.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
int Hand::GetFaceValue()
{
	int face_value(0);
	int aces(0);

	// Go through all the cards in hand (linked list) 
	for (int i = 0; i < m_cards.GetNumNodes(); i++)
	{
		// if card is an ace, increment num aces for check later.
		// At first, treat aces as one. After sum, then see if 
		// it can be treated as 11.
		if (m_cards.GetCard(i).GetRank() == Card::ACE) 
		{
			aces++;
			face_value += 1;
		}
		// if card is a face card add ten
		else if (m_cards.GetCard(i).GetRank() == Card::JACK
			|| m_cards.GetCard(i).GetRank() == Card::QUEEN
			|| m_cards.GetCard(i).GetRank() == Card::KING)
		{
			face_value += 10;
		}
		// otherwise, just add the value of the card
		else
		{
			face_value += m_cards.GetCard(i).GetRank();
		}
	}

	//now deal with the aces
	if (aces > 0)
	{
		// if face_value is 11 and under, treat the ace as
		// an 11. Since the ace has already been treated as
		// a one, just add 10.
		if (face_value < 12)
			face_value += 10;
	}

	m_face_value = face_value;

	return m_face_value;
}

/**************************************************************
*	Name:
*		DisplayCards()
*
*	Purpose:
*		Diplays all cards.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Hand::DisplayCards()
{
	m_cards.DisplayNodes();
}

/**************************************************************
*	Name:
*		DisplayFirstCard()
*
*	Purpose:
*		Displays first card in hand.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Hand::DisplayFirstCard() const
{
	m_cards.DisplayFirstNode();
}

/**************************************************************
*	Name:
*		Add()
*
*	Purpose:
*		Adds a card to hand.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Hand::Add(Card card)
{
	m_cards.Add(card);
}

/**************************************************************
*	Name:
*
*
*	Purpose:
*
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Hand::RemoveAll()
{
	m_cards.DeleteAllNodes();
}

/**************************************************************
*	Name:
*		GetCardCount()
*
*	Purpose:
*		Returns number of nodes
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
int Hand::GetCardCount()
{
	return m_cards.GetNumNodes();
}