#ifndef GAME_TABLE_H
#define GAME_TABLE_H


#include <vector>

#include "GameMaterials.h"
#include "GAME_CONSTANTS.h"


// forward declarations
class Player;
class Dealer;


// BASE TABLE ////////////////////////////////
class GameTable
{
protected:
	enum TableLevel
	{
		Red, Green, Black, Blue
	};

	TableLevel Level;

	int TableID;

	int minBet;
	int maxBet;
	int betMultiple;

	int minPlayers;
	int maxPlayers;

	int minDecks;
	int maxDecks;

	int startRatio;
	int refillRatio;
	int TableStartCash;
	int TableCurrentCash;
	int TableRefillAmount;

	int PromotionThreshold;

	Dealer* TableDealer;
	vector<Player*> TablePlayers;
	Deck* TableDeck;

	void BettingRound();
	void DealingRound();
	void PlayingRound();
	void ResultsRound();

	void PlayerPromotions();

public:
	GameTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks, int startRatio, int refillRatio, int PromotionThreshold);
	~GameTable();

	bool AssignDealer(Dealer* in_dealer);
	bool DealerNeedsToRetire();
	Dealer* RemoveDealer();

	bool AddPlayer(Player* in_player);
	vector<Player*>& GetPlayersOnTable() { return TablePlayers; }

	bool GameReadyToStart();
	bool CanTakeMorePlayer();
	bool CanTakeADealer();

	Card HitMe();
	int PlaceBet();

	void PlayRound();
	int TableLevel() { return Level; }

	bool needCashRefill();
	int topUpAmount();
	void depositCash(int amount);

};


#endif /* GAME_TABLE_H */

