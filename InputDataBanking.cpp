#include <iostream>
#include <vector>
#include "InputtedData.h"

using namespace std;

//Default constructor for Inputted Data
InputData::InputData() {
    InputData::userInputs = {
        "Initial Investment Amount:  ",
                "Monthly Deposit:  ",
                "Annual Interest:  ",
                "Number of Years:  "
    };
};
const vector<string> &InputData::getUserInputs() const {
    return userInputs;
}

//Getter and Setter Methods for users inputs
double InputData::getInitialInvestedAmount() const {
    return initialInvestedAmount;
}

void InputData::setInitialInvestedAmount(double t_initialInvestedAmount) {
    initialInvestedAmount = t_initialInvestedAmount;
}

double InputData::getMonthlyDeposit() const {
    return monthlyDeposit;
}

void InputData::setMonthlyDeposit(double t_monthlyDeposit) {
    monthlyDeposit = t_monthlyDeposit;
}

double InputData::getAnnualInterest() const {
    return annualInterest;
}

void InputData::setAnnualInterest(double t_annualInterest) {
    annualInterest = t_annualInterest;
}

double InputData::getNumberOfYears() const {
    return numberOfYears;
}

void InputData::setNumberOfYears(double t_numberOfYears) {
    numberOfYears = t_numberOfYears;
}

//Printers the Data Input header for User inputs
void InputData::printHeader() {
    cout << string(36, '*') << endl;
    cout << string(12, '*') << " Data Input " << string(12, '*') << endl;
}

//Stores User inputs and sets them to class members
void InputData::promptUser() {
    vector<double> depositDetails;
    char quitCommand = 'a';  //Starts an infinite loop until all requirements are met

    while (quitCommand != 'q') {    //Starts a while loop that continues as long as the User doesn't type a 'q' character

        try {
            //Clears any previous collections of inputs
            depositDetails.clear();
            //Displays header
            printHeader();
            //Collects users inputs
            depositDetails = inputCapture();

        }
        //Catches any invalid arguments
        catch (invalid_argument& except) {
            cin.clear(); //Clears errors
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clears out the input buffer
            cout << except.what() << endl;
        }

        //Checks if depositDetails vector is full and if the User wants to continue
        if (depositDetails.size() == 4 && enterCheck()) {
            //Sets private members
            setInitialInvestedAmount(depositDetails.at(0));
            setMonthlyDeposit(depositDetails.at(1));
            setAnnualInterest(depositDetails.at(2));
            setNumberOfYears(depositDetails.at(3));

            //Exits this class and goes back to the main() function
            quitCommand = 'q';
        }
    }
}

//Loops users inputs and stores them
vector<double> InputData::inputCapture() {
    //Collects user inputs and puts them in a vector of responses
    vector<double> responses;
    vector<string> prompts = getUserInputs();

    for (int i = 0; i < prompts.size(); ++i) {
        string prompt = prompts.at(i);
        double userInput;
        cout << prompt;
        cin >> userInput;

        //This checks for valid inputs from the User
        if (!cin || userInput < 0.01) {
            throw invalid_argument("\n\nAlphabetical characters and amounts less than .01 not allowed. \n\n"
                "Please try again.\n\n");
        }

        //Adds the users input to the responses vector
        responses.push_back(userInput);
    }
    return responses;
}
//Method to check for any key to be pressed
bool InputData::enterCheck() {
    cout << "Press enter to continue . . .\n\n\n";
    return cin.get() == '\n';
}