#include "SystemController.h"


SystemController::SystemController(long int& cr, TrafficGen* tg, vector<Player*>& pb, vector<Dealer*>& db, vector<GameTable*>& tb, vector<Player*> qp, vector<Player*> hf)
	: CashReserve(cr), TrafficGenModule(tg), InitialPlayerBase(pb), DealerBase(db), Tables(tb), QuitPlayers(qp), HallOfFame(hf)
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


void SystemController::refillTables()
{
	for (auto& table : Tables)
	{
		if (table->needCashRefill())
		{
			int amount = table->topUpAmount();
			if ((CashReserve - amount) >= 0)
			{
				CashReserve -= amount;
				table->depositCash(amount);
			}
		}
	}
}


void SystemController::retireDealers()
{
	for (auto& table : Tables)
	{
		if (table->DealerNeedsToRetire())
		{
			DealerBase.insert(DealerBase.begin(), table->RemoveDealer());
		}
	}
}


void SystemController::quitPlayers()
{
	for (auto& table : Tables)
	{
		vector<Player*>& TablePlayers = table->GetPlayersOnTable();
		for (auto& player : TablePlayers)
		{
			if (player->QuittingBehaviour())
			{
				QuitPlayers.push_back(player);
				remove(TablePlayers.begin(), TablePlayers.end(), player);
			}
		}
	}
}


void SystemController::retrieveAllPlayers()
{
	for (auto& table : Tables)
	{
		vector<Player*>& TablePlayers = table->GetPlayersOnTable();
		for (auto& player : TablePlayers)
		{
			switch (player->PlayerLevel())
			{
				case L1:	L1Q.push_back(player);
							remove(TablePlayers.begin(), TablePlayers.end(), player);
							break;

				case L2:	L2Q.push_back(player);
							remove(TablePlayers.begin(), TablePlayers.end(), player);
							break;

				case L3:	L3Q.push_back(player);
							remove(TablePlayers.begin(), TablePlayers.end(), player);
							break;

				case L4:	L4Q.push_back(player);
							remove(TablePlayers.begin(), TablePlayers.end(), player);
							break;

				case L5:	HallOfFame.push_back(player);
							remove(TablePlayers.begin(), TablePlayers.end(), player);
							break;
			}
		}
	}
}


int SystemController::getActivePlayers()
{
	int activePlayers = L1Q.size() + L2Q.size() + L3Q.size() + L4Q.size();
	return activePlayers;
}


bool SystemController::endPlay()
{
	if (CashReserve < CASINO_BROKE_CASH)
		return true;

	if (getActivePlayers() < MIN_PLAYERS)
		return true;

	return false;
}


void SystemController::StartSimulation()
{
	// start the simulation
	cout << endl << "Simulation has started!" << endl;

	// loop till end of player list, end of casino money, or not enough players
	while (true)
	{
		// game setup
		populateTables();

		// game
		playRoundOnAllTables();

		// cleanup
		refillTables();
		retireDealers();
		quitPlayers();
		retrieveAllPlayers();

		// end play
		if (endPlay())
			break;
	}

	EndSimulation();
}


void SystemController::EndSimulation()
{
	// end the simulation
	cout << endl << "Simulation has ended!" << endl;
}

