#include "Casino.h"

Casino::Casino() // in the casino defult constructor we declare objects of 
{
	// traffic generator that passes base of players, base of dealers, base of tables
	TraffGen = new TrafficGen(InitialPlayerBase, DealerBase, Tables); 
	SK = new StatKeeper();
	SysCon = new SystemController(TraffGen); // system controller that passes traffic generator objects

}

Casino::~Casino()
{
	delete TraffGen;    // deallocate or delete traffic generator
	delete SK;          // deallocate or delete statistic keeper
	delete SysCon;      // deallocate or delete system controller
}
