#include <iostream>                         // Include input/output library
                                            // No modification from original

using namespace std;                        // Use standard namespace
                                            // Added for simpler cout syntax

// MODIFIED: Class name changed from Number to Balance
class Balance
{
private:

    // MODIFIED: Variable changed from 'value' to 'balance'
    int balance;                            // Stores the balance amount

public:

    // MODIFIED: Constructor changed from Number to Balance
    // MODIFIED: Parameter changed from givenValue to givenBalance
    explicit Balance(int givenBalance)
        : balance(givenBalance)              // MODIFIED: Initialize balance
    {
        // Constructor body is empty
    }

    // MODIFIED: Unary minus operator for Balance class
    // Original: Number operator-() const
    Balance operator-() const
    {
        // MODIFIED: Return a new Balance object
        // with the negative of the stored balance
        return Balance(-balance);
    }

    // Display function
    // MODIFIED: Displays balance instead of value
    void display() const
    {
        cout << balance << "\n";             // MODIFIED: Print balance
    }
};

int main()
{
    // MODIFIED: Object type changed from Number to Balance
    // MODIFIED: Initial value changed from 25 to 2500
    Balance first(2500);

    // MODIFIED: Creates second Balance object using unary minus
    // -first internally calls first.operator-()
    Balance second = -first;

    // MODIFIED: Message changed from "Original value"
    // to "Original balance"
    cout << "Original balance: ";

    // Display the original balance
    first.display();

    // MODIFIED: Message changed from "Negated value"
    // to "Negative balance"
    cout << "Negative balance: ";

    // Display the negative balance
    second.display();

    // End the program successfully
    return 0;
}
