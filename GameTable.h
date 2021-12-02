#ifndef GAME_TABLE_H
#define GAME_TABLE_H

#include <fstream>
#include <vector>

#include "GameMaterials.h"
#include "GAME_CONSTANTS.h"
#include "StatKeeper.h"

using std::ofstream;

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

	TableLevel tableLevel;

	int tableID;

	int minBet;
	int maxBet;
	int betMultiple;

	int tableMinPlayers;
	int tableMaxPlayers;

	int tableMinDecks;
	int tableMaxDecks;

	int cashStartRatio;
	int cashRefillRatio;
	int tableStartCash;
	int tableCurrentCash;
	int tableRefillAmount;

	int playerPromotionThreshold;

	Dealer* tableAssignedDealer;
	vector<Player*> tableAssignedPlayers;
	Deck* tableCardsDeck;

	ofstream outfile;

	void BettingRound();
	void DealingRound();
	void PlayingRound();
	void ResultsRound(StatKeeper* statModule);
	void PlayerLoseLogistics(StatKeeper* statModule, Player* player);
	void PlayerWinLogistics(StatKeeper* statModule, Player* player);
	void PlayerDrawLogistics(StatKeeper* statModule, Player* player);
	void PrintHands();

	void PlayerPromotions();
	void CleanUp();

public:
	GameTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks, int startRatio, int refillRatio, int PromotionThreshold);
	~GameTable();

	bool AssignDealer(Dealer* in_dealer);
	bool DealerNeedsToRetire();
	Dealer* RemoveDealer();

	bool AddPlayer(Player* in_player);
	vector<Player*>& GetPlayersOnTable() { return tableAssignedPlayers; }

	bool GameReadyToStart();
	bool CanTakeMorePlayer();
	bool CanTakeADealer();

	Card HitMe();
	int PlaceBet();

	void PlayRound(StatKeeper* statModule);
	int TableLevel() { return (int)tableLevel; }
	int TableMinPlayers() { return tableMinPlayers; }

	bool NeedCashRefill();
	int TopUpAmount();
	void DepositCash(int amount);

	int GetCurrentCash() { return tableCurrentCash; }

};


#endif /* GAME_TABLE_H */

