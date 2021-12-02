#include "StatKeeper.h"

StatKeeper::StatKeeper()
{
	playerWinAmount = 0;
	playerLossAmount = 0;
	roundsPlayed = 0;
	casinoStartAmount = 0;
	casinoCurrentAmount = 0;
	numHOF = 0;
	numQuit = 0;
}

void StatKeeper::IncrementRound()
{
	roundsPlayed++;
}

void StatKeeper::SetCasinoStartAmount(int amount)
{
	casinoStartAmount = amount;
	casinoCurrentAmount = casinoStartAmount;
}

void StatKeeper::DeductCasinoCash(int amount)
{
	casinoCurrentAmount -= amount;
}

void StatKeeper::AddPlayerWinAmount(int amount)
{
	playerWinAmount += amount;
	casinoCurrentAmount -= amount;
}

void StatKeeper::AddPlayerLoseAmount(int amount)
{
	playerLossAmount += amount;
	casinoCurrentAmount += amount;
}

void StatKeeper::SetHallOfFamers(int num)
{
	numHOF = num;
}

void StatKeeper::SetQuitters(int num)
{
	numQuit = num;
}

void StatKeeper::PrintStats()
{
	cout << "####################################" << endl;
	cout << "######## Casino Statistics #########" << endl;
	cout << "####################################" << endl;
	cout << "Total Rounds Played: " << roundsPlayed << endl;
	cout << "Casino Profit/Loss: $" << (casinoCurrentAmount - casinoStartAmount) << endl;
	cout << "Money won by Players: $" << playerWinAmount << endl;
	cout << "Money lost by Players: $" << playerLossAmount << endl;
	cout << "Hall of Famers: " << numHOF << endl;
	cout << "Players washed out: " << numQuit << endl;
	cout << "####################################" << endl;
	cout << "####################################" << endl;

}

void StatKeeper::PrintStatsToFile()
{
	ofstream outfile(STAT_OUTPUT_FILE);
	if (outfile.is_open())
	{
		outfile << "####################################" << endl;
		outfile << "######## Casino Statistics #########" << endl;
		outfile << "####################################" << endl;
		outfile << "Total Rounds Played: " << roundsPlayed << endl;
		outfile << "Casino Profit/Loss: $" << (casinoCurrentAmount - casinoStartAmount) << endl;
		outfile << "Money won by Players: $" << playerWinAmount << endl;
		outfile << "Money lost by Players: $" << playerLossAmount << endl;
		outfile << "Hall of Famers: " << numHOF << endl;
		outfile << "Players washed out: " << numQuit << endl;
		outfile << "####################################" << endl;
		outfile << "####################################" << endl;
	}
	else
	{
		cout << "Failed to write stats to file..." << endl;
	}
	outfile.close();
}

