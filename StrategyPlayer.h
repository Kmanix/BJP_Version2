#ifndef STRATEGY_PLAYER_H
#define STRATEGY_PLAYER_H

#include "Player.h"

// child class of player class
// Random strat ////////////////////////
class RandomPlayer : public Player
{
public:
	RandomPlayer(int in_ID, int in_Level); // declaring a constructor of specific player to create object later
	bool Strategy(int Handscore) ; 
};


// Mimic Strat ////////////////////////
class MimicPlayer : public Player
{
public:
	MimicPlayer(int in_ID, int in_Level);// declaring a constructor of specific player to create object later
	bool Strategy(int Handscore) ;
};


// Safe strat ////////////////////////
class SafePlayer : public Player
{
public:
	SafePlayer(int in_ID, int in_Level);// declaring a constructor of specific player to create object later
	bool Strategy(int Handscore) ;
};


// Custom Strat ////////////////////////
class CustomPlayer : public Player
{
public:
	CustomPlayer(int in_ID, int in_Level);// declaring a constructor of specific player to create player object later
	bool Strategy(int Handscore) ;
};

#endif /* STRATEGY_PLAYER_H */