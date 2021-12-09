#ifndef DEALER_H
#define DEALER_H


#include "BasePerson.h"


class Dealer : public BasePerson
{
private:
	int dealerSalary;
	int salaryRate;
	int lossThreshold;

public:
	Dealer(int ID, int salaryRate, int lossThreshold);

	int Bet() override;
	bool QuittingBehaviour() override;
	bool Strategy(int) override;

	void UpdateSalary();
	double GetSalary();


};


#endif /* DEALER_H */