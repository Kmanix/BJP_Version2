#include "StrategyPlayer.h"

#include "GameTable.h"


// Random strat ////////////////////////////////////////////////////////
RandomPlayer::RandomPlayer(int in_ID, int in_Level)
	: Player(in_ID, in_Level)
{
}

bool RandomPlayer::Strategy(int Handscore)
{
	int min = 1;
	int max = 20;

	int roll1 = (rand() % (max - min + 1)) + min;
	int roll2 = (rand() % (max - min + 1)) + min;

	if (roll1 < roll2)
		return true;
	else
		return false;
}


// Mimic Strat ////////////////////////////////////////////////////////
MimicPlayer::MimicPlayer(int in_ID, int in_Level)
	: Player(in_ID, in_Level)
{
}

bool MimicPlayer::Strategy(int Handscore)
{
	if (Handscore <= 16)
		return true;
	else
		return false;
}


// Safe strat ////////////////////////////////////////////////////////
SafePlayer::SafePlayer(int in_ID, int in_Level)
	: Player(in_ID, in_Level)
{
}

bool SafePlayer::Strategy(int Handscore)
{
	if (Handscore > 16 && Handscore < 21)
		return false;
	else
		return true;
}


// Custom Strat ////////////////////////////////////////////////////////
CustomPlayer::CustomPlayer(int in_ID, int in_Level)
	: Player(in_ID, in_Level)
{
}

bool CustomPlayer::Strategy(int Handscore)
{
	if (Handscore <= 16 && Handscore >= 5)
		return true;
	else
		return false;
}
