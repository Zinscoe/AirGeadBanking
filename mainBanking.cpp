#include <string>
#include <iostream>
#include "InputtedData.h"
#include "Calculations.h"
#include "InvestedInfo.h"
#include "GeneratedReport.h"

using namespace std;
//Declares the startApp function
void startApp() {
    bool restart = true;

    try {
        do {
            //Prompts the user for inputs an stores the users inputs
            InputData userData;
            userData.promptUser();

            //Passes Users inputs to make appropriate calculations
            Calculations calculations;
            InvestedInfo acctWithNoMonthlyDeposit = calculations.calculateAnnualInvestment(userData);
            InvestedInfo acctWithMonthlyDeposit = calculations.calculateAnnualInvestment(userData, true);

            //Relays info back to the User
            GeneratedReport balanceAndInterestReport;
            balanceAndInterestReport.generatedReport(acctWithNoMonthlyDeposit, acctWithMonthlyDeposit);

            //Prompts User to continue or not
            restart = balanceAndInterestReport.additionalSessionCheck();
        } while (restart);
    }
    catch (runtime_error& except) {
        cout << "Oops! Something went wrong. Exception: " << except.what() << endl;
    }
}

int main() {

    startApp();

    return 0;
}