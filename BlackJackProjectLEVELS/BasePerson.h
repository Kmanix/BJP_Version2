#ifndef BASE_PERSON_H
#define BASE_PERSON_H


#include <iostream>
#include <vector>

#include "GAME_CONSTANTS.h"
#include "GameMaterials.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;


// forward declaration
class GameTable;


class BasePerson
{
protected:
	int ID;
	int TableNumber;

	int StartCash;
	int CurrentCash;

	int RoundLimit;
	int RoundsPlayed;

	vector<char> TrackRecord;
	GameTable* assignedTable;
	vector<Card> hand;

public:
	BasePerson(int in_ID);

	virtual int Bet() = 0;
	virtual bool QuittingBehaviour() = 0;
	virtual bool Strategy(int HandScore) = 0;

	virtual bool Play(int Handscore);
	virtual void Win();
	virtual void Lose();

	GameTable* getGameTable();
	void setGameTable(GameTable* in_table);
	void clearGameTable();

	void addCard(Card c);
	int GetHandscore();
	void resetHand();

	int ProfitLoss();
};


#endif /* BASE_PERSON_H */
