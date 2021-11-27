#ifndef DEALER_H
#define DEALER_H


#include "BasePerson.h"


class Dealer : public BasePerson
{
private:
	int salary;
	int salary_rate;
	int threshold;

public:
	Dealer(int ID, int salaryRate, int winThreshol);

	int Bet() override;
	bool QuittingBehaviour() override;
	bool Strategy(int) override;

	void UpdateSalary();
	double getSalary();
};


#endif /* DEALER_H */