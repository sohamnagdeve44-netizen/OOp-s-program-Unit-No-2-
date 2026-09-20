#include <iostream>   // For input and output operations
#include <string>     // For using string
#include <utility>    // For std::move

// Base class for all vehicles
class Vehicle {

protected:
    std::string registrationNumber;  // Stores vehicle registration number
    double ratePerDay;               // Stores rental rate per day

public:
    // Constructor to initialize vehicle details
    Vehicle(std::string registration, double rate)
        : registrationNumber(std::move(registration)), ratePerDay(rate) {}

    // Virtual function to calculate rent
    virtual double calculateRent(int days) const {
        return ratePerDay * days;   // Basic rent calculation
    }

    // Virtual function to display vehicle details
    virtual void display() const {
        std::cout << "Registration: "
                  << registrationNumber << '\n';

        std::cout << "Rate per day: "
                  << ratePerDay << '\n';
    }

    // Virtual destructor
    virtual ~Vehicle() = default;
};

// Car class inherits from Vehicle
class Car : public Vehicle {

private:
    int numberOfDoors;   // Stores number of doors

public:
    // Constructor to initialize car details
    Car(std::string registration, double rate, int doors)
        : Vehicle(std::move(registration), rate),
          numberOfDoors(doors) {}

    // Override display function
    void display() const override {

        // Display base class vehicle details
        Vehicle::display();

        // Display number of doors
        std::cout << "Doors: " << numberOfDoors << '\n';
    }
};

// Bike class inherits from Vehicle
class Bike : public Vehicle {

private:
    int engineCapacity;   // Stores engine capacity

public:
    // Constructor to initialize bike details
    Bike(std::string registration, double rate, int capacity)
        : Vehicle(std::move(registration), rate),
          engineCapacity(capacity) {}

    // Override calculateRent function
    double calculateRent(int days) const override {

        // Calculate rent with 10% discount
        return ratePerDay * days * 0.9;
    }

    // Override display function
    void display() const override {

        // Display base class vehicle details
        Vehicle::display();

        // Display engine capacity
        std::cout << "Engine Capacity: "
                  << engineCapacity << " cc\n";
    }
};

int main() {

    // Create Car object
    Car car("MH12AB1234", 2000.0, 5);

    // Create Bike object
    Bike bike("MH12CD5678", 800.0, 150);

    // Display car details
    std::cout << "Car Details\n";
    car.display();

    // Calculate and display car rent for 3 days
    std::cout << "Rent for 3 days: "
              << car.calculateRent(3) << "\n\n";

    // Display bike details
    std::cout << "Bike Details\n";
    bike.display();

    // Calculate and display bike rent for 3 days
    std::cout << "Rent for 3 days: "
              << bike.calculateRent(3) << '\n';

    return 0;   // End of program
}
