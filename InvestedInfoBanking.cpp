#include <vector>
#include "InvestedInfo.h"

using namespace std;


//Default Constructor
InvestedInfo::InvestedInfo() {}

//Getters and setters for the InvestedInfo class member
const vector<int>& InvestedInfo::getYears() const {
    return years;
}

void InvestedInfo::setYears(const vector<int>& t_years) {
    years = t_years;
}

const vector<double>& InvestedInfo::getYearEndBalance() const {
    return yearEndBalance;
}

void InvestedInfo::setYearEndBalance(const vector<double>& t_yearEndBalance) {
    yearEndBalance = t_yearEndBalance;
}

const vector<double>& InvestedInfo::getYearEndEarnedInterest() const {
    return yearEndEarnedInterest;
}

void InvestedInfo::setYearEndEarnedInterest(const vector<double>& t_yearEndEarnedInterest) {
    yearEndEarnedInterest = t_yearEndEarnedInterest;
}