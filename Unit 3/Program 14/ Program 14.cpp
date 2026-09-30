#include <iostream> // For input and output

// Base class
class Base {
public:
    // Virtual function
    virtual void display() const {
        std::cout << "Base object\n";
    }

    // Virtual destructor
    virtual ~Base() = default;
};

// Derived class inherits from Base
class Derived : public Base {
public:
    // Overrides display() function
    void display() const override {
        std::cout << "Derived object\n";
    }
};

// Function receives object by value
void displayByValue(Base object) {
    object.display(); // Calls Base function due to object slicing
}

// Function receives object by reference
void displayByReference(const Base& object) {
    object.display(); // Calls Derived function using polymorphism
}

int main() {
    Derived derived; // Create Derived object

    // Pass Derived object by value
    std::cout << "Passing by value: ";
    displayByValue(derived);

    // Pass Derived object by reference
    std::cout << "Passing by reference: ";
    displayByReference(derived);

    return 0; // End of program
}
