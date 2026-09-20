#include <iostream>   // Provides input/output functions like cout
#include <memory>     // Provides smart pointers such as unique_ptr and make_unique
#include <string>     // Provides the string data type
#include <vector>     // Provides the vector container

using namespace std;  // Allows using standard library names without std::


// Abstract base class representing a payment method
class PaymentMethod {
protected:
    string transactionId;  // Stores the transaction ID
    double amount;         // Stores the payment amount

public:
    // Constructor to initialize transaction ID and amount
    PaymentMethod(string tid, double amt)
        : transactionId(tid), amount(amt) {}

    // Pure virtual function for processing payment
    // Makes PaymentMethod an abstract class
    virtual bool processPayment() const = 0;

    // Virtual destructor for proper destruction of derived objects
    virtual ~PaymentMethod() = default;
};


// Credit Card Payment class derived from PaymentMethod
class CreditCardPayment : public PaymentMethod {
private:
    string maskedCardNumber;  // Stores the masked card number

public:
    // Constructor to initialize credit card payment details
    CreditCardPayment(string tid, double amt, string card)
        : PaymentMethod(tid, amt), maskedCardNumber(card) {}

    // Overrides the payment processing function
    bool processPayment() const override {

        // Displays credit card transaction details
        cout << "Credit-card transaction " << transactionId
             << " for Rs. " << amount
             << " using " << maskedCardNumber
             << " completed." << endl;

        return true;  // Indicates successful payment
    }
};


// UPI Payment class derived from PaymentMethod
class UPIPayment : public PaymentMethod {
private:
    string upiId;  // Stores the UPI ID

public:
    // Constructor to initialize UPI payment details
    UPIPayment(string tid, double amt, string upi)
        : PaymentMethod(tid, amt), upiId(upi) {}

    // Overrides the payment processing function
    bool processPayment() const override {

        // Displays UPI transaction details
        cout << "UPI transaction " << transactionId
             << " for Rs. " << amount
             << " from " << upiId
             << " completed." << endl;

        return true;  // Indicates successful payment
    }
};


// Net Banking Payment class derived from PaymentMethod
class NetBankingPayment : public PaymentMethod {
private:
    string bankName;  // Stores the bank name

public:
    // Constructor to initialize net banking payment details
    NetBankingPayment(string tid, double amt, string bank)
        : PaymentMethod(tid, amt), bankName(bank) {}

    // Overrides the payment processing function
    bool processPayment() const override {

        // Displays net banking transaction details
        cout << "Net-banking transaction " << transactionId
             << " for Rs. " << amount
             << " through " << bankName
             << " completed." << endl;

        return true;  // Indicates successful payment
    }
};


// Main function - program execution starts here
int main() {

    // Creates a vector to store different payment objects
    // unique_ptr provides automatic memory management
    vector<unique_ptr<PaymentMethod>> payments;

    // Creates a CreditCardPayment object and adds it to the vector
    payments.push_back(
        make_unique<CreditCardPayment>(
            "TXN001", 2500, "XXXX-XXXX-1234"));

    // Creates a UPIPayment object and adds it to the vector
    payments.push_back(
        make_unique<UPIPayment>(
            "TXN002", 1200, "student@upi"));

    // Creates a NetBankingPayment object and adds it to the vector
    payments.push_back(
        make_unique<NetBankingPayment>(
            "TXN003", 5000, "Example Bank"));

    // Displays the program heading
    cout << "===== Payment Gateway =====" << endl;

    // Loops through all payment objects
    for (const auto& payment : payments) {

        // Calls the appropriate processPayment()
        // function using runtime polymorphism
        payment->processPayment();
    }

    // Indicates successful program termination
    return 0;
}
