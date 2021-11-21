#include "SystemController.h"

SystemController::SystemController(TrafficGen* in_TrafficGenModule)
{
	TrafficGenModule = in_TrafficGenModule;
	Init();
}

SystemController::~SystemController()
{
}

void SystemController::Init()
{
	TrafficGenModule->Init(USER_INPUT_FILE);
}
