#include "GameTable.h"

#include "StrategyPlayer.h"
#include "Dealer.h"


GameTable::GameTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks, int in_maxDecks, int in_StartRatio, int in_refillRatio)
	: TableID(in_ID), minPlayers(in_minPlayers), maxPlayers(in_maxPlayers), minDecks(in_minDecks), maxDecks(in_maxDecks), startRatio(in_StartRatio), refillRatio(in_refillRatio)
{
	Level = Red;

	minBet = -1;
	maxBet = -1;
	betMultiple = -1;

	TableStartCash = -1;
	TableCurrentCash = -1;
	TableRefillAmount = -1;

	TableDealer = nullptr;
	TableDeck = new Deck((rand() % (maxDecks - minDecks + 1)) + minDecks);
}


GameTable::~GameTable()
{
	delete TableDeck;
}


bool GameTable::AssignDealer(Dealer* in_dealer)
{
	if (TableDealer == nullptr)
	{
		TableDealer = in_dealer;
		return true;
	}
	return false;
}


Dealer* GameTable::RemoveDealer()
{
	Dealer* retiredDealer = TableDealer;
	TableDealer = nullptr;
	return retiredDealer;
}


bool GameTable::AddPlayer(Player* in_player)
{
	if (TablePlayers.size() < maxPlayers)
	{
		TablePlayers.push_back(in_player);
		return true;
	}
	return false;
}


Player* GameTable::RemovePlayer()
{
	return nullptr;
}


bool GameTable::GameReadyToStart()
{
	if (TableDealer == nullptr)
		return false;

	if (TablePlayers.size() < minPlayers)
		return false;

	return true;
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
		BettingRound();

		DealingRound();

		PlayingRound();

		ResultsRound();
		
		// cleanup

	}
}


void GameTable::BettingRound()
{
	// betting round
	for (auto& p : TablePlayers)
	{
		p->Bet();
	}
}


void GameTable::DealingRound()
{
	// deal cards for player
	for (auto& p : TablePlayers)
	{
		for (int i = 0; i < 2; i++)
		{
			p->addCard(TableDeck->dealCard());
		}
	}

	// deal cards for dealer
	for (int i = 0; i < 2; i++)
	{
		TableDealer->addCard(TableDeck->dealCard());
	}
}


void GameTable::PlayingRound()
{
	// players' turn
	for (auto& p : TablePlayers)
	{
		while (p->Play(p->GetHandscore()));
	}

	// dealer's turn
	while (TableDealer->Play(TableDealer->GetHandscore()));
}


void GameTable::ResultsRound()
{
	// calculate winner and losers
	int dealerScore = TableDealer->GetHandscore();
	for (auto& p : TablePlayers)
	{
		int playerScore = p->GetHandscore();
		
		if (playerScore > 21)
		{
			p->Lose();
			TableCurrentCash += p->getBetAmount();
		}
		else if (playerScore < dealerScore && dealerScore < 21)
		{
			p->Lose();
			TableCurrentCash += p->getBetAmount();
		}
		else
		{
			p->Win();
			TableCurrentCash -= p->getWinAmount();
		}
	}
}


int GameTable::PlaceBet()
{
	int amount = minBet;
	int additive = rand() % (((maxBet - minBet) / betMultiple) + 1);
	amount += betMultiple * additive;
	return amount;
}


Card GameTable::HitMe()
{
	return TableDeck->dealCard();
}

