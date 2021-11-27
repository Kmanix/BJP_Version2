#include "Player.h"

#include "GameTable.h"


Player::Player(int in_ID, int in_Level)
	: BasePerson(in_ID)
{
	Level = in_Level;
	betAmount = 0;
	winAmount = 0;

	switch (Level)
	{
	case 0: StartCash = 2 * (rand() % (RED_MAX_BET - RED_MIN_BET)) + RED_MIN_BET;
		break;
	case 1: StartCash = 2 * (rand() % (GREEN_MAX_BET - GREEN_MIN_BET)) + GREEN_MIN_BET;
		break;
	case 2: StartCash = 2 * (rand() % (BLACK_MAX_BET - BLACK_MIN_BET)) + BLACK_MIN_BET;
		break;
	case 3: StartCash = 2 * (rand() % (BLUE_MAX_BET - BLUE_MIN_BET)) + BLUE_MIN_BET;
		break;
	}

	CurrentCash = StartCash;
}


int Player::Bet()
{
	betAmount = assignedTable->PlaceBet();
	if (betAmount > CurrentCash)
	{
		betAmount = CurrentCash;
		CurrentCash = 0;
	}
	else
	{
		CurrentCash -= betAmount;
	}
	return betAmount;
}


bool Player::QuittingBehaviour()
{
	switch (Level)
	{
	case 0: return RedLevelQuit();
		break;
	case 1: return GreenLevelQuit();
		break;
	case 2: return BlackLevelQuit();
		break;
	case 3: return BlueLevelQuit();
		break;
	}
	return false;
}


bool Player::RedLevelQuit()
{
	int wins = 0, losses = 0;
	for (char& c : TrackRecord)
	{
		if (c == 'W')
			wins++;
		else if (c == 'L')
			losses++;
	}

	double quitLimit = 60.0f; // 60% loss rate

	if (TrackRecord.size() > 1)
	{
		double lose_percent = (double)losses / TrackRecord.size() * 100.0;

		if (lose_percent >= quitLimit)
			return true;
	}

	return false;
}


bool Player::GreenLevelQuit()
{
	if (CurrentCash <= (int)((double)StartCash * 0.1))
		return true;
	else
		return false;
}


bool Player::BlackLevelQuit()
{
	if (RoundsPlayed >= RoundLimit)
		return true;
	else
		return false;
}


bool Player::BlueLevelQuit()
{
	if (TrackRecord.size() > 2)
	{
		int lastIndex = (int)TrackRecord.size() - 1;
		if (TrackRecord[lastIndex] == 'L' &&
			TrackRecord[lastIndex - 1] == 'L' &&
			TrackRecord[lastIndex - 2] == 'L')
		{
			return true;
		}
	}
	return false;
}


void Player::Win()
{
	BasePerson::Win();

	if (hand.size() == 2 && GetHandscore() == 21)
	{
		winAmount = (betAmount + (int)((double)betAmount * 1.5));
	}
	else
	{
		winAmount = (betAmount + betAmount);
	}

	CurrentCash += winAmount;
}


void Player::Lose()
{
	BasePerson::Lose();
}


void Player::PromotePlayer()
{
	if (Level < L4)
	{
		Level++;
	}
}
