#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <ctime>
#include <random>

#include "Casino.h"
#include "GameMaterials.h"


// TESTS //////////////////////
void TestPlayerCreation()
{
	Player* rp = new RandomPlayer(10, 0);
	Player* mp = new MimicPlayer(11, 1);
	Player* sp = new SafePlayer(12, 2);
	Player* cp = new CustomPlayer(13, 3);

	cout << endl;
}

void TestDealerCreation()
{
	Dealer* d = new Dealer(10, 50, 40);

	cout << endl;
}

void TestGameTableCreation()
{
	GameTable* r_t = new RedTable(0, 4, 8, 2, 6, 50, 20, 200);
	GameTable* g_t = new GreenTable(1, 4, 8, 2, 6, 50, 20, 1'000);
	GameTable* bla_t = new BlackTable(2, 4, 8, 2, 6, 50, 20, 5'000);
	GameTable* blu_t = new BlueTable(3, 4, 8, 2, 6, 50, 20, 100'000);

	cout << endl;
}

void TestDecks()
{
	Deck* d1 = new Deck(1);
	Deck* d2 = new Deck(2);
	Deck* d4 = new Deck(4);
	Deck* d5 = new Deck(5);

	cout << endl;
}

void TestTrafficGenTestFile()
{
	vector<Player*> Players;
	vector<Dealer*> Dealers;
	vector<GameTable*> Tables;

	TrafficGen* tg_test = new TrafficGen(Players, Dealers, Tables);
	tg_test->Init("test_input.txt");

	cout << endl;
}

void TestTrafficGenUserFile()
{
	vector<Player*> Players;
	vector<Dealer*> Dealers;
	vector<GameTable*> Tables;

	TrafficGen* tg_user = new TrafficGen(Players, Dealers, Tables);
	tg_user->Init("user_input.txt");

	cout << endl;
}

void TestSystemController()
{
	long int CashReserve = 1'000'000;

	vector<Player*> Players;
	vector<Dealer*> Dealers;
	vector<GameTable*> Tables;
	vector<Player*> QuitPlayers;
	vector<Player*> HallOfFame;

	TrafficGen* tg = new TrafficGen(Players, Dealers, Tables);
	StatKeeper* sk = new StatKeeper();

	SystemController* syscon = new SystemController(CashReserve, tg, sk, Players, Dealers, Tables, QuitPlayers, HallOfFame);

	cout << endl;
}


// RUN TESTS //////////////////
void runTests()
{
	// object creation tests
	TestPlayerCreation();
	TestDealerCreation();
	TestGameTableCreation();
	TestDecks();

	// file reading and object creation
	TestTrafficGenTestFile();
	TestTrafficGenUserFile();

	// system controller
	TestSystemController();
}


#endif
