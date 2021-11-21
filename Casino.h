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
	SystemController* SysCon; // declaring a system controller pointer that will create traffic generator object
	TrafficGen* TraffGen; // declaring a traffic generator pointer that will create player & table & dealer objects
	StatKeeper* SK; // declaring a statistic keeper pointer to handle counting the game statistic

	vector<Player*> InitialPlayerBase; // declaring a vector of pointers of base of platers
	vector<Dealer*> DealerBase; // declaring a vector of pointers of base of dealers
	vector<GameTable*> Tables;  // declaring a vector of pointers of base of tables
public:
	Casino();
	~Casino();
};

#endif /* CASINO_H */