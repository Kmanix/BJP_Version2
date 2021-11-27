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
	SystemController* SysCon;
	TrafficGen* TraffGen;
	StatKeeper* SK;

	vector<Player*> InitialPlayerBase;
	vector<Dealer*> DealerBase;
	vector<GameTable*> Tables;

	vector<Player*> QuitPlayers;
	vector<Player*> HallOfFame;

public:
	Casino();
	~Casino();
};


#endif /* CASINO_H */