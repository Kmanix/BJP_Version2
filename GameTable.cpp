#include "GameTable.h"

#include "StrategyPlayer.h"
#include "Dealer.h"


GameTable::GameTable(int in_ID, int in_minPlayers, int in_maxPlayers, int in_minDecks,
	int in_maxDecks, int in_StartRatio, int in_refillRatio, int in_PromotionThreshold)
	: tableID(in_ID), tableMinPlayers(in_minPlayers), tableMaxPlayers(in_maxPlayers), tableMinDecks(in_minDecks), tableMaxDecks(in_maxDecks),
	cashStartRatio(in_StartRatio), cashRefillRatio(in_refillRatio), playerPromotionThreshold(in_PromotionThreshold)
{
	tableLevel = Red;

	minBet = -1;
	maxBet = -1;
	betMultiple = -1;

	tableStartCash = -1;
	tableCurrentCash = -1;
	tableRefillAmount = -1;

	tableAssignedDealer = nullptr;
	tableCardsDeck = new Deck((rand() % (tableMaxDecks - tableMinDecks + 1)) + tableMinDecks);

	outfile.open(ROUND_OUTPUT_FILE);
}


GameTable::~GameTable()
{
	if (tableAssignedDealer)
		delete tableAssignedDealer;

	delete tableCardsDeck;
	outfile.close();
}


bool GameTable::AssignDealer(Dealer* in_dealer)
{
	if (tableAssignedDealer == nullptr)
	{
		tableAssignedDealer = in_dealer;
		return true;
	}
	return false;
}


bool GameTable::DealerNeedsToRetire()
{
	if (tableAssignedDealer)
		return tableAssignedDealer->QuittingBehaviour();

	return false;
}


Dealer* GameTable::RemoveDealer()
{
	Dealer* retiredDealer = tableAssignedDealer;
	tableAssignedDealer = nullptr;
	retiredDealer->ClearAssignedGameTable();
	return retiredDealer;
}


bool GameTable::AddPlayer(Player* in_player)
{
	if (tableAssignedPlayers.size() < tableMaxPlayers)
	{
		tableAssignedPlayers.push_back(in_player);
		return true;
	}
	return false;
}


bool GameTable::GameReadyToStart()
{
	if (tableAssignedDealer == nullptr)
		return false;

	if (tableAssignedPlayers.size() < tableMinPlayers)
		return false;

	if (tableCurrentCash <= tableRefillAmount)
		return false;

	return true;
}


bool GameTable::CanTakeMorePlayer()
{
	if (tableAssignedPlayers.size() < tableMaxPlayers)
		return true;

	return false;
}


bool GameTable::CanTakeADealer()
{
	if (tableAssignedDealer == nullptr)
		return true;

	return false;
}


void GameTable::PlayRound(StatKeeper* statModule)
{
	if (GameReadyToStart())
	{
		cout << endl << "Table" << tableID << " of level " << (tableLevel + 1) << " started round:" << endl;

		outfile << endl << "Table" << tableID << " of level " << (tableLevel + 1) << " started round:" << endl;

		BettingRound();

		DealingRound();

		PlayingRound();

		ResultsRound(statModule);

		PlayerPromotions();

		CleanUp();

		cout << "Table" << tableID << ": ended round" << endl << endl;
		outfile << "Table" << tableID << ": ended round" << endl << endl;
	}
}


bool GameTable::NeedCashRefill()
{
	if (tableCurrentCash <= tableRefillAmount)
		return true;
	else
		return false;
}


int GameTable::TopUpAmount()
{
	return tableStartCash - tableCurrentCash;
}


void GameTable::DepositCash(int amount)
{
	tableCurrentCash += amount;
}


void GameTable::BettingRound()
{
	// betting round
	for (auto& p : tableAssignedPlayers)
	{
		p->Bet();
	}
}


void GameTable::DealingRound()
{
	// deal cards for player
	for (auto& p : tableAssignedPlayers)
	{
		for (int i = 0; i < 2; i++)
		{
			p->AddCard(tableCardsDeck->DealOneCard());
		}
	}

	// deal cards for dealer
	for (int i = 0; i < 2; i++)
	{
		tableAssignedDealer->AddCard(tableCardsDeck->DealOneCard());
	}
}


void GameTable::PlayingRound()
{
	// players' turn
	for (auto& p : tableAssignedPlayers)
	{
		while (p->Play(p->GetHandscore()));
	}

	// dealer's turn
	while (tableAssignedDealer->Play(tableAssignedDealer->GetHandscore()));
}


