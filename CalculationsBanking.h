#ifndef AIRGEAD_BANKING_CALCULATIONS_H
#define AIRGEAD_BANKING_CALCULATIONS_H

#include <vector>
#include "InputtedData.h"
#include "InvestedInfo.h"

using namespace std;
//Creates the Calculations class and it's members
class Calculations {

public:
    Calculations();

    InvestedInfo calculateAnnualInvestment(InputData& data, bool t_monthlyDeposit = false);

private:
    vector<vector<double>> annualBalanceWithInterest(double t_openAmount, double t_depositAmount, int t_interestRate, int t_years);
};


#endif //AIRGEAD_BANKING_CALCULATIONS_H