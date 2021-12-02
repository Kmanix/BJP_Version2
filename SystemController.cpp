#include "SystemController.h"


SystemController::SystemController(long int& cr, TrafficGen* tg, StatKeeper* sm, vector<Player*>& pb, vector<Dealer*>& db, vector<GameTable*>& tb, vector<Player*> qp, vector<Player*> hf)
	: cashReserve(cr), trafficGenModule(tg), statModule(sm), initialPlayerBase(pb), dealerBase(db), casinoTables(tb), quitPlayers(qp), hallOfFame(hf)
{
	// intialize the system
	Init();
}

SystemController::~SystemController()
{
	// delete player objects
	for (int i = 0; i < level1Q.size(); i++)
	{
		delete level1Q[i];
	}
	level1Q.clear();

	for (int i = 0; i < level2Q.size(); i++)
	{
		delete level2Q[i];
	}
	level2Q.clear();

	for (int i = 0; i < level3Q.size(); i++)
	{
		delete level3Q[i];
	}
	level3Q.clear();

	for (int i = 0; i < level4Q.size(); i++)
	{
		delete level4Q[i];
	}
	level4Q.clear();
}


void SystemController::Init()
{
	cout << "System Controller Initializing..." << endl;

	// intialize the traffic gen module
	trafficGenModule->Init(USER_INPUT_FILE);

	// sort the players by levels
	SortPlayers();

	// stat keeping
	statModule->SetCasinoStartAmount(cashReserve);

	// begin simulation
	StartSimulation();
}


void SystemController::SortPlayers()
{
	while (initialPlayerBase.size() > 0)
	{
		int playerLevel = initialPlayerBase.back()->PlayerLevel();
		switch (playerLevel)
		{
			case L1: level1Q.push_back(initialPlayerBase.back());
				break;
			case L2: level2Q.push_back(initialPlayerBase.back());
				break;
			case L3: level3Q.push_back(initialPlayerBase.back());
				break;
			case L4: level4Q.push_back(initialPlayerBase.back());
				break;
		}
		initialPlayerBase.pop_back();
	}
}


void SystemController::PopulateTables()
{
	for (auto& table : casinoTables)
	{
		// assign dealers
		if (table->CanTakeADealer() && dealerBase.size() > 0)
		{
			table->AssignDealer(dealerBase.back());
			dealerBase.back()->SetAssignedGameTable(table);
			dealerBase.pop_back();
		}

		// assign players
		bool flag = true;
		while (table->CanTakeMorePlayer() && flag)
		{
			flag = false;
			switch (table->TableLevel())
			{
				case L1:	if (level1Q.size() > 0)
							{
								table->AddPlayer(level1Q.back());
								level1Q.back()->SetAssignedGameTable(table);
								level1Q.pop_back();
								flag = true;
							}
							break;
					
				case L2:	if (level2Q.size() > 0)
							{
								table->AddPlayer(level2Q.back());
								level2Q.back()->SetAssignedGameTable(table);
								level2Q.pop_back();
								flag = true;
							}
							break;

				case L3:	if (level3Q.size() > 0)
							{
								table->AddPlayer(level3Q.back());
								level3Q.back()->SetAssignedGameTable(table);
								level3Q.pop_back();
								flag = true;	
							}
							break;

				case L4:	if (level4Q.size() > 0)
							{
								table->AddPlayer(level4Q.back());
								level4Q.back()->SetAssignedGameTable(table);
								level4Q.pop_back();
								flag = true;
							}
							break;
			}
		}
	}
}


void SystemController::PlayRoundOnAllTables()
{
	for (auto& table : casinoTables)
	{
		table->PlayRound(statModule);
	}
}


void SystemController::RefillTables()
{
	for (auto& table : casinoTables)
	{
		if (table->NeedCashRefill())
		{
			int amount = table->TopUpAmount();
			if ((cashReserve - amount) >= 0)
			{
				cashReserve -= amount;
				table->DepositCash(amount);
				statModule->DeductCasinoCash(amount);
			}
		}
	}
}


void SystemController::RetireDealers()
{
	for (auto& table : casinoTables)
	{
		if (table->DealerNeedsToRetire())
		{
			Dealer* retiredDealer = table->RemoveDealer();
			retiredDealer->ClearAssignedGameTable();
			dealerBase.insert(dealerBase.begin(), retiredDealer);
		}
	}
}


void SystemController::RetirePlayers()
{
	for (auto& table : casinoTables)
	{
		vector<Player*>& TablePlayers = table->GetPlayersOnTable();
		for (auto& player : TablePlayers)
		{
			if (player->QuittingBehaviour())
			{
				quitPlayers.push_back(player);
				player->SetQuit();
				player->ClearAssignedGameTable();
			}
		}
	}
}


void SystemController::RetrieveAllPlayers()
{
	for (auto& table : casinoTables)
	{
		vector<Player*>& TablePlayers = table->GetPlayersOnTable();
		for (auto& player : TablePlayers)
		{
			switch (player->PlayerLevel())
			{
				case L1:	if(!player->HasPlayerQuit())
								level1Q.push_back(player);
							break;

				case L2:	if (!player->HasPlayerQuit())
								level2Q.push_back(player);
							break;

				case L3:	if (!player->HasPlayerQuit())
								level3Q.push_back(player);
							break;

				case L4:	if (!player->HasPlayerQuit())
								level4Q.push_back(player);
							break;

				case L5:	if (!player->HasPlayerQuit())
								hallOfFame.push_back(player);
							break;
			}
			player->ClearAssignedGameTable();
		}
		TablePlayers.clear();
	}
}


int SystemController::MinPlayersRequirement()
{
	
	enum TableLevel
	{
		Red, Green, Black, Blue
	};

	int playableFlag = false;
	for (auto& table : casinoTables)
	{
		switch (table->TableLevel())
		{
			case Red:	if (level1Q.size() >= table->TableMinPlayers())
							playableFlag = true;
						break;

			case Green:	if (level2Q.size() >= table->TableMinPlayers())
							playableFlag = true;
						break;

			case Black:	if (level3Q.size() >= table->TableMinPlayers())
							playableFlag = true;
						break;

			case Blue:	if (level4Q.size() >= table->TableMinPlayers())
							playableFlag = true;
						break;
		}
	}

	return playableFlag;
}


bool SystemController::EndPlay()
{
	if (cashReserve < CASINO_BROKE_CASH)
		return true;

	if (!MinPlayersRequirement())
		return true;

	return false;
}


void SystemController::StartSimulation()
{
	// start the simulation
	cout << endl << "Simulation has started!" << endl;

	// loop till end of player list, end of casino money, or not enough players
	int round = 1;
	while (true)
	{
		cout << "ROUND: " << round++ << " ----------------" << endl;
		statModule->IncrementRound();

		// game setup
		PopulateTables();

		// game
		PlayRoundOnAllTables();

		// cleanup
		RefillTables();
		RetireDealers();
		RetirePlayers();
		RetrieveAllPlayers();

		// end play
		if (EndPlay() || round > MAX_ROUNDS)
			break;
		
	}

	EndSimulation();
}


void SystemController::EndSimulation()
{
	// end the simulation
	cout << endl << "Simulation has ended!" << endl;

	statModule->SetHallOfFamers((int)hallOfFame.size());
	statModule->SetQuitters((int)quitPlayers.size());

	statModule->PrintStats();
	statModule->PrintStatsToFile();
}

