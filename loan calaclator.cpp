#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to calculate EMI
double calculateEMI(double principal, double annualInterestRate, int tenureInYears) {
    double monthlyInterestRate = annualInterestRate / (12 * 100); // Convert annual interest rate to monthly
    int totalMonths = tenureInYears * 12;

    // EMI formula: EMI = [P * r * (1 + r)^n] / [(1 + r)^n - 1]
    double emi = (principal * monthlyInterestRate * pow(1 + monthlyInterestRate, totalMonths)) /
                 (pow(1 + monthlyInterestRate, totalMonths) - 1);

    return emi;
}

int main() {
    double principal;
    double annualInterestRate;
    int tenureInYears;

    // Input principal, interest rate, and tenure
    cout << "Enter the loan amount (Principal): ";
    cin >> principal;

    cout << "Enter the annual interest rate (in %): ";
    cin >> annualInterestRate;

    cout << "Enter the loan tenure (in years): ";
    cin >> tenureInYears;

    // Calculate EMI
    double emi = calculateEMI(principal, annualInterestRate, tenureInYears);

    // Display results
    cout << fixed << setprecision(2);
    cout << "\nFor a loan amount of " << principal << " at an annual interest rate of " << annualInterestRate 
         << "% over " << tenureInYears << " years:\n";
    cout << "Monthly EMI: " << emi << endl;

    return 0;
}
