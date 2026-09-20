#include <iostream>   // For input and output operations

// Account class
class Account {

private:
    double balance;   // Stores the account balance

    // Auditor is declared as a friend class
    friend class Auditor;

public:
    // Constructor to initialize the account balance
    explicit Account(double initialBalance)
        : balance(initialBalance) {}
};

// Auditor class
class Auditor {

public:
    // Function to inspect and display account balance
    void inspect(const Account& account) const {

        // Accessing private balance because Auditor is a friend class
        std::cout << "Account Balance: "
                  << account.balance << '\n';
    }
};

int main() {

    // Create an Account object with balance 5000
    Account account(5000.0);

    // Create an Auditor object
    Auditor auditor;

    // Call inspect() to display the account balance
    auditor.inspect(account);

    return 0;   // End of program
}
