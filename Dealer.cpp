#include "Dealer.h"

#include "GameTable.h"


// constructor
Dealer::Dealer(int in_ID, int in_sal, int in_thres) : BasePerson(in_ID)
{
	dealerSalary = 0;
	salaryRate = in_sal;
	lossThreshold = in_thres;
}



int Dealer::Bet()
{
	return 0;
}


bool Dealer::QuittingBehaviour()
{
	// when to go to lounge?

	// calculate wins and losses
	int wins = 0, losses = 0;
	for (char& c : trackRecord)
	{
		if (c == 'W')
			wins++;
		else if (c == 'L')
			losses++;
	}

	// determine if they retire or not
	if (trackRecord.size() > 0)
	{
		double win_percent = (double)wins / trackRecord.size() * 100;
		if (win_percent <= lossThreshold)
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
	dealerSalary = (int)trackRecord.size() * salaryRate;
}


double Dealer::GetSalary()
{
	return dealerSalary;
}
