#ifndef DEALER_H
#define DEALER_H

#include "BasePerson.h"

 // child class of base person
class Dealer : public BasePerson
{
private:
	double salary;  // declaring the salary to use it in the updateSalary () method after updating the salary
	double salary_rate; // declaring a salary rate to use it in the updateSalary() method
	double threshold;  // declaring the threshold to use it in the losing behaviour method of the dealer
	double startRatio;  // declaring the start cash of the dealer to use it when the dealer go out of the money
	double refillRatio; // declaring the refill amount after going out of the money 

public:
	Dealer(int ID, double salaryRate, double winThreshol, double startAmountRatio, double refillAmountRation);

	int Bet();
	bool Play(int Handscore);
	bool QuittingBehaviour() ;
	bool Strategy(int) ;

	void UpdateSalary(); // declaring the update salarty method to update the salary based on the salary rate
	double getSalary();  // get the salary after updating the salary
};

#endif /* DEALER_H */