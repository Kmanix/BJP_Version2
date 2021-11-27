#include "ColorGameTable.h"

#include "StrategyPlayer.h"
#include "Dealer.h"


// RED ////////////////////////////////
RedTable::RedTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks, int in_StartRatio, int in_refillRatio) 
	: GameTable(in_ID, in_minPlayers, in_maxPlayers, in_minDecks, in_maxDecks, in_StartRatio, in_refillRatio)
{
	Level = Red;

	minBet = RED_MIN_BET;
	maxBet = RED_MAX_BET;
	betMultiple = RED_BET_MULTIPLE;

	TableStartCash = startRatio * maxBet;
	TableCurrentCash = TableStartCash;
	TableRefillAmount = (int)(TableStartCash * ((float)refillRatio / startRatio));
}


// GREEN ////////////////////////////////
GreenTable::GreenTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks, int in_StartRatio, int in_refillRatio) 
	: GameTable(in_ID, in_minPlayers, in_maxPlayers, in_minDecks, in_maxDecks, in_StartRatio, in_refillRatio)
{
	Level = Green;

	minBet = GREEN_MIN_BET;
	maxBet = GREEN_MAX_BET;
	betMultiple = GREEN_BET_MULTIPLE;

	TableStartCash = startRatio * maxBet;
	TableCurrentCash = TableStartCash;
	TableRefillAmount = (int)(TableStartCash * ((float)refillRatio / startRatio));
}


// BLACK ////////////////////////////////
BlackTable::BlackTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks, int in_StartRatio, int in_refillRatio) 
	: GameTable(in_ID, in_minPlayers, in_maxPlayers, in_minDecks, in_maxDecks, in_StartRatio, in_refillRatio)
{
	Level = Black;

	minBet = BLACK_MIN_BET;
	maxBet = BLACK_MAX_BET;
	betMultiple = BLACK_BET_MULTIPLE;

	TableStartCash = startRatio * maxBet;
	TableCurrentCash = TableStartCash;
	TableRefillAmount = (int)(TableStartCash * ((float)refillRatio / startRatio));
}


// BLUE ////////////////////////////////
BlueTable::BlueTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks, int in_StartRatio, int in_refillRatio) 
	: GameTable(in_ID, in_minPlayers, in_maxPlayers, in_minDecks, in_maxDecks, in_StartRatio, in_refillRatio)
{
	Level = Blue;

	minBet = BLUE_MIN_BET;
	maxBet = BLUE_MAX_BET;
	betMultiple = BLUE_BET_MULTIPLE;

	TableStartCash = startRatio * maxBet;
	TableCurrentCash = TableStartCash;
	TableRefillAmount = (int)(TableStartCash * ((float)refillRatio / startRatio));
}

