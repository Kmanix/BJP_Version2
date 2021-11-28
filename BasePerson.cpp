#include "BasePerson.h"

#include "GameTable.h"


BasePerson::BasePerson(int in_ID)
{
	ID = in_ID;
	TableNumber = -1;
	assignedTable = nullptr;

	RoundLimit = ROUND_LIMIT;
	RoundsPlayed = 0;

	StartCash = 0;
	CurrentCash = 0;

}


bool BasePerson::Play(int Handscore)
{
	if (Handscore >= 21)
	{
		// stop when person Blackjacks or busts
		return false;
	}
	else
	{
		if (Strategy(Handscore))
		{
			// person decided to hit
			hand.push_back(assignedTable->HitMe());
			return true;
		}
		else
		{
			// person decided to stay
			return false;
		}
	}

}


void BasePerson::Win()
{
	TrackRecord.push_back('W');
	RoundsPlayed++;
}


void BasePerson::Lose()
{
	TrackRecord.push_back('L');
	RoundsPlayed++;
}


GameTable* BasePerson::getGameTable()
{
	return assignedTable;
}


void BasePerson::setGameTable(GameTable* in_table)
{
	if (in_table != nullptr)
		assignedTable = in_table;
}


void BasePerson::clearGameTable()
{
	assignedTable = nullptr;
}


void BasePerson::addCard(Card c)
{
	hand.push_back(c);
}


int BasePerson::GetHandscore()
{
	int hs = 0;
	for (auto& c : hand)
	{
		int rank = c.getRank();
		if (rank >= 2 && rank <= 10) // for non-ace cards
		{
			hs += rank;
		}
		else // for ace cards
		{
			if ((11 + hs) > 21) // if ace will bust, use rank 1
			{
				hs += 1;
			}
			else // if ace wont bust, use rank 11
			{
				hs += 11;
			}
		}
	}
	return hs;
}


void BasePerson::resetHand()
{
	hand.clear();
}


int BasePerson::ProfitLoss()
{
	return StartCash - CurrentCash;
}


