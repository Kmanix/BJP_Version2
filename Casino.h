#ifndef CASINO_H
#define CASINO_H


#include <vector>

#include "SystemController.h"
#include "TrafficGen.h"
#include "StatKeeper.h"

#include "Player.h"
#include "Dealer.h"
#include "GameTable.h"



class Casino
{
private:
	SystemController* sysCon;
	TrafficGen* trafficGenModule;
	StatKeeper* statModule;

	vector<Player*> initialPlayerBase;
	vector<Dealer*> dealerBase;
	vector<GameTable*> casinoTables;

	vector<Player*> quitPlayers;
	vector<Player*> hallOfFame;

	long int cashReserve;
	long int casinoStartCash;

public:
	Casino();
	~Casino();
};


#endif /* CASINO_H */