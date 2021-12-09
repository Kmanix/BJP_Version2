#ifndef COLOR_GAME_TABLE_H
#define COLOR_GAME_TABLE_H


#include "GameTable.h"


// RED ////////////////////////////////
class RedTable : public GameTable
{
public:
	RedTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks,
		int in_maxDecks, int in_StartRatio, int in_refillRatio, int PromotionThreshold);
};


// GREEN ////////////////////////////////
class GreenTable : public GameTable
{
public:
	GreenTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks,
		int in_maxDecks, int in_StartRatio, int in_refillRatio, int PromotionThreshold);
};


// BLACK ////////////////////////////////
class BlackTable : public GameTable
{
public:
	BlackTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks,
		int in_maxDecks, int in_StartRatio, int in_refillRatio, int PromotionThreshold);
};


// BLUE ////////////////////////////////
class BlueTable : public GameTable
{
public:
	BlueTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks,
		int in_maxDecks, int in_StartRatio, int in_refillRatio, int PromotionThreshold);
};


#endif /* COLOR_GAME_TABLE_H */