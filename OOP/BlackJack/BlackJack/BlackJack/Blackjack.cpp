/**************************************************************
*               You know the rules and so do I!
****************************************************************/


#include "Blackjack.h"

/**************************************************************
*	Name:
*		Blackjack()
*
*	Purpose:
*		Calls default ctors for m_player, m_dealer, m_deck
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Blackjack::Blackjack() : m_player(), m_dealer(), m_deck(), m_bet(0)
{

}

/**************************************************************
*	Name:
*		Blackjack(int purse)
*
*	Purpose:
*		Gives m_player purse amount of money
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Blackjack::Blackjack(int purse) : m_bet(0)
{
	m_player.SetPurse(purse);
}

/**************************************************************
*	Name:
*		~Blackjack()
*
*	Purpose:
*		Dtor or whatever.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
Blackjack::~Blackjack()
{

}

/**************************************************************
*	Name:
*		Prompt()
*
*	Purpose:
*		Displays a menu and prompts user to do stuff.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Blackjack::StartPrompt()
{
	int choice(0);

	while (choice != 2)
	{

		DisplayStartMenu();
		cin >> choice;

		switch (choice)
		{
		case 1: // Start Game
			if (m_player.GetPurse() > 0)
				StartGame();
			else
			{
				cout << "\nYou no longer have any money. Go away." << endl;
				system("pause");
			}
			break;

		case 2: // Exit
			cout << "Good bye!" << endl;
			break;

		default:
			cout << "\nYou made an invalid choice. Please try again."
				<< endl;
			break;
		}
	}
}

/**************************************************************
*	Name:
*		DisplayStartMenu()
*
*	Purpose:
*		Displays menu to start a game or exit
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Blackjack::DisplayStartMenu()
{
	system("cls");
	cout << "\t*~*~* Welcome to Blackjack! *~*~*" << "\n\n"
		<< "1. Start New Game\n"
		<< "2. Exit" << endl;
}

/**************************************************************
*	Name:
*		HitStandQuitMenu()
*
*	Purpose:
*		Displays one card face up
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Blackjack::HitStandQuitMenu()
{
	cout << "1. Hit\n"
		<< "2. Stand\n"
		<< "3. Quit\n" << endl;

}

/**************************************************************
*	Name:
*		DealCardPlayer()
*
*	Purpose:
*		Deals a card to a player.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Blackjack::DealCardPlayer()
{
	m_player.AddCard(m_deck.Deal());
}

/**************************************************************
*	Name:
*		DealCardDealer()
*
*	Purpose:
*		Deals a card to dealer.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Blackjack::DealCardDealer()
{
	m_dealer.AddCard(m_deck.Deal());
}

/**************************************************************
*	Name:
*		StartGame()
*
*	Purpose:
*		Deals and displays cards to player for beginning of
*		game. Then calls display of next menu for next move.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Blackjack::StartGame()
{
	bool gameover = false;
	int double_down = 0; //used to make choice to double down

	cout << "\nYour money: " << m_player.GetPurse();
	SetBet();

	m_deck.Shuffle(); // Shuffle the cards first!!

	for (int i(0); i < 2; i++)
	{
		DealCardPlayer();
		DealCardDealer();
	}

	// NOW CHECK FOR BLACKJACK for both
	if (IsTwentyOne(m_player) && IsTwentyOne(m_dealer))
	{
		DisplayDealerHand();
		DisplayPlayerHand();
		cout << "\n\t***  Draw  ***"
			<< "\nBoth have blackjack" << endl;
		system("pause");
		StartPrompt();
	}
	else if (IsTwentyOne(m_player)) // if player has blackjack
	{
		DisplayDealerHand();
		DisplayPlayerHand();
		cout << "\n\t***  You got a BLACKJACK!!  ***\n"
			<< "\t\tCongrats, you win!" << endl;
		system("pause");
		m_player.AddToPurse(m_bet);
	}
	else if (IsTwentyOne(m_dealer)) // if dealer has blackjack
	{
		DisplayDealerHand();
		DisplayPlayerHand();
		cout << "\n\t***  Dealer got a BLACKJACK!!  ***\n"
			<< "\t\tSorry, you lose!" << endl;
		system("pause");
		m_player.SubFromPurse(m_bet);
	}

	//THEN ASK IF WANTS TO HIT/STAND. CHECK FOR DOUBLE DOWN
	else
	{
		//check if can double down
		if (m_player.GetHandValue() == 10 ||
			m_player.GetHandValue() == 11)
		{

			DisplayDealerCard();
			DisplayPlayerHand();
			cout << "\nYou have the option to Double Down."
				<< "\n1. Double Down"
				<< "\n2. Continue" << endl;
			cin >> double_down;


			if (double_down == 1) // wants to double down
			{
				DoubleDown();

				while (m_dealer.GetHandValue() < 17)
				{
					m_dealer.AddCard(m_deck.Deal());
				}

				DisplayDealerCard();
				DisplayPlayerHand();
				EndGame();
			}
		}
		else // cannot double down
		{
			DisplayDealerHand();
			DisplayPlayerHand();
			while (!gameover)
			{
				HitStandQuitPrompt(gameover);
			}
		}
	}


	m_player.DeleteCards();
	m_dealer.DeleteCards();
}

/**************************************************************
*	Name:
*		HitStandQuitPrompt()
*
*	Purpose:
*		Calls HitStandQuitMenu()
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Blackjack::HitStandQuitPrompt(bool & gameover)
{
	int choice = 0;

	while (choice != 3)
	{
		system("cls");
		DisplayDealerCard();
		DisplayPlayerHand();

		// either player or dealer is >= 21
		if (OverTwentyOne(m_player) ||
			OverTwentyOne(m_dealer) ||
			IsTwentyOne(m_player) ||
			IsTwentyOne(m_dealer))
		{
			EndGame();
			gameover = true;
			choice = 3;
		}
		// neither are over 21
		else
		{

			HitStandQuitMenu();
			cin >> choice;


			switch (choice)
			{
			case 1: // Hit			
				// add card to player
				if (m_player.GetHandValue() < 21)
					m_player.AddCard(m_deck.Deal());
				else if (m_player.GetHandValue() >= 21)
				{
					EndGame();
					choice = 3;
					gameover = true;
				}
				else if (OverTwentyOne(m_player))
				{
					EndGame();
					choice = 3;
					gameover = true;

				}

				break;

			case 2: //Stand

				while (m_dealer.GetHandValue() < 17)
				{
					m_dealer.AddCard(m_deck.Deal());
				}

				// check to see who wins. then add/sub bet
				EndGame();
				gameover = true;
				choice = 3;
				break;

			case 3: // Quit entirely
				gameover = true;
				break;
			default:
				break;
			}
		}
	}
}

/**************************************************************
*	Name:
*		SetBet()
*
*	Purpose:
*		Sets Bet for player
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Blackjack::SetBet()
{
	int bet = 0;

	while (bet <= 0 || bet > m_player.GetPurse())
	{
		cout << "\nWhat bet would you like to place? ";
		cin >> bet;


		if (bet <= 0)
			cout << "\nYou can't place a zero or negative bet." << endl;
		else if (bet > m_player.GetPurse())
		{
			cout << "\nYou can't bet more than you have!" << endl;
		}
	}

	m_bet = bet;
}

/**************************************************************
*	Name:
*		DoubleDown()
*
*	Purpose:
*		Allows player to double down. Bet is doubled (if there
*		is enough in players purse. Is dealt only one more card
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Blackjack::DoubleDown()
{
	if (m_player.GetPurse() >= m_bet * 2)
	{
		m_bet *= 2; // double the bet!!
		m_player.AddCard(m_deck.Deal());
	}
	else
	{
		cout << "You do not have enough in "
			<< "your bankroll to double down." << endl;
		system("pause");
	}

}


/**************************************************************
*	Name:
*		DisplayPlayerHand()
*
*	Purpose:
*		Displays all of the players cards
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Blackjack::DisplayPlayerHand()
{
	cout << "\n\n----  Your Hand  ----" << endl;
	m_player.DisplayCards();
	cout << "Total value: " << m_player.GetHandValue();
	cout << "\n---------------------\n" << endl;
}

/**************************************************************
*	Name:
*		DisplayDealerCard()
*
*	Purpose:
*		Displays one dealer card to screen.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Blackjack::DisplayDealerCard()
{
	cout << "\n\n----  Dealer  ----" << endl;
	m_dealer.DisplayOneCard();
	m_dealer.ShowFaceDown();
	cout << "\n------------------\n" << endl;
}

void Blackjack::DisplayDealerHand()
{
	cout << "\n\n----  Dealer  ----" << endl;
	m_dealer.DisplayCards();
	cout << "Total value: " << m_dealer.GetHandValue();
	cout << "\n------------------\n" << endl;
}

/**************************************************************
*	Name:
*		IsTwentyOne()
*
*	Purpose:
*		Returns true if total value in hand is twentyone.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
bool Blackjack::IsTwentyOne(Player person)
{
	bool is_twentyone = false;

	if (person.GetHandValue() == 21)
	{
		is_twentyone = true;
	}

	return is_twentyone;
}

/**************************************************************
*	Name:
*		OverTwentyOne()
*
*	Purpose:
*		Returns true if total value in hand is over twentyone.
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
bool Blackjack::OverTwentyOne(Player person)
{
	bool over_twentyone = false;

	if (person.GetHandValue() > 21)
		over_twentyone = true;

	return over_twentyone;
}

/**************************************************************
*	Name:
*		EndGame()
*
*	Purpose:
*		Checks
*
*	Entry:
*		None.
*
*	Exit:
*		None.
****************************************************************/
void Blackjack::EndGame()
{
	system("cls");

	DisplayDealerHand();
	DisplayPlayerHand();

	// dealer has more than player and dealer has less than 21
	if (m_dealer.GetHandValue() > m_player.GetHandValue() &&
		m_dealer.GetHandValue() <= 21)
	{
		m_player.SubFromPurse(m_bet);
		cout << "\n***  You lost.  ***\n"
			<< "\nYour money after losing: "
			<< m_player.GetPurse() << endl;
		system("pause");
	}

	// dealer has less than player and player has <= 21 OR
	// dealer has more than 21 and player has <= 21
	else if ((m_dealer.GetHandValue() < m_player.GetHandValue() &&
		m_player.GetHandValue() <= 21))
	{
		m_player.AddToPurse(m_bet);
		cout << "\n***  You won!  ***\n"
			<< "\nYour money after winning: "
			<< m_player.GetPurse() << endl;
		system("pause");
	}
	// dealer has over 21 and player has less than or equal to 21
	else if (OverTwentyOne(m_dealer) && m_player.GetHandValue() <= 21)
	{
		m_player.AddToPurse(m_bet);
		cout << "\n***  You won!  ***"
			<< "\n\nYour money after winning: "
			<< m_player.GetPurse() << endl;
		system("pause");
	}
	else if (m_player.GetHandValue() == m_dealer.GetHandValue())// tie
	{
		cout << "\nDraw" << endl;
		system("pause");
	}
	else // player has over 21
	{
		m_player.SubFromPurse(m_bet);
		cout << "\n***  You lost.  ***\n"
			<< "\nYour money after losing: "
			<< m_player.GetPurse() << endl;
		system("pause");
	}
}