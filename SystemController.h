#ifndef SYSTEM_CONTROLLER_H
#define SYSTEM_CONTROLLER_H

#include <vector>

#include "TrafficGen.h"
#include "GAME_CONSTANTS.h"


class SystemController
{
	enum Level
	{
		L1, L2, L3, L4, L5
	};

	long int& CashReserve;

	TrafficGen* TrafficGenModule;

	vector<Player*>& InitialPlayerBase; // used as player queue
	vector<Dealer*>& DealerBase; // used as dealer queue/lounge
	vector<GameTable*>& Tables;

	vector<Player*>& QuitPlayers;
	vector<Player*>& HallOfFame;

	vector<Player*> L1Q;
	vector<Player*> L2Q;
	vector<Player*> L3Q;
	vector<Player*> L4Q;

	void sortPlayers();

	void populateTables();
	void playRoundOnAllTables();
	void refillTables();
	void retireDealers();
	void quitPlayers();
	void retrieveAllPlayers();
	int getActivePlayers();
	bool endPlay();

public:
	SystemController(long int& CashReserve, TrafficGen* TrafficGen, vector<Player*>& PlayerBase, vector<Dealer*>& Dealerbase, vector<GameTable*>& TableBase, vector<Player*> QuitPlayers, vector<Player*> HallOfFame);

	void Init();
	void StartSimulation();
	void EndSimulation();
};


#endif /* SYSTEM_CONTROLLER_H */
