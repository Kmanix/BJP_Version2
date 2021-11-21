#ifndef SYSTEM_CONTROLLER_H
#define SYSTEM_CONTROLLER_H

#include <vector>

#include "TrafficGen.h"
#include "GAME_CONSTANTS.h"

class SystemController
{
	TrafficGen* TrafficGenModule;// declare a traffic genertator pointer to genertate the game

public:
	SystemController(TrafficGen* in_TrafficGenModule);
	~SystemController();
	void Init();
};


#endif /* SYSTEM_CONTROLLER_H */