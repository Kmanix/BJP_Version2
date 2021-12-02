#ifndef BASE_PERSON_H
#define BASE_PERSON_H


#include <iostream>
#include <vector>
#include <string>

#include "GAME_CONSTANTS.h"
#include "GameMaterials.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::to_string;


// forward declaration
class GameTable;


class BasePerson
{
protected:
	int personID;
	int tableNumber;

	int roundLimit;
	int roundsPlayed;

	vector<char> trackRecord;
	GameTable* assignedTable;
	vector<Card> playHand;

public:
	BasePerson(int in_ID);

	virtual int Bet() = 0;
	virtual bool QuittingBehaviour() = 0;
	virtual bool Strategy(int HandScore) = 0;

	virtual bool Play(int Handscore);
	virtual void Win();
	virtual void Lose();
	virtual void Draw();

	GameTable* GetAssignedGameTable();
	void SetAssignedGameTable(GameTable* in_table);
	void ClearAssignedGameTable();

	void AddCard(Card c);
	int GetHandscore();
	void ResetPlayHand();

	string GetPlayHandAsString();

};


#endif /* BASE_PERSON_H */

