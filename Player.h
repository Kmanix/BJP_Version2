#ifndef PLAYER_H
#define PLAYER_H


#include "BasePerson.h"


class Player : public BasePerson
{
protected:
	enum PlayerLevel
	{
		L1, L2, L3, L4
	};

	int Level;

	int betAmount;
	int winAmount;

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

	int getBetAmount() { return betAmount; }
	int getWinAmount() { return winAmount; }

	int PlayerLevel() { return Level; }
	void PromotePlayer();

};


#endif /* PLAYER_H */
