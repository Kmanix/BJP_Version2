#include "Dealer.h"

#include "GameTable.h"


// constructor
Dealer::Dealer(int in_ID, int in_sal, int in_thres) : BasePerson(in_ID)
{
	salary = 0;
	salary_rate = in_sal;
	threshold = in_thres;
}


// dealer bet handled in game table class
int Dealer::Bet()
{
	return 0;
}


bool Dealer::QuittingBehaviour()
{
	// when to go to lounge?

	// calculate wins and losses
	int wins = 0, losses = 0;
	for (char& c : TrackRecord)
	{
		if (c == 'W')
			wins++;
		else if (c == 'L')
			losses++;
	}

	// determine if they retire or not
	if (TrackRecord.size() > 0)
	{
		double win_percent = (double)wins / TrackRecord.size() * 100;
		if (win_percent <= threshold)
		{
			return true;
		}
	}

	return false;
}


bool Dealer::Strategy(int HandScore)
{
	if (HandScore <= 16)
		return true;
	else
		return false;
}


void Dealer::UpdateSalary()
{
	salary = TrackRecord.size() * salary_rate;
}


int Dealer::getSalary()
{
	return salary; 
}


