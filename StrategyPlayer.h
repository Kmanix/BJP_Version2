#ifndef STRATEGY_PLAYER_H
#define STRATEGY_PLAYER_H

#include "Player.h"


// Random strat ////////////////////////
class RandomPlayer : public Player
{
public:
	RandomPlayer(int in_ID, int in_Level);
	bool Strategy(int Handscore) override;
};


// Mimic Strat ////////////////////////
class MimicPlayer : public Player
{
public:
	MimicPlayer(int in_ID, int in_Level);
	bool Strategy(int Handscore) override;
};


// Safe strat ////////////////////////
class SafePlayer : public Player
{
public:
	SafePlayer(int in_ID, int in_Level);
	bool Strategy(int Handscore) override;
};


// Custom Strat ////////////////////////
class CustomPlayer : public Player
{
public:
	CustomPlayer(int in_ID, int in_Level);
	bool Strategy(int Handscore) override;
};

#endif /* STRATEGY_PLAYER_H */
