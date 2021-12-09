#ifndef SYSTEM_CONTROLLER_H
#define SYSTEM_CONTROLLER_H

#include <vector>

#include "TrafficGen.h"
#include "StatKeeper.h"
#include "GAME_CONSTANTS.h"


class SystemController
{
	enum Level
	{
		L1, L2, L3, L4, L5
	};

	long int& cashReserve;

	TrafficGen* trafficGenModule;
	StatKeeper* statModule;

	vector<Player*>& initialPlayerBase; // used as player queue
	vector<Dealer*>& dealerBase; // used as dealer queue/lounge
	vector<GameTable*>& casinoTables;

	vector<Player*>& quitPlayers;
	vector<Player*>& hallOfFame;

	vector<Player*> level1Q;
	vector<Player*> level2Q;
	vector<Player*> level3Q;
	vector<Player*> level4Q;

	void SortPlayers();

	void PopulateTables();
	void PlayRoundOnAllTables();
	void RefillTables();
	void RetireDealers();
	void RetirePlayers();
	void RetrieveAllPlayers();
	int MinPlayersRequirement();
	bool EndPlay();

public:
	SystemController(long int& CashReserve, TrafficGen* TrafficGen, StatKeeper* statModule,
		vector<Player*>& PlayerBase, vector<Dealer*>& Dealerbase, vector<GameTable*>& TableBase,
		vector<Player*> QuitPlayers, vector<Player*> HallOfFame);
	~SystemController();

	void Init();
	void StartSimulation();
	void EndSimulation();
};


#endif /* SYSTEM_CONTROLLER_H */