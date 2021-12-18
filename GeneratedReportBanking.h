#ifndef AIRGEAD_BANKING_REPORTGENERATOR_H
#define AIRGEAD_BANKING_REPORTGENERATOR_H

#include <vector>
#include "InputtedData.h"
#include "Calculations.h"
#include "InvestedInfo.h"

using namespace std;

class GeneratedReport {
public:
    GeneratedReport();

    void generatedReport(InvestedInfo& t_dataOne, InvestedInfo& dataTwo);

    bool additionalSessionCheck();

private:
    void printColumnHeader();

    void annualReport(InvestedInfo& t_data);

};


#endif //AIRGEAD_BANKING_REPORTGENERATOR_H