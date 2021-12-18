#ifndef AIRGEAD_BANKING_DATAINPUT_H
#define AIRGEAD_BANKING_DATAINPUT_H

#include <vector>

using namespace std;
//InputData class with members within it
class InputData {
public:
    InputData();
    
    //Getter and setter methods for class members of InputData class
    const vector<string>& getUserInputs() const;

    double getInitialInvestedAmount() const;

    void setInitialInvestedAmount(double t_initialInvestedAmount);

    double getMonthlyDeposit() const;

    void setMonthlyDeposit(double t_monthlyDeposit);

    double getAnnualInterest() const;

    void setAnnualInterest(double t_annualInterest);

    double getNumberOfYears() const;

    void setNumberOfYears(double t_numberOfYears);

    void promptUser();

private:
    vector<string> userInputs;

    double initialInvestedAmount;

    double monthlyDeposit;

    double annualInterest;

    double numberOfYears;

    void printHeader();

    vector<double> inputCapture();

    bool enterCheck();
};


#endif //AIRGEAD_BANKING_DATAINPUT_H