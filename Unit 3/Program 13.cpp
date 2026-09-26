#include <iostream> // For input and output

// Base class
class Base {
public:
    // Virtual destructor
    virtual ~Base() {
        std::cout << "Base destructor\n";
    }
};

// Derived class inherits from Base
class Derived : public Base {
public:
    // Overrides the base class destructor
    ~Derived() override {
        std::cout << "Derived destructor\n";
    }
};

int main() {
    // Base pointer points to Derived object
    Base* pointer = new Derived();

    // Deletes object and calls destructors in proper order
    delete pointer;

    return 0; // End of program
}
