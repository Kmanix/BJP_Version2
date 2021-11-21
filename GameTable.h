#ifndef GAME_TABLE_H
#define GAME_TABLE_H

#include <vector>

#include "Player.h"
#include "Dealer.h"
#include "GAME_CONSTANTS.h"

// BASE TABLE CLASS ////////////////////////////////
class GameTable
{
protected:
	int TableID; // holding the number of a table

	int minBet; // holding the minumum of the bet that in the project details Pdf file
	int maxBet; // holding the maximum of the bet that in the project details Pdf file
	int betMultiple; // holding the multinumber of the bet that in the project details Pdf file

	int minPlayers; // holding the minmum of players in one table
	int maxPlayers;  // holding the maximum of players in one table

	int minDecks;  // holding the minmum of decks in one table
	int maxDecks;   // holding the maximum of decks in one table

	Dealer* TableDealer;  // declaring a dealer pointer and using it to point to a dealer method
	vector<Player*> TablePlayers; // declaring a vector of players's pointers and using it to point to a player method
	Deck* TableDeck;  // declaring a deck pointer and using it to poit to a deck's method 

public:
	// declaring a table constructor that takes table number id min & max of players AND min & max of decks
	GameTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks);

	bool AssignDealer(Dealer* in_dealer); // assign dealer in a table by passing a dealer pointer to point to a dealer 
	Dealer* RemoveDealer();  // remove the dealer from the address that the dealer was pointed to

	bool AddPlayer(Player* in_player); // adding a player to  in a table by passing a player pointer to point to a player
	Player* RemovePlayer(); // remove the player from the address that the player was pointed to

	bool GameReadyToStart();  // set up the game to start  
	bool CanTakeMorePlayer(); // checking the number of player in a table
	bool CanTakeADealer();  // checking if there a dealer in a table

	void PlayRound();  // playing a game

	int PlaceBet(); // a bet for specific player in colored table

};

//child classes of table class
// RED ////////////////////////////////
class RedTable : public GameTable
{
public:
	RedTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks)
		: GameTable(in_ID, in_minPlayers, in_maxPlayers, in_minDecks, in_maxDecks)
	{
		minBet = RED_MIN_BET; // we take the amount of bet from GAME_CONSTANT header file
		maxBet = RED_MAX_BET;
		betMultiple = RED_BET_MULTIPLE;
	}
};


// GREEN ////////////////////////////////
class GreenTable : public GameTable
{
public:
	GreenTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks)
		: GameTable(in_ID, in_minPlayers, in_maxPlayers, in_minDecks, in_maxDecks)
	{
		minBet = GREEN_MIN_BET;
		maxBet = GREEN_MAX_BET;
		betMultiple = GREEN_BET_MULTIPLE;
	}
};


// BLACK ////////////////////////////////
class BlackTable : public GameTable
{
public:
	BlackTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks)
		: GameTable(in_ID, in_minPlayers, in_maxPlayers, in_minDecks, in_maxDecks)
	{
		minBet = BLACK_MIN_BET;
		maxBet = BLACK_MAX_BET;
		betMultiple = BLACK_BET_MULTIPLE;
	}
};


// BLUE ////////////////////////////////
class BlueTable : public GameTable
{
public:
	BlueTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks)
		: GameTable(in_ID, in_minPlayers, in_maxPlayers, in_minDecks, in_maxDecks)
	{
		minBet = BLUE_MIN_BET;
		maxBet = BLUE_MAX_BET;
		betMultiple = BLUE_BET_MULTIPLE;
	}
};

#endif /* GAME_TABLE_H */
