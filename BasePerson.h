#ifndef BASE_PERSON_H
#define BASE_PERSON_H

#include <iostream>
#include <vector>

#include "GAME_CONSTANTS.h"
#include "GameTable.h"
#include "GameMaterials.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// parent class for dealer and players
class BasePerson
{
protected:
	int ID; // player or dealer ID#
	int TableNumber; 

	int StartCash; // the amount of the money to start with// we can use it in the losing behaviour
	int CurrentCash; // counting the current cash that a player have after play some game //  we can use it in the losing behaviour

	int RoundLimit; // limiting how many round of playing // we can use it in the losing behaviour 
	int RoundsPlayed; // counting how many round that played // we can use it in the losing behaviour

	vector<char> TrackRecord;  // holding the winning the losing of each player and count them

	GameTable* assignedTable; // create a table pointer to point to an table

	vector<Card> hand; // a vector of cards to hold the card in a hand

public:
	BasePerson(int in_ID); // declaring a constructor of parent class

	virtual int Bet() = 0;
	virtual bool Play(int Handscore) = 0;
	virtual bool QuittingBehaviour() = 0;
	virtual bool Strategy(int HandScore) = 0;

	virtual void Win(); 
	virtual void Lose();

	GameTable* getGameTable();  // a method that return a table pointer to get a table from the table class
	void setGameTable(GameTable* in_table); // a method to set up a table by pointing to specific table by its ID#
	void clearGameTable(); // a method of reseting the table

	void addCard(Card c); // a method to add card by passing the card memeber
	int GetHandscore(); // a method to count the hand card score 
	void resetHand(); // a method to reset the hand of cards 

	int ProfitLoss(); // a method to count the amount of the money that a player was lost
};

#endif /* BASE_PERSON_H */
