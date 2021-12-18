#ifndef AIRGEAD_BANKING_INVESTMENTINFO_H
#define AIRGEAD_BANKING_INVESTMENTINFO_H

#include <vector>

using namespace std;
//InvestedInfo class with class members
class InvestedInfo {

public:
    InvestedInfo();

    const vector<int>& getYears() const;

    void setYears(const vector<int>& t_years);

    const vector<double>& getYearEndBalance() const;

    void setYearEndBalance(const vector<double>& t_yearEndBalance);

    const vector<double>& getYearEndEarnedInterest() const;

    void setYearEndEarnedInterest(const vector<double>& t_yearEndEarnedInterest);

private:
    vector<int> years;

    vector<double> yearEndBalance;

    vector<double> yearEndEarnedInterest;

};


#endif //AIRGEAD_BANKING_INVESTMENTINFO_H