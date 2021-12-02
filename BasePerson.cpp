#include "BasePerson.h"

#include "GameTable.h"


BasePerson::BasePerson(int in_ID)
{
	personID = in_ID;
	tableNumber = -1;
	assignedTable = nullptr;

	roundLimit = ROUND_LIMIT;
	roundsPlayed = 0;

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
			playHand.push_back(assignedTable->HitMe());
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
	trackRecord.push_back('W');
	roundsPlayed++;
}


void BasePerson::Lose()
{
	trackRecord.push_back('L');
	roundsPlayed++;
}


void BasePerson::Draw()
{
	trackRecord.push_back('D');
	roundsPlayed++;
}


GameTable* BasePerson::GetAssignedGameTable()
{
	return assignedTable;
}


void BasePerson::SetAssignedGameTable(GameTable* in_table)
{
	if (in_table != nullptr)
		assignedTable = in_table;
}


void BasePerson::ClearAssignedGameTable()
{
	assignedTable = nullptr;
}


void BasePerson::AddCard(Card c)
{
	playHand.push_back(c);
}


int BasePerson::GetHandscore()
{
	int hs = 0;
	for (auto& c : playHand)
	{
		int rank = c.GetRank();
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


void BasePerson::ResetPlayHand()
{
	playHand.clear();
}


string BasePerson::GetPlayHandAsString()
{
	string handStr = "";
	for (auto& c : playHand)
	{
		switch (c.GetSuit())
		{
			case Hearts: handStr += "H";
				break;
			case Diamonds: handStr += "D";
				break;
			case Clubs: handStr += "C";
				break;
			case Spades: handStr += "S";
				break;
		}
		handStr += to_string(c.GetRank());
		handStr += ", ";
	}
	return handStr;
}

