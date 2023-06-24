#ifndef AIRGEAD_BANKING_APP_H
#define AIRGEAD_BANKING_APP_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>

/**
 * AirgeadBankingApp is a simple banking application that calculates year-end reports
 * based on user input such as initial investment amount, monthly deposits, annual interest,
 * and the number of years.
 */
class AirgeadBankingApp {
private:
    double m_initialInvestmentAmount;   // Stores the initial investment amount
    double m_monthlyDeposit;            // Stores the monthly deposit amount
    double m_annualInterest;            // Stores the annual interest rate
    int m_numberOfYears;                // Stores the number of years for calculation

public:
    /**
     * Runs the AirgeadBankingApp, allowing the user to perform calculations multiple times.
     */
    void run();

private:
    /**
     * Displays the input screen for the user to enter the required values.
     */
    void displayInputScreen();

    /**
     * Reads user input and assigns the values to the respective member variables.
     */
    void readUserInput();

    /**
     * Prompts the user for a valid double input with the given message and returns the value.
     * @param message The message displayed to the user as input prompt.
     * @return The valid double value entered by the user.
     */
    double getValidDoubleInput(const std::string& message);

    /**
     * Prompts the user for a valid integer input with the given message and returns the value.
     * @param message The message displayed to the user as input prompt.
     * @return The valid integer value entered by the user.
     */
    int getValidIntInput(const std::string& message);

    /**
     * Displays the values entered by the user.
     */
    void displayEnteredValues();

    /**
     * Displays the year-end reports for investment scenarios.
     */
    void displayYearEndReports();
};

#endif
