#ifndef TRAFFIC_GEN_H
#define TRAFFIC_GEN_H


#include <fstream>
#include <vector>
#include <random>

#include "StrategyPlayer.h"
#include "Dealer.h"
#include "ColorGameTable.h"

using std::vector;
using std::string;
using std::ifstream;


class TrafficGen
{
	enum StratType
	{
		Random = 0, Mimic = 1, Safe = 2, Custom = 3
	};

	enum LevelType
	{
		L1, L2, L3, L4
	};

private:
	// table info
	int numTables;
	int minNumPlayer;
	int maxNumPlayer;
	int minNumDeck;
	int maxNumDeck;
	int transitionThreshold[4];

	// dealer info
	int numDealers;
	int dealerSalary;
	int dealerWinThreshold;
	int tableStartAmountRatio;
	int tableRefillAmountRatio;

	// player info
	int numPlayers;
	int stratDistr[4];
	int colorDistr[4][4];

	double playerArrivalProb;

	vector<Player*>& InitialPlayerBase;
	vector<Dealer*>& DealerBase;
	vector<GameTable*>& Tables;

public:

	TrafficGen(vector<Player*>& PlayerBase, vector<Dealer*>& DealerBase, vector<GameTable*>& TableBase);
	void Init(string filename);
	void LoadInputFile(string filename);
	void CreatePlayerBase();
	void CreateDealerBase();
	void CreateTables();
};


#endif /* TRAFFIC_GEN_H */