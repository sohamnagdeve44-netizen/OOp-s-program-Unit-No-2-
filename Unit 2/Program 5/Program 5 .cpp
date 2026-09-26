#include <iostream>      // Used for input and output operations
#include <string>        // Used for string data type
#include <utility>       // Used for std::move()

// Base class
class Vehicle {

protected:
    std::string registrationNumber;  // Stores vehicle registration number

public:

    // Constructor of Vehicle class
    explicit Vehicle(std::string registration)
        : registrationNumber(std::move(registration)) {}

    // Function to start the vehicle
    void start() const {
        std::cout << "Vehicle " << registrationNumber
                  << " started\n";
    }
};

// Car inherits from Vehicle
class Car : public Vehicle {

public:

    // Constructor of Car class
    explicit Car(std::string registration)
        : Vehicle(std::move(registration)) {}  // Calls Vehicle constructor

    // Function to open car boot
    void openBoot() const {
        std::cout << "Car boot opened\n";
    }
};

// Bike inherits from Vehicle
class Bike : public Vehicle {

public:

    // Constructor of Bike class
    explicit Bike(std::string registration)
        : Vehicle(std::move(registration)) {}  // Calls Vehicle constructor

    // Function to remind about helmet
    void helmetReminder() const {
        std::cout << "Please wear a helmet\n";
    }
};

// Main function - program execution starts here
int main() {

    // Creates Car object with registration number
    Car car("MH12AB1234");

    // Creates Bike object with registration number
    Bike bike("MH12CD5678");

    // Calls inherited start() function for car
    car.start();

    // Calls Car's own function
    car.openBoot();

    // Calls inherited start() function for bike
    bike.start();

    // Calls Bike's own function
    bike.helmetReminder();

    // Ends the program successfully
    return 0;
}
