#include <iostream> // For input and output

// Base class
class Base {
public:
    // Base class display function
    void display() const {
        std::cout << "Base display function\n";
    }
};

// Derived class inherits from Base
class Derived : public Base {
public:
    // Derived class display function
    void display() const {
        std::cout << "Derived display function\n";
    }
};

int main() {
    // Create object of Derived class
    Derived derivedObject;

    // Base class pointer points to Derived object
    Base* basePointer = &derivedObject;

    // Calls Base display function
    basePointer->display();

    return 0; // End of program
}
