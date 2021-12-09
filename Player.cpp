#include "Player.h"

#include "GameTable.h"


Player::Player(int in_ID, int in_Level)
	: BasePerson(in_ID)
{
	hasQuit = false;

	startCash = -1;
	currentCash = -1;

	playerLevel = in_Level;
	betAmount = 0;
	winAmount = 0;

	switch (playerLevel)
	{
	case L1: startCash = 2 * (rand() % (RED_MAX_BET - RED_MIN_BET)) + RED_MIN_BET;
		break;
	case L2: startCash = 2 * (rand() % (GREEN_MAX_BET - GREEN_MIN_BET)) + GREEN_MIN_BET;
		break;
	case L3: startCash = 2 * (rand() % (BLACK_MAX_BET - BLACK_MIN_BET)) + BLACK_MIN_BET;
		break;
	case L4: startCash = 2 * (rand() % (BLUE_MAX_BET - BLUE_MIN_BET)) + BLUE_MIN_BET;
		break;
	}

	currentCash = startCash;
}


int Player::Bet()
{
	betAmount = assignedTable->PlaceBet();
	if (betAmount > currentCash)
	{
		betAmount = currentCash;
		currentCash = 0;
	}
	else
	{
		currentCash -= betAmount;
	}
	return betAmount;
}


bool Player::QuittingBehaviour()
{
	if (currentCash <= 0)
		return true;

	switch (playerLevel)
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
	for (char& c : trackRecord)
	{
		if (c == 'W')
			wins++;
		else if (c == 'L')
			losses++;
	}

	double quitLimit = 60.0f; // 60% loss rate

	if (trackRecord.size() > 1)
	{
		double lose_percent = (double)losses / trackRecord.size() * 100.0;

		if (lose_percent >= quitLimit)
			return true;
	}

	return false;
}


bool Player::GreenLevelQuit()
{
	if (currentCash <= (int)((double)startCash * 0.1))
		return true;
	else
		return false;
}


bool Player::BlackLevelQuit()
{
	if (roundsPlayed >= roundLimit)
		return true;
	else
		return false;
}


bool Player::BlueLevelQuit()
{
	if (trackRecord.size() > 2)
	{
		int lastIndex = (int)trackRecord.size() - 1;
		if (trackRecord[lastIndex] == 'L' &&
			trackRecord[lastIndex - 1] == 'L' &&
			trackRecord[lastIndex - 2] == 'L')
		{
			return true;
		}
	}
	return false;
}


void Player::Win()
{
	BasePerson::Win();

	if (playHand.size() == 2 && GetHandscore() == 21)
	{
		winAmount = (betAmount + (int)((double)betAmount * 1.5));
	}
	else
	{
		winAmount = (betAmount + betAmount);
	}

	currentCash += winAmount;
}


void Player::Lose()
{
	BasePerson::Lose();
}


void Player::Draw()
{
	BasePerson::Draw();

	winAmount = betAmount;
	currentCash += winAmount;
}


int Player::PlayerProfitLoss()
{
	return currentCash - startCash;
}


void Player::PromotePlayer()
{
	if (playerLevel < L5)
	{
		playerLevel++;
	}
}

int Player::ProfitLoss()
{
	return startCash - currentCash;
}
