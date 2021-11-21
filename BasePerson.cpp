#include "BasePerson.h"

BasePerson::BasePerson(int in_ID) // a constructor of person that has
{
	ID = in_ID; // intializing player ID# 
	TableNumber = -1; // intializing a defult table number 
	assignedTable = nullptr;  // intializing poiter to point to empty table

	RoundLimit = ROUND_LIMIT; // intializing the round limit to the number of limit that is in (GAME_CONSTANT.h)
	RoundsPlayed = 0; // intializing the round of game to 0

	StartCash = 0; // intializing the starting cash to 0
	CurrentCash = 0;  // intializing the current cash to 0

}

void BasePerson::Win()
{
	TrackRecord.push_back('W'); // adding the winning to the vector trackRecord
	RoundsPlayed++;  // increasing the number of the round
}

void BasePerson::Lose()
{
	TrackRecord.push_back('L');// adding the losing to the vector trackRecord
	RoundsPlayed++;   // increasing the number of the round
}

GameTable* BasePerson::getGameTable() // a method to get a table from the table class by
{
	return assignedTable;  // returning the address that the table point to
}

void BasePerson::setGameTable(GameTable* in_table)  // a method to set up a table from the table class by
{
	if (in_table != nullptr) // checking first if the table exist 
		assignedTable = in_table;  // assigned the table by its ID#  
}

void BasePerson::clearGameTable()   // reseting the table by assigning it to NULL 
{
	assignedTable = nullptr;
}

void BasePerson::addCard(Card c) // adding cards to the hand of a player 
{
	hand.push_back(c);
}

int BasePerson::GetHandscore() // a method to get hand score of each card that is in the player's hand
{
	int hs = 0;  // intiailizing the hand score to 0
	for (auto& c : hand) // go  for loop to each card in the hand
	{
		int rank = c.getRank();  // get the value of each rank of cards : 2,3,4,5,6,7,8,9,10
		if (rank >= 2 && rank <= 10) // for non-ace cards // check if the score of cards is :2,3,4,5,6,7,8,9,10
		{
			hs += rank; // add the ace as one
		}
		else // for ace cards
		{
			if ((11 + hs) > 21) // if ace will bust, use rank 1
			{
				hs += 1;
			}
			else // if ace wont bust, use rank 11
			{
				hs += 11;
			}
		}
	}
	return hs;
}

void BasePerson::resetHand() // clearing the cards that in the game 
{
	hand.clear();  // by using .clear() method in the "vector"
}

int BasePerson::ProfitLoss() // checking the amount of the money that a player was lost
{
	return StartCash - CurrentCash;
}

