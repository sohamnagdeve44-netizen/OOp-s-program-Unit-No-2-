#include <iostream>  // Used for input and output operations

// Base class
class Base {

public:

    // Constructor of Base class
    Base() {
        std::cout << "Base constructor\n";
    }

    // Destructor of Base class
    ~Base() {
        std::cout << "Base destructor\n";
    }
};

// Derived class inherits from Base
class Derived : public Base {

public:

    // Constructor of Derived class
    Derived() {
        std::cout << "Derived constructor\n";
    }

    // Destructor of Derived class
    ~Derived() {
        std::cout << "Derived destructor\n";
    }
};

// Main function - program execution starts here
int main() {

    // Creates an object of Derived class
    Derived object;

    // Object is automatically destroyed here
    // Destructors are called in reverse order

    // Ends the program successfully
    return 0;
}
