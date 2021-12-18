#include <string>
#include <iostream>
#include <iomanip>
#include "GeneratedReport.h"
#include "Calculations.h"

using namespace std;

const char* YEAR = "Year";
const char* YEAR_END_BAL = "Year End Balance";
const char* YEAR_END_INTEREST = "Year End Interest";

//Default Constructor
GeneratedReport::GeneratedReport() {}

//Prints the column titles
void GeneratedReport::printColumnHeader() {
    cout << string(66, '=') << endl;
    cout << setw(9) << YEAR << setw(26) << YEAR_END_BAL << setw(27) << YEAR_END_INTEREST << endl;
    cout << string(66, '-') << endl;
}

//Prints the headers
void GeneratedReport::generatedReport(InvestedInfo& t_dataOne, InvestedInfo& t_dataTwo) {
    cout << "     Balance and Interest Without Additional Monthly Deposits     \n" << endl;
    annualReport(t_dataOne);

    cout << "     Balance and Interest With Additional Monthly Deposits     \n" << endl;
    annualReport(t_dataTwo);
}

//Prints rows of financial info
void GeneratedReport::annualReport(InvestedInfo& t_data) {
    // Set local vars to producing accurate report
    vector<int> years = t_data.getYears();
    vector<double> yearEndBalance = t_data.getYearEndBalance();
    vector<double> yearEndEarnedInterest = t_data.getYearEndEarnedInterest();

    printColumnHeader();

    //Loops over InvestedInfo object to fill out report
    for (int i = 0; i < years.size(); ++i) {
        cout << setw(9) << years.at(i) << fixed << setprecision(2);
        cout << setw(26) << yearEndBalance.at(i) << fixed << setprecision(2);
        cout << setw(27) << yearEndEarnedInterest.at(i) << fixed << setprecision(2) << endl;
    }
    cout << endl << endl;
}

//Prompts User for another session
bool GeneratedReport::additionalSessionCheck() {
    string text;

    cout << "Press enter to try more values (press 'q' to quit)\n";
    getline(cin, text);

    if (text.empty()) {
        return true;
    }
    else {
        return false;
    }
}