// David Hughes
// 6/2/23
#include "AirgeadBankingApp.h"

// Runs the Airgead Banking App
void AirgeadBankingApp::run() {
    char choice;
    do {
        displayInputScreen();
        readUserInput();
        displayEnteredValues();
        displayYearEndReports();
        std::cout << "Do you want to calculate again? (Y/N): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
    } while (toupper(choice) == 'Y');
}

// Displays the input screen to the user
void AirgeadBankingApp::displayInputScreen() {
    std::cout << "Airgead Banking App\n";
    std::cout << "--------------------------\n";
    std::cout << "Initial Investment Amount:\n";
    std::cout << "Monthly Deposit:\n";
    std::cout << "Annual Interest:\n";
    std::cout << "Number of Years:\n";
    std::cout << std::endl;
}

// Reads and validates user input
void AirgeadBankingApp::readUserInput() {
    m_initialInvestmentAmount = getValidDoubleInput("Enter Initial Investment Amount: $");
    m_monthlyDeposit = getValidDoubleInput("Enter Monthly Deposit: $");
    m_annualInterest = getValidDoubleInput("Enter Annual Interest (%): ");
    m_numberOfYears = getValidIntInput("Enter Number of Years: ");
}

// Helper function to get a valid double input from the user
double AirgeadBankingApp::getValidDoubleInput(const std::string& message) {
    double value;
    while (true) {
        std::cout << message;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again.\n";
    }
    return value;
}

// Helper function to get a valid integer input from the user
int AirgeadBankingApp::getValidIntInput(const std::string& message) {
    int value;
    while (true) {
        std::cout << message;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again.\n";
    }
    return value;
}

// Displays the entered values to the user
void AirgeadBankingApp::displayEnteredValues() {
    std::cout << "\nEntered Values:\n";
    std::cout << "--------------------------\n";
    std::cout << "Initial Investment Amount: $" << std::fixed << std::setprecision(2) << m_initialInvestmentAmount << std::endl;
    std::cout << "Monthly Deposit: $" << std::fixed << std::setprecision(2) << m_monthlyDeposit << std::endl;
    std::cout << "Annual Interest: %" << std::fixed << std::setprecision(2) << m_annualInterest << std::endl;
    std::cout << "Number of Years: " << m_numberOfYears << std::endl;
    std::cout << std::endl;
}

// Displays the year-end reports for investment scenarios
void AirgeadBankingApp::displayYearEndReports() {
    std::cout << "\nYear-End Reports:\n";
    std::cout << "------------------------------------\n";

    double openingAmount = m_initialInvestmentAmount;

    std::cout << "Without Additional Monthly Deposits:\n";
    std::cout << "    Year |    Year End Balance |    Year End Earned Interest |\n";
    std::cout << "--------------------------------------------------------------\n";
    for (int year = 1; year <= m_numberOfYears; year++) {
        double interest = openingAmount * (m_annualInterest / 100);
        double closingBalance = openingAmount + interest;

        // Format the closing balance and interest as strings for display
        std::ostringstream closingBalanceStream;
        closingBalanceStream << std::fixed << std::setprecision(2) << closingBalance;
        std::string closingBalanceStr = closingBalanceStream.str();

        std::ostringstream interestStream;
        interestStream << std::fixed << std::setprecision(2) << interest;
        std::string interestStr = interestStream.str();

        // Display the year-end report for the current year
        std::cout << std::setw(8) << std::right << year << " |";
        std::cout << std::setw(20 - closingBalanceStr.length()) << "$" << closingBalanceStr << " |";
        std::cout << std::setw(28 - interestStr.length()) << "$" << interestStr << " |" << std::endl;

        openingAmount = closingBalance;
    }

    openingAmount = m_initialInvestmentAmount;

    std::cout << "\nWith Additional $" << std::fixed << std::setprecision(2) << m_monthlyDeposit << " Monthly Deposits:\n";
    std::cout << "    Year |    Year End Balance |    Year End Earned Interest |\n";
    std::cout << "--------------------------------------------------------------\n";
    for (int year = 1; year <= m_numberOfYears; year++) {
        double closingBalance = openingAmount;
        double totalEarnedInterest = 0;
        for (int month = 1; month <= 12; month++) {
            double interest = (closingBalance + m_monthlyDeposit) * ((m_annualInterest / 100) / 12);
            totalEarnedInterest += interest;
            closingBalance = closingBalance + m_monthlyDeposit + interest;
        }

        // Format the closing balance and total interest as strings for display
        std::ostringstream closingBalanceStream;
        closingBalanceStream << std::fixed << std::setprecision(2) << closingBalance;
        std::string closingBalanceStr = closingBalanceStream.str();

        std::ostringstream interestStream;
        interestStream << std::fixed << std::setprecision(2) << totalEarnedInterest;
        std::string interestStr = interestStream.str();

        // Display the year-end report for the current year
        std::cout << std::setw(8) << std::right << year << " |";
        std::cout << std::setw(20 - closingBalanceStr.length()) << "$" << closingBalanceStr << " |";
        std::cout << std::setw(28 - interestStr.length()) << "$" << interestStr << " |" << std::endl;

        openingAmount = closingBalance;
    }

    std::cout << std::endl;
}

int main() {
    AirgeadBankingApp app;
    app.run();
    return 0;
}
