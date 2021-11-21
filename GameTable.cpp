#include "GameTable.h"



GameTable::GameTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks)
	: TableID(in_ID), minPlayers(in_minPlayers), maxPlayers(in_maxPlayers), minDecks(in_minDecks), maxDecks(in_maxDecks)
{
	// we initialize a defult value to each attributes
	minBet = -1;
	maxBet = -1;

	TableDealer = nullptr;
	// we pick a rondom number of deck from the maximum and the minimum of the given number
	TableDeck = new Deck((rand() % (maxDecks - minDecks + 1)) + minDecks); 
}

bool GameTable::AssignDealer(Dealer* in_dealer)
{
	if (TableDealer == nullptr)  // check if the table does not have a dealer on it
	{
		TableDealer = in_dealer; // we assign a dealer in a table
		return true;
	}
	return false; // else we return false because the table has dealer
}

Dealer* GameTable::RemoveDealer()
{
	Dealer* retiredDealer = TableDealer; 
	TableDealer = nullptr;
	return retiredDealer;
}

bool GameTable::AddPlayer(Player* in_player)
{
	if (TablePlayers.size() < maxPlayers) // check if the table has less than the maximum of players
	{
		TablePlayers.push_back(in_player); // if so, add player in a table
		return true;
	}
	return false; // else, return false, which do NOT add player
}

Player* GameTable::RemovePlayer()
{
	return nullptr; //  remove the player by returning a NULL to pointer of player
}

bool GameTable::GameReadyToStart() // check if the table empty, return false that the table NOT ready to start the game
{
	if (TableDealer == nullptr) // if the table does not have a dealer
		return false;

	if (TablePlayers.size() < minPlayers) // if the table does not have the minmum of the player to start
		return false;

	return true; // else, return the table is ready to start a game
}

bool GameTable::CanTakeMorePlayer() 
{
	if (TablePlayers.size() < maxPlayers)
		return true;

	return false;
}

bool GameTable::CanTakeADealer()
{
	if (TableDealer == nullptr)
		return true;

	return false;
}

void GameTable::PlayRound()
{
	if (GameReadyToStart())
	{
		// betting round
		for (auto& p : TablePlayers)
		{
			p->Bet();
		}

		// deal cards
		for (auto& p : TablePlayers)
		{
			for (int i = 0; i < 2; i++)
			{
				p->addCard(TableDeck->dealCard());
			}
		}
		for (int i = 0; i < 2; i++)
		{
			TableDealer->addCard(TableDeck->dealCard());
		}

		// player turn


		// dealer turn


		// calculate winner and losers


		// cleanup


	}
}

int GameTable::PlaceBet() // a common logic for bet method for each player 
{
	int amount = minBet;
	int additive = rand() % (((maxBet - minBet) / betMultiple) + 1);
	amount += betMultiple * additive;
	return amount;
}
