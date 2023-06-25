#include <iostream>
#include <iomanip>

class InvestmentCalculator {
private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numYears;

public:
    InvestmentCalculator(double initialInvestment, double monthlyDeposit, double annualInterest, int numYears)
        : initialInvestment(initialInvestment), monthlyDeposit(monthlyDeposit),
        annualInterest(annualInterest), numYears(numYears) {}

    void displayInvestmentSummary() {
        // Display the investment details entered by the user
        std::cout << "******************************************" << std::endl;
        std::cout << "*************** Data Inputed *************" << std::endl;
        std::cout << "Initial Investment Amount: $" << initialInvestment << std::endl;
        std::cout << "Monthly Deposit: $" << monthlyDeposit << std::endl;
        std::cout << "Annual Interest (Compounded): " << annualInterest << "%" << std::endl;
        std::cout << "Number of Years: " << numYears << std::endl;
        std::cout << std::endl;

        // Prompt the user to press any key to continue
        std::cout << "Press any key to continue...";
        std::cin.get();

        std::cout << std::endl;
        std::cout << "******************************************" << std::endl;
        std::cout << "******************************************" << std::endl;
        std::cout << "******************************************" << std::endl;
        std::cout << std::endl;

        // Display year-end balances without monthly deposits
        std::cout << "Year-End Balances (No Monthly Deposits):" << std::endl;
        calculateYearEndBalances(false);

        std::cout << std::endl;
        std::cout << "******************************************" << std::endl;
        std::cout << "******************************************" << std::endl;
        std::cout << std::endl;

        // Display year-end balances with monthly deposits
        std::cout << "Year-End Balances (With Monthly Deposits):" << std::endl;
        calculateYearEndBalances(true);

    }

private:
    void calculateYearEndBalances(bool includeMonthlyDeposits) {
        double openingAmount = initialInvestment;
        double closingBalance = openingAmount;
        double totalInterest = 0.0;

        for (int year = 1; year <= numYears; ++year) {
            // Display the year number
            std::cout << "Year " << year << ":" << std::endl;

            if (includeMonthlyDeposits) {
                // Display the opening balance and deposited amount
                std::cout << "  Opening Balance: $" << std::fixed << std::setprecision(2) << openingAmount << std::endl;
                std::cout << "  Deposited Amount: $" << monthlyDeposit << std::endl;
                // Update the closing balance by adding the monthly deposit
                closingBalance += monthlyDeposit;
            }

            // Calculate the interest and update the closing balance
            double interest = closingBalance * ((annualInterest / 100.0) / 12.0);
            totalInterest += interest;
            closingBalance += interest;

            // Display the interest earned and closing balance for the year
            std::cout << "  Interest Earned: $" << std::fixed << std::setprecision(2) << interest << std::endl;
            std::cout << "  Closing Balance: $" << std::fixed << std::setprecision(2) << closingBalance << std::endl;
            std::cout << std::endl;
        }

        // Display the total interest earned
        std::cout << "******************************" << std::endl;
        std::cout << "*Total Interest Earned: $" << std::fixed << std::setprecision(2) << totalInterest << "*" << std::endl;
        std::cout << "******************************" << std::endl;
    }
};

int main() {
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numYears;

    // Input investment details from the user
    std::cout << "******************************************" << std::endl;
    std::cout << "*************** Data Input ***************" << std::endl;

    std::cout << "Enter Initial Investment Amount: $";
    std::cin >> initialInvestment;

    std::cout << "Enter Monthly Deposit: $";
    std::cin >> monthlyDeposit;

    std::cout << "Enter Annual Interest (Compounded): ";
    std::cin >> annualInterest;

    std::cout << "Enter Number of Years: ";
    std::cin >> numYears;

    // Prompt the user to press any key to continue
    std::cout << "Press any key to continue..." << std::endl;

    // Wait for user input
    std::cin.ignore();  // Ignore the previous newline character
    std::cin.get();     // Wait for user input

    // Create an instance of InvestmentCalculator and display the investment summary
    InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterest, numYears);
    calculator.displayInvestmentSummary();

    return 0;
}