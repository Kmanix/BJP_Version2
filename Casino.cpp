#include "Casino.h"


Casino::Casino()
{
	cashReserve = CASINO_CASH;
	casinoStartCash = cashReserve;

	trafficGenModule = new TrafficGen(initialPlayerBase, dealerBase, casinoTables);
	
	statModule = new StatKeeper();
	
	sysCon = new SystemController(cashReserve, trafficGenModule,
		statModule, initialPlayerBase, dealerBase, casinoTables, quitPlayers, hallOfFame);
}


Casino::~Casino()
{
	// delete casino components
	delete trafficGenModule;
	delete statModule;
	delete sysCon;

	// delete player objects
	for (int i = 0; i < initialPlayerBase.size(); i++)
	{
		delete initialPlayerBase[i];
	}
	initialPlayerBase.clear();

	// delete dealer objects
	for (int i = 0; i < dealerBase.size(); i++)
	{
		delete dealerBase[i];
	}
	dealerBase.clear();

	// delete table objects
	for (int i = 0; i < casinoTables.size(); i++)
	{
		delete casinoTables[i];
	}
	casinoTables.clear();

	// delete Quit Players objects
	for (int i = 0; i < quitPlayers.size(); i++)
	{
		delete quitPlayers[i];
	}
	quitPlayers.clear();

	// delete Hall Of Fame objects
	for (int i = 0; i < hallOfFame.size(); i++)
	{
		delete hallOfFame[i];
	}
	hallOfFame.clear();
}
