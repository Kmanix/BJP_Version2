#ifndef STATISTICS_KEEPER_H
#define STATISTICS_KEEPER_H

#include <iostream>
#include <fstream>

#include "GAME_CONSTANTS.h"

using std::cout;
using std::endl;
using std::ofstream;

class StatKeeper
{
private:
	int playerWinAmount;
	int playerLossAmount;
	int roundsPlayed;
	int casinoStartAmount;
	int casinoCurrentAmount;
	int numHOF;
	int numQuit;

public:
	StatKeeper();
	void IncrementRound();
	void SetCasinoStartAmount(int amount);
	void DeductCasinoCash(int amount);
	void AddPlayerWinAmount(int amount);
	void AddPlayerLoseAmount(int amount);
	void SetHallOfFamers(int num);
	void SetQuitters(int num);

	void PrintStats();
	void PrintStatsToFile();
};


#endif /* STATISTICS_KEEPER_H */
