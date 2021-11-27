#include "TrafficGen.h"


TrafficGen::TrafficGen(vector<Player*>& pb, vector<Dealer*>& db, vector<GameTable*>& tb)
	: InitialPlayerBase(pb), DealerBase(db), Tables(tb)
{

	numTables = 0;
	minNumPlayer = 0;
	maxNumPlayer = 0;
	minNumDeck = 0;
	maxNumDeck = 0;

	numDealers = 0;
	dealerSalary = 0;
	dealerWinThreshold = 0;
	tableStartAmountRatio = 0;
	tableRefillAmountRatio = 0;

	numPlayers = 0;
	for (int i = 0; i < 4; i++)
	{
		transitionThreshold[i] = 0;
		stratDistr[i] = 0;
		for (int j = 0; j < 4; j++)
		{
			colorDistr[i][j] = 0;
		}
	}

	playerArrivalProb = 0.0;
}


void TrafficGen::Init(string filename)
{
	cout << "Traffic Generator Initializing..." << endl;
	LoadInputFile(filename);
	CreatePlayerBase();
	CreateDealerBase();
	CreateTables();
	cout << "Traffic Generator: DONE!" << endl;
}


void TrafficGen::LoadInputFile(string filename)
{
	ifstream infile(filename);
	if (infile.is_open())
	{
		string junk;

		cout << "Loading file:" << filename << endl;
		infile >> numTables;
		infile >> minNumPlayer;
		infile >> maxNumPlayer;
		infile >> minNumDeck;
		infile >> maxNumDeck;

		infile >> transitionThreshold[L1];
		infile >> transitionThreshold[L2];
		infile >> transitionThreshold[L3];
		infile >> transitionThreshold[L4];

		infile >> numDealers;
		infile >> dealerSalary;
		infile >> dealerWinThreshold;
		infile >> tableStartAmountRatio;
		infile >> tableRefillAmountRatio;

		infile >> numPlayers;

		infile >> stratDistr[Random];
		infile >> stratDistr[Mimic];
		infile >> stratDistr[Safe];
		infile >> stratDistr[Custom];

		infile >> junk;
		infile >> colorDistr[Random][L1];
		infile >> colorDistr[Random][L2];
		infile >> colorDistr[Random][L3];
		infile >> colorDistr[Random][L4];

		infile >> junk;
		infile >> colorDistr[Mimic][L1];
		infile >> colorDistr[Mimic][L2];
		infile >> colorDistr[Mimic][L3];
		infile >> colorDistr[Mimic][L4];

		infile >> junk;
		infile >> colorDistr[Safe][L1];
		infile >> colorDistr[Safe][L2];
		infile >> colorDistr[Safe][L3];
		infile >> colorDistr[Safe][L4];

		infile >> junk;
		infile >> colorDistr[Custom][L1];
		infile >> colorDistr[Custom][L2];
		infile >> colorDistr[Custom][L3];
		infile >> colorDistr[Custom][L4];

		infile >> playerArrivalProb;

		cout << "Loading user input file status: DONE." << endl;
		infile.close();
	}
	else
	{
		cout << "Error! User input file not found..." << endl;
		exit(1);
	}

}


void TrafficGen::CreatePlayerBase()
{
	cout << "Creating Players..." << endl;
	int roll = 0;
	StratType chosenStrat = Random;
	LevelType chosenLevel = L1;

	// set strategy limits
	int RandomLimit = stratDistr[Random];
	int MimicLimit = RandomLimit + stratDistr[Mimic];
	int SafeLimit = MimicLimit + stratDistr[Safe];
	int CustomLimit = SafeLimit + stratDistr[Custom];

	for (int i = 0; i < numPlayers; i++)
	{
		// roll for strategy
		roll = 1 + (rand() % 101);
		// choose strategy based on roll
		if (roll <= RandomLimit)
			chosenStrat = Random;
		else if (roll <= MimicLimit)
			chosenStrat = Mimic;
		else if (roll <= SafeLimit)
			chosenStrat = Safe;
		else if (roll <= CustomLimit)
			chosenStrat = Custom;

		// set color limits
		int L1Limit = colorDistr[chosenStrat][L1];
		int L2Limit = L1Limit + colorDistr[chosenStrat][L2];
		int L3Limit = L2Limit + colorDistr[chosenStrat][L3];
		int L4Limit = L3Limit + colorDistr[chosenStrat][L4];

		// roll for color
		roll = 1 + (rand() % 101);
		// choose color based on roll
		if (roll <= L1Limit)
			chosenLevel = L1;
		else if (roll <= L2Limit)
			chosenLevel = L2;
		else if (roll <= L3Limit)
			chosenLevel = L3;
		else if (roll <= L4Limit)
			chosenLevel = L4;

		switch (chosenStrat)
		{
		case Random: InitialPlayerBase.push_back(new RandomPlayer(i, chosenLevel));
			break;
		case Mimic: InitialPlayerBase.push_back(new MimicPlayer(i, chosenLevel));
			break;
		case Safe:InitialPlayerBase.push_back(new SafePlayer(i, chosenLevel));
			break;
		case Custom:InitialPlayerBase.push_back(new CustomPlayer(i, chosenLevel));
			break;
		} // end of switch

	}// end of for loop
}


void TrafficGen::CreateDealerBase()
{
	cout << "Creating Dealers..." << endl;
	for (int i = 0; i < numDealers; i++)
	{
		DealerBase.push_back(new Dealer(i, dealerSalary, dealerWinThreshold));
	}
}


void TrafficGen::CreateTables()
{
	cout << "Creating Tables..." << endl;
	int tokens = numTables;
	while (tokens > 0)
	{
		if (tokens > 0)
		{
			Tables.push_back(new RedTable((numTables - tokens), minNumPlayer, maxNumPlayer, minNumDeck, maxNumDeck, tableStartAmountRatio, tableRefillAmountRatio));
			tokens--;
		}

		if (tokens > 0)
		{
			Tables.push_back(new GreenTable((numTables - tokens), minNumPlayer, maxNumPlayer, minNumDeck, maxNumDeck, tableStartAmountRatio, tableRefillAmountRatio));
			tokens--;
		}

		if (tokens > 0)
		{
			Tables.push_back(new BlackTable((numTables - tokens), minNumPlayer, maxNumPlayer, minNumDeck, maxNumDeck, tableStartAmountRatio, tableRefillAmountRatio));
			tokens--;
		}

		if (tokens > 0)
		{
			Tables.push_back(new BlueTable((numTables - tokens), minNumPlayer, maxNumPlayer, minNumDeck, maxNumDeck, tableStartAmountRatio, tableRefillAmountRatio));
			tokens--;
		}
	}
}

