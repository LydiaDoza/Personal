/***********************************************************
* Class:			Score
* 		
* Managers:
* 	Score
* 		Default constructor
*	Score(const Score & copy)
* 		Copy Ctor
*	~Score
*		Destructor
* 	void operator=(const Score & rhs)
*		Overload the = operator
*
* Public Methods:
*	void Add(int sides_touched)
*		adds to score
*	friend ostream& operator<<(ostream& o, const Score & s)
*		overloads output operator so that score can just be
*		printed using native syntax.
*	int GetScore()
*		Returns score number
************************************************************/
#ifndef SCORE_H
#define SCORE_H

#include <iostream>
using std::ostream;

class Score
{
public:
	Score();
	Score(const Score & copy);
	~Score();
	
	Score& operator=(const Score & rhs);

	void Add(int sides_touched);
	
	friend ostream& operator<<(ostream& o, const Score & s);
	int GetScore();
	
private:
	int m_score;
};

#endif