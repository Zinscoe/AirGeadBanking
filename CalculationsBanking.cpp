
#include <vector>
#include <iostream>
#include "Calculations.h"
#include "InvestedInfo.h"

using namespace std;

const long MAX_AMOUNT = 9999999999999999;

//Default constructor
Calculations::Calculations() {}

//Takes users inputs and builds InvestedInfo that has user balance and interests
InvestedInfo Calculations::calculateAnnualInvestment(InputData& t_userData, bool t_monthlyDeposit) {
    
    //This sorts out user inputs
    double openAmount = t_userData.getInitialInvestedAmount();
    double depositAmount = t_userData.getMonthlyDeposit();
    int interestRate = t_userData.getAnnualInterest();
    int numberOfYears = t_userData.getNumberOfYears();
    vector<int> years;
    vector<vector<double>> yearEndBalance;

    //Creating an object to store data
    InvestedInfo investmentDetails;

    try {

        //Return years as array of integers for display
        for (int i = 0; i < numberOfYears; ++i) {
            years.push_back(i + 1);
        }

        if (t_monthlyDeposit == false) {
            //Calculates without monthly deposit
            yearEndBalance = annualBalanceWithInterest(openAmount, 0, interestRate, numberOfYears);
        }
        else {
            //Calculates with monthly deposits
            yearEndBalance = annualBalanceWithInterest(openAmount, depositAmount, interestRate, numberOfYears);
        }

        //This populates Invested properties
        investmentDetails.setYears(years);
        investmentDetails.setYearEndEarnedInterest(yearEndBalance.at(0));
        investmentDetails.setYearEndBalance(yearEndBalance.at(1));

        return investmentDetails;
    }
    catch (runtime_error& except) {
        cout << except.what() << endl;
    }

}

//Calculates annual account balance as wel as earned interest
vector<vector<double>> Calculations::annualBalanceWithInterest(double t_openAmount, double t_depositAmount, int t_interestRate, int t_years) {
    //Variables to manipulate data for accurate calculations
    vector<vector<double>> balanceAndInterest;
    vector<double> annualInterestOnly;
    vector<double> annualBalanceWithInterest;
    double newBalance;
    double yearEndInterest = 0;
    double precInterestRate = (t_interestRate / 100.00) / 12.00;
    double interestTracker = 0;
    double interestOnly = 0;

    //Loops over months and calculates annual balances & earned interests
    for (int i = 0; i < (t_years * 12); ++i) {
        yearEndInterest += ((interestTracker + t_openAmount) + (t_depositAmount * (i + 1))) * precInterestRate;
        //Allows tracking earned interest
        interestTracker = yearEndInterest;
        if (((i + 1) % 12) == 0) {
            annualInterestOnly.push_back(yearEndInterest - interestOnly); //Adds just the annual interest to the vector
            interestOnly = yearEndInterest;
            newBalance = t_openAmount + (t_depositAmount * (i + 1)) + yearEndInterest; //Adds interest and such
            annualBalanceWithInterest.push_back(newBalance); //Adds annual balance with interest to the second vector
        }
    }

    if (newBalance > MAX_AMOUNT) {
        throw runtime_error("Unable to complete calculation. Amount too large.");
    }

    balanceAndInterest.push_back(annualInterestOnly); //A vector for tracking interest
    balanceAndInterest.push_back(annualBalanceWithInterest); //Vector for tracking interest and balance

    //Passes vectors back to the InvestedInfo vectors
    return balanceAndInterest;
}











