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

	Dealer* TableDealer;
	vector<Player*> TablePlayers;
	Deck* TableDeck;

	void BettingRound();
	void DealingRound();
	void PlayingRound();
	void ResultsRound();

public:
	GameTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks, int startRatio, int refillRatio);
	~GameTable();

	bool AssignDealer(Dealer* in_dealer);
	Dealer* RemoveDealer();

	bool AddPlayer(Player* in_player);
	Player* RemovePlayer();

	bool GameReadyToStart();
	bool CanTakeMorePlayer();
	bool CanTakeADealer();

	Card HitMe();
	int PlaceBet();

	void PlayRound();
	int TableLevel() { return Level; }

};


#endif /* GAME_TABLE_H */

