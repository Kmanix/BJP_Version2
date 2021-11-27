#include "SystemController.h"


SystemController::SystemController(TrafficGen* tg, vector<Player*>& pb, vector<Dealer*>& db, vector<GameTable*>& tb, vector<Player*> qp, vector<Player*> hf)
	: TrafficGenModule(tg), InitialPlayerBase(pb), DealerBase(db), Tables(tb), QuitPlayers(qp), HallOfFame(hf)
{
	// intialize the system
	Init();
}


void SystemController::Init()
{
	cout << "System Controller Initializing..." << endl;

	// intialize the traffic gen module
	TrafficGenModule->Init(USER_INPUT_FILE);

	// sort the players by levels
	sortPlayers();

	// begin simulation
	StartSimulation();
}


void SystemController::sortPlayers()
{
	while (InitialPlayerBase.size() > 0)
	{
		int playerLevel = InitialPlayerBase.back()->PlayerLevel();
		switch (playerLevel)
		{
		case L1: L1Q.push_back(InitialPlayerBase.back());
			break;
		case L2: L2Q.push_back(InitialPlayerBase.back());
			break;
		case L3: L3Q.push_back(InitialPlayerBase.back());
			break;
		case L4: L4Q.push_back(InitialPlayerBase.back());
			break;
		}
		InitialPlayerBase.pop_back();
	}
}


void SystemController::populateTables()
{
	for (auto& table : Tables)
	{
		// assign dealers
		if (table->CanTakeADealer() && DealerBase.size() > 0)
		{
			table->AssignDealer(DealerBase.back());
			DealerBase.pop_back();
		}

		// assign players
		bool flag = true;
		while (table->CanTakeMorePlayer() && flag)
		{
			flag = false;
			switch (table->TableLevel())
			{
			case L1:	if (L1Q.size() > 0)
			{
				table->AddPlayer(L1Q.back());
				L1Q.pop_back();
				flag = true;
				break;
			}

			case L2:	if (L2Q.size() > 0)
			{
				table->AddPlayer(L2Q.back());
				L2Q.pop_back();
				flag = true;
				break;
			}

			case L3:	if (L3Q.size() > 0)
			{
				table->AddPlayer(L3Q.back());
				L3Q.pop_back();
				flag = true;
				break;
			}

			case L4:	if (L4Q.size() > 0)
			{
				table->AddPlayer(L4Q.back());
				L4Q.pop_back();
				flag = true;
				break;
			}
			}
		}
	}
}


void SystemController::playRoundOnAllTables()
{
	for (auto& table : Tables)
	{
		table->PlayRound();
	}
}


void SystemController::StartSimulation()
{
	// start the simulation
	cout << endl << "Simulation has started!" << endl;

	// loop till end of player list, end of casino money, or not enough players
	while (true)
	{
		populateTables();

		playRoundOnAllTables();

		// promote players

		// remove players

		// retire dealers
	}

	EndSimulation();
}


void SystemController::EndSimulation()
{
	// end the simulation
	cout << endl << "Simulation has ended!" << endl;
}