void GameTable::ResultsRound(StatKeeper* statModule)
{
	// print results
	PrintHands();

	// calculate winner and losers
	int dealerScore = tableAssignedDealer->GetHandscore();

	for (auto& player : tableAssignedPlayers)
	{
		int playerScore = player->GetHandscore();

		if (playerScore > 21 && dealerScore > 21)
		{
			PlayerDrawLogistics(statModule, player);
		}
		else if (playerScore == dealerScore)
		{
			PlayerDrawLogistics(statModule, player);
		}
		else if (playerScore > 21)
		{
			PlayerLoseLogistics(statModule, player);
		}
		else if (playerScore < dealerScore && dealerScore <= 21)
		{
			PlayerLoseLogistics(statModule, player);
		}
		else
		{
			PlayerWinLogistics(statModule, player);
		}
	}

	cout << endl;
	outfile << endl;
}


void GameTable::PrintHands()
{
	cout << "Dealer: " << tableAssignedDealer->GetPlayHandAsString();
	cout << "\t\tSum: " << tableAssignedDealer->GetHandscore() << endl;

	outfile << "Dealer: " << tableAssignedDealer->GetPlayHandAsString();
	outfile << "\t\tSum: " << tableAssignedDealer->GetHandscore() << endl;

	for (auto& player : tableAssignedPlayers)
	{
		cout << "Player" << player->PlayerID() << ": " << player->GetPlayHandAsString();
		cout << "\t\tSum: " << player->GetHandscore() << "\t\t" << "Bet Amount: " << player->GetBetAmount() << endl;

		outfile << "Player" << player->PlayerID() << ": " << player->GetPlayHandAsString();
		outfile << "\t\tSum: " << player->GetHandscore() << "\t\t" << "Bet Amount: " << player->GetBetAmount() << endl;
	}

	cout << endl;
	outfile << endl;
}


void GameTable::PlayerLoseLogistics(StatKeeper* statModule, Player* player)
{
	player->Lose();

	tableCurrentCash += player->GetBetAmount();
	statModule->AddPlayerLoseAmount(player->GetBetAmount());

	// output to console
	cout << "Player" << player->PlayerID() << ": loses " << player->GetBetAmount() << ".\t\tBalance: " << player->GetCurrentCash() << endl;

	// output to file
	outfile << "Player" << player->PlayerID() << ": loses " << player->GetBetAmount() << ".\t\tBalance: " << player->GetCurrentCash() << endl;
}


void GameTable::PlayerWinLogistics(StatKeeper* statModule, Player* player)
{
	player->Win();

	tableCurrentCash -= player->GetWinAmount();
	statModule->AddPlayerWinAmount(player->GetWinAmount());

	// output to console
	cout << "Player" << player->PlayerID() << ": wins " << player->GetWinAmount() << "!\t\tBalance: " << player->GetCurrentCash() << endl;

	// output to file
	outfile << "Player" << player->PlayerID() << ": wins " << player->GetWinAmount() << "!\t\tBalance: " << player->GetCurrentCash() << endl;
}


void GameTable::PlayerDrawLogistics(StatKeeper* statModule, Player* player)
{
	player->Draw();

	// output to console
	cout << "Player" << player->PlayerID() << ": draws.\t\tBalance: " << player->GetCurrentCash() << endl;

	// output to file
	outfile << "Player" << player->PlayerID() << ": draws.\t\tBalance: " << player->GetCurrentCash() << endl;
}




void GameTable::PlayerPromotions()
{
	for (auto& player : tableAssignedPlayers)
	{
		if (player->PlayerProfitLoss() >= playerPromotionThreshold)
		{
			player->PromotePlayer();

			cout << "NOTICE: Player" << player->PlayerID() << " promoted to higher table!" << endl;
			outfile << "NOTICE: Player" << player->PlayerID() << " promoted to higher table!" << endl;
		}
	}
}


void GameTable::CleanUp()
{
	tableAssignedDealer->ResetPlayHand();

	for (auto& player : tableAssignedPlayers)
	{
		player->ResetPlayHand();
	}

	delete tableCardsDeck;
	tableCardsDeck = new Deck((rand() % (tableMaxDecks - tableMinDecks + 1)) + tableMinDecks);
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
	return tableCardsDeck->DealOneCard();
}
