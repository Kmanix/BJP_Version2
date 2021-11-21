#include "Player.h"

Player::Player(int in_ID, int in_Level) // define the player construstor and using the parent class to take care of
	: BasePerson(in_ID) // player's or dealer's id
{
	Level = in_Level; // intialize the level of a player
	betAmount = 0; // intialize the bet amount
}

int Player::Bet()
{
	// a player bets based on the placeBet() method that in the GameTable class by using the GameTable pointer
	// that in the BasePerson class, which is the parent class of the player class, to point to the PlaceBet() method
	// and use it for specefic player based on the color of the table that the player is playing on 
	betAmount = assignedTable->PlaceBet();
}

bool Player::Play(int Handscore)
{
	return false;
}

bool Player::QuittingBehaviour()
{
	return false;
}
