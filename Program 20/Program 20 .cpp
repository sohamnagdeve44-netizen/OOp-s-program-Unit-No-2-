#include <iostream>   // Provides input/output functions like cout
#include <string>     // Provides the string data type
#include <vector>     // Provides the vector container
#include <memory>     // Provides smart pointers like unique_ptr and make_unique

using namespace std;  // Allows using standard library names without std::


// Base class representing a general bank account
class Account {
protected:
    int accountNumber;    // Stores the account number
    string holderName;    // Stores the account holder's name
    double balance;       // Stores the account balance

public:
    // Constructor to initialize account details
    Account(int accNo, string name, double bal)
        : accountNumber(accNo), holderName(name), balance(bal) {}

    // Function to deposit money into the account
    void deposit(double amount) {

        // Checks whether the deposit amount is positive
        if (amount > 0) {
            balance += amount;  // Adds amount to the balance

            // Displays the deposited amount
            cout << "Deposited Rs. " << amount << endl;
        }
    }

    // Virtual function to withdraw money
    // It can be overridden by derived classes
    virtual void withdraw(double amount) {

        // Checks whether amount is valid and available
        if (amount > 0 && amount <= balance) {
            balance -= amount;  // Deducts amount from balance

            // Displays the withdrawn amount
            cout << "Withdrawn Rs. " << amount << endl;
        }
        else {
            // Displays message when withdrawal is not possible
            cout << "Insufficient balance!" << endl;
        }
    }

    // Pure virtual function for calculating interest
    // Makes Account an abstract class
    virtual double calculateInterest() const = 0;

    // Virtual function to display account details
    virtual void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    // Virtual destructor for proper destruction of derived objects
    virtual ~Account() = default;
};


// Savings Account class derived from Account
class SavingsAccount : public Account {
private:
    double interestRate;  // Stores savings account interest rate

public:
    // Constructor to initialize savings account details
    SavingsAccount(int accNo, string name, double bal, double rate)
        : Account(accNo, name, bal), interestRate(rate) {}

    // Overrides the interest calculation function
    double calculateInterest() const override {

        // Interest = Balance × Rate / 100
        return balance * interestRate / 100;
    }

    // Overrides the display function
    void display() const override {

        // Displays account type
        cout << "\n--- Savings Account ---" << endl;

        // Displays common account information
        Account::display();

        // Displays calculated interest
        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};


// Current Account class derived from Account
class CurrentAccount : public Account {
private:
    double interestRate;  // Stores current account interest rate

public:
    // Constructor to initialize current account details
    CurrentAccount(int accNo, string name, double bal, double rate)
        : Account(accNo, name, bal), interestRate(rate) {}

    // Overrides the interest calculation function
    double calculateInterest() const override {

        // Interest = Balance × Rate / 100
        return balance * interestRate / 100;
    }

    // Overrides the display function
    void display() const override {

        // Displays account type
        cout << "\n--- Current Account ---" << endl;

        // Displays common account information
        Account::display();

        // Displays calculated interest
        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};


// Fixed Deposit Account class derived from Account
class FixedDepositAccount : public Account {
private:
    double interestRate;  // Stores FD interest rate
    int duration;         // Stores FD duration in years

public:
    // Constructor to initialize FD account details
    FixedDepositAccount(int accNo, string name, double bal,
                        double rate, int years)
        : Account(accNo, name, bal),
          interestRate(rate),
          duration(years) {}

    // Overrides the interest calculation function
    double calculateInterest() const override {

        // Interest = Balance × Rate × Duration / 100
        return balance * interestRate * duration / 100;
    }

    // Overrides the withdrawal function
    void withdraw(double amount) override {

        // Withdrawal is restricted before FD maturity
        cout << "Withdrawal is not allowed before FD maturity."
             << endl;
    }

    // Overrides the display function
    void display() const override {

        // Displays account type
        cout << "\n--- Fixed Deposit Account ---" << endl;

        // Displays common account information
        Account::display();

        // Displays FD duration
        cout << "Duration: " << duration
             << " years" << endl;

        // Displays calculated interest
        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};


// Main function - program execution starts here
int main() {

    // Creates a vector to store different account objects
    vector<unique_ptr<Account>> accounts;

    // Creates a SavingsAccount object and adds it to the vector
    accounts.push_back(
        make_unique<SavingsAccount>(
            101, "Rahul", 50000, 4.0));

    // Creates a CurrentAccount object and adds it to the vector
    accounts.push_back(
        make_unique<CurrentAccount>(
            102, "Priya", 75000, 2.0));

    // Creates a FixedDepositAccount object and adds it to the vector
    accounts.push_back(
        make_unique<FixedDepositAccount>(
            103, "Amit", 100000, 7.0, 3));

    // Displays the banking system heading
    cout << "===== BANKING SYSTEM =====" << endl;


    // Deposit and withdrawal operations for Savings Account
    accounts[0]->deposit(5000);   // Deposits Rs. 5000
    accounts[0]->withdraw(3000);  // Withdraws Rs. 3000


    // Deposit and withdrawal operations for Current Account
    accounts[1]->deposit(10000);  // Deposits Rs. 10000
    accounts[1]->withdraw(5000);  // Withdraws Rs. 5000


    // Deposit and withdrawal operations for Fixed Deposit Account
    accounts[2]->deposit(20000);  // Deposits Rs. 20000
    accounts[2]->withdraw(10000); // Withdrawal is restricted


    // Displays account details heading
    cout << "\n===== ACCOUNT DETAILS =====" << endl;


    // Loops through all account objects
    for (const auto& account : accounts) {

        // Calls the appropriate display() function
        // using runtime polymorphism
        account->display();
    }


    // Indicates successful program termination
    return 0;
}
