#include <iostream>  // Used for input and output operations

// Base class
class Vehicle {

public:

    // Virtual function that can be overridden by derived classes
    virtual void move() const {
        std::cout << "Vehicle is moving\n";
    }

    // Virtual destructor for proper destruction of derived objects
    virtual ~Vehicle() = default;
};

// Car inherits from Vehicle
class Car : public Vehicle {

public:

    // Overrides the move() function of Vehicle
    void move() const override {
        std::cout << "Car moves on roads\n";
    }
};

// Boat inherits from Vehicle
class Boat : public Vehicle {

public:

    // Overrides the move() function of Vehicle
    void move() const override {
        std::cout << "Boat moves on water\n";
    }
};

// Main function - program execution starts here
int main() {

    // Creates a Car object
    Car car;

    // Creates a Boat object
    Boat boat;

    // Calls Car's overridden move() function
    car.move();

    // Calls Boat's overridden move() function
    boat.move();

    // Ends the program successfully
    return 0;
}
