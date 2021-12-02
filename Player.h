#ifndef PLAYER_H
#define PLAYER_H


#include "BasePerson.h"


class Player : public BasePerson
{
protected:
	enum PlayerLevel
	{
		L1, L2, L3, L4, L5 // L5 is Hall of Fame
	};

	int playerLevel;

	int startCash;
	int currentCash;

	int betAmount;
	int winAmount;

	bool hasQuit;

	bool RedLevelQuit();
	bool GreenLevelQuit();
	bool BlackLevelQuit();
	bool BlueLevelQuit();

public:
	Player(int in_ID, int in_Level);

	int Bet() override;
	bool QuittingBehaviour() override;

	void Win() override;
	void Lose() override;
	void Draw() override;

	int GetBetAmount() { return betAmount; }
	int GetWinAmount() { return winAmount; }

	int PlayerID() { return personID; }
	int PlayerLevel() { return playerLevel; }
	int PlayerProfitLoss();
	void PromotePlayer();

	int ProfitLoss();

	void SetQuit() { hasQuit = true; }
	bool HasPlayerQuit() { return hasQuit; }

	int GetCurrentCash() { return currentCash; }
};


#endif /* PLAYER_H */
