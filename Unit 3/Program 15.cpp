#include <iostream> // For input and output
#include <string>   // For string operations

// Abstract base class
class Payment {
public:
    // Pure virtual function for payment
    virtual void pay(double amount) const = 0;

    // Virtual destructor
    virtual ~Payment() = default;
};

// Card payment class
class CardPayment : public Payment {
public:
    // Implements payment using card
    void pay(double amount) const override {
        std::cout << "Paid Rs. " << amount << " using card\n";
    }
};

// UPI payment class
class UpiPayment : public Payment {
public:
    // Implements payment using UPI
    void pay(double amount) const override {
        std::cout << "Paid Rs. " << amount << " using UPI\n";
    }
};

// Net banking payment class
class NetBankingPayment : public Payment {
public:
    // Implements payment using net banking
    void pay(double amount) const override {
        std::cout << "Paid Rs. " << amount << " using net banking\n";
    }
};

// Function to process any type of payment
void processPayment(const Payment& payment, double amount) {
    payment.pay(amount); // Calls appropriate pay() function
}

int main() {
    // Create payment method objects
    CardPayment card;
    UpiPayment upi;
    NetBankingPayment netBanking;

    // Process card payment
    processPayment(card, 1250.0);

    // Process UPI payment
    processPayment(upi, 750.0);

    // Process net banking payment
    processPayment(netBanking, 500.0);

    return 0; // End of program
}
