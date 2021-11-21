#include "Dealer.h"

// constructor
Dealer::Dealer(int in_ID, double in_sal, double in_thres, double in_startRatio, double in_refillRatio) : BasePerson(in_ID)
{
	// intializing the attributes of the dealer
	salary = 0.0;
	salary_rate = in_sal;

	threshold = in_thres;

	startRatio = in_startRatio;
	refillRatio = in_refillRatio;
}


int Dealer::Bet()
{
	// TODO: bet money
	return 0;
}

bool Dealer::Play(int Handscore)
{
	return false;
	// TODO: dealer play
}


bool Dealer::QuittingBehaviour()
{
	// when to draw money?
	if (CurrentCash <= 0)
	{
		//TODO: refill event
	}

	// when to go to lounge?
	int wins = 0;
	int losses = 0;
	
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
			// TODO: retire dealer
			return true;
		}
	}
	return false;
}


bool Dealer::Strategy(int HandScore)
{
	if (HandScore <= 16)
		return true;  // hit
	else
		return false; // stay
}


void Dealer::UpdateSalary()
{
	salary = TrackRecord.size() * salary_rate;
}


double Dealer::getSalary()
{
	return salary;
}
