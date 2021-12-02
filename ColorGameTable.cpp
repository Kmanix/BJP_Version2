#include "ColorGameTable.h"

#include "StrategyPlayer.h"
#include "Dealer.h"


// RED ////////////////////////////////
RedTable::RedTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks, int in_StartRatio, int in_refillRatio, int in_PromotionThreshold)
	: GameTable(in_ID, in_minPlayers, in_maxPlayers, in_minDecks, in_maxDecks, in_StartRatio, in_refillRatio, in_PromotionThreshold)
{
	tableLevel = Red;

	minBet = RED_MIN_BET;
	maxBet = RED_MAX_BET;
	betMultiple = RED_BET_MULTIPLE;

	tableStartCash = cashStartRatio * maxBet;
	tableCurrentCash = tableStartCash;
	tableRefillAmount = (int)(tableStartCash * ((float)cashRefillRatio / cashStartRatio));
}


// GREEN ////////////////////////////////
GreenTable::GreenTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks, int in_StartRatio, int in_refillRatio, int in_PromotionThreshold)
	: GameTable(in_ID, in_minPlayers, in_maxPlayers, in_minDecks, in_maxDecks, in_StartRatio, in_refillRatio, in_PromotionThreshold)
{
	tableLevel = Green;

	minBet = GREEN_MIN_BET;
	maxBet = GREEN_MAX_BET;
	betMultiple = GREEN_BET_MULTIPLE;

	tableStartCash = cashStartRatio * maxBet;
	tableCurrentCash = tableStartCash;
	tableRefillAmount = (int)(tableStartCash * ((float)cashRefillRatio / cashStartRatio));
}


// BLACK ////////////////////////////////
BlackTable::BlackTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks, int in_StartRatio, int in_refillRatio, int in_PromotionThreshold)
	: GameTable(in_ID, in_minPlayers, in_maxPlayers, in_minDecks, in_maxDecks, in_StartRatio, in_refillRatio, in_PromotionThreshold)
{
	tableLevel = Black;

	minBet = BLACK_MIN_BET;
	maxBet = BLACK_MAX_BET;
	betMultiple = BLACK_BET_MULTIPLE;

	tableStartCash = cashStartRatio * maxBet;
	tableCurrentCash = tableStartCash;
	tableRefillAmount = (int)(tableStartCash * ((float)cashRefillRatio / cashStartRatio));
}


// BLUE ////////////////////////////////
BlueTable::BlueTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks, int in_StartRatio, int in_refillRatio, int in_PromotionThreshold)
	: GameTable(in_ID, in_minPlayers, in_maxPlayers, in_minDecks, in_maxDecks, in_StartRatio, in_refillRatio, in_PromotionThreshold)
{
	tableLevel = Blue;

	minBet = BLUE_MIN_BET;
	maxBet = BLUE_MAX_BET;
	betMultiple = BLUE_BET_MULTIPLE;

	tableStartCash = cashStartRatio * maxBet;
	tableCurrentCash = tableStartCash;
	tableRefillAmount = (int)(tableStartCash * ((float)cashRefillRatio / cashStartRatio));
}

