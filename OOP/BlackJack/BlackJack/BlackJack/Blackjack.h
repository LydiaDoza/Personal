/************************************************************************
*                    We're no strangers to love
* Class: Blackjack
*
* Constructors:
*	Blackjack()
*		initializes m_bet to zero
*	Blackjack(int bankroll)
*		initializes m_player's purse to bankroll
*	Blackjack(const Blackjack & blackjack)
*		copies this to blackjack
*
* Destructors:
*	~Blackjack()
*		resets m_bet to zero
* 
* Public methods are commented below.
*************************************************************************/
#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Deck.h"
#include "Dealer.h"
#include "Player.h"


class Blackjack
{
public:
	Blackjack();
	Blackjack(int bankroll);
	Blackjack(const Blackjack & blackjack);
	~Blackjack();

	Blackjack& operator=(const Blackjack & blackjack);

	void StartPrompt();			// reads in option selection
	void DisplayStartMenu();	// displays options
	void HitStandQuitMenu();	// displays options

	void DealCardPlayer();		// add a card to player hand
	void DealCardDealer();		// Add a card to dealer hand

	void StartGame();			// The bulk of the games logic is here
	void HitStandQuitPrompt(bool & gameover);
								// reads in option selection

	void SetBet();		// allows player to set the bet
	void DoubleDown();	// allows player to double down on 10 or 11
			
	void DisplayPlayerHand();	//shows all cards in player hand
	void DisplayDealerCard();	// shows faceup card during game
	void DisplayDealerHand();	// shows all cards at end of game

	bool IsTwentyOne(Player person);	// if hand value == 21, then true
	bool OverTwentyOne(Player person);  // if hand value >= 21, then true
	
	void EndGame();						// determines winner

private:
	Deck m_deck;
	Dealer m_dealer;
	Player m_player;
	int m_bet;
};

#endif