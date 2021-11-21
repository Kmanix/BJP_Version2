#ifndef PLAYER_H
#define PLAYER_H

#include "BasePerson.h"

// child class of base person class
class Player : public BasePerson
{
protected:
	int Level; // declaring the level of each players

	int betAmount; // declaring the bet of the amount of each player

public:
	Player(int in_ID, int in_Level);// constructor of player to create an object by passing player id & player level

	int Bet() ;
	bool Play(int Handscore) ;
	bool QuittingBehaviour() ;

};

#endif /* PLAYER_H */