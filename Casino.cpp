#include "Casino.h"


Casino::Casino()
{
	TraffGen = new TrafficGen(InitialPlayerBase, DealerBase, Tables);
	SK = new StatKeeper();
	SysCon = new SystemController(TraffGen, InitialPlayerBase, DealerBase, Tables, QuitPlayers, HallOfFame);
}


Casino::~Casino()
{
	// delete casino components
	delete TraffGen;
	delete SK;
	delete SysCon;

	// delete player objects
	for (int i = 0; i < InitialPlayerBase.size(); i++)
	{
		delete InitialPlayerBase[i];
	}
	InitialPlayerBase.clear();

	// delete dealer objects
	for (int i = 0; i < DealerBase.size(); i++)
	{
		delete DealerBase[i];
	}
	DealerBase.clear();

	// delete table objects
	for (int i = 0; i < Tables.size(); i++)
	{
		delete Tables[i];
	}
	Tables.clear();

	// delete player objects
	for (int i = 0; i < InitialPlayerBase.size(); i++)
	{
		delete InitialPlayerBase[i];
	}
	InitialPlayerBase.clear();

	// delete Quit Players objects
	for (int i = 0; i < QuitPlayers.size(); i++)
	{
		delete QuitPlayers[i];
	}
	QuitPlayers.clear();

	// delete Hall Of Fame objects
	for (int i = 0; i < HallOfFame.size(); i++)
	{
		delete HallOfFame[i];
	}
	HallOfFame.clear();
}

