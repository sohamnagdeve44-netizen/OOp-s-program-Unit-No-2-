#include <iostream>   // Provides input/output functions like cout
#include <memory>     // Provides smart pointers like unique_ptr and make_unique
#include <string>     // Provides the string data type
#include <vector>     // Provides the vector container

using namespace std;  // Allows using standard library names without std::


// Base class representing a general vehicle
class Vehicle {
protected:
    string vehicleId;          // Stores the vehicle ID
    string registrationNumber; // Stores the vehicle registration number
    double fuelLevel;          // Stores the current fuel level

public:
    // Constructor to initialize vehicle ID and registration number
    // Fuel level is initially set to 100%
    Vehicle(string vid, string reg)
        : vehicleId(vid), registrationNumber(reg), fuelLevel(100.0) {}

    // Starts the vehicle engine
    void startEngine() const {
        cout << "Vehicle " << vehicleId
             << " engine started." << endl;
    }

    // Adds fuel to the vehicle
    void refuel(double amount) {
        fuelLevel += amount;  // Increase fuel level

        // Prevents fuel level from exceeding 100%
        if (fuelLevel > 100.0) {
            fuelLevel = 100.0;
        }
    }

    // Virtual function to display vehicle information
    // It can be overridden by derived classes
    virtual void displayInfo() const {
        cout << "Vehicle ID: " << vehicleId
             << " | Registration: " << registrationNumber
             << " | Fuel: " << fuelLevel << "%" << endl;
    }

    // Virtual destructor for proper destruction of derived objects
    virtual ~Vehicle() = default;
};


// Truck class derived from Vehicle
class Truck : public Vehicle {
private:
    double cargoCapacity;  // Stores truck cargo capacity in tonnes

public:
    // Constructor to initialize truck details
    Truck(string vid, string reg, double capacity)
        : Vehicle(vid, reg), cargoCapacity(capacity) {}

    // Overrides the displayInfo() function
    void displayInfo() const override {
        cout << "Truck: ";

        // Calls the base class displayInfo()
        Vehicle::displayInfo();

        // Displays truck-specific information
        cout << "Cargo capacity: "
             << cargoCapacity << " tonnes" << endl;
    }
};


// Delivery Van class derived from Vehicle
class DeliveryVan : public Vehicle {
private:
    int packageCount;  // Stores the number of packages loaded

public:
    // Constructor to initialize delivery van details
    DeliveryVan(string vid, string reg, int packages)
        : Vehicle(vid, reg), packageCount(packages) {}

    // Overrides the displayInfo() function
    void displayInfo() const override {
        cout << "Delivery Van: ";

        // Calls the base class displayInfo()
        Vehicle::displayInfo();

        // Displays number of packages loaded
        cout << "Packages loaded: "
             << packageCount << endl;
    }
};


// Bike class derived from Vehicle
class Bike : public Vehicle {
private:
    bool hasDeliveryBox;  // Stores whether the bike has a delivery box

public:
    // Constructor to initialize bike details
    Bike(string vid, string reg, bool hasBox)
        : Vehicle(vid, reg), hasDeliveryBox(hasBox) {}

    // Overrides the displayInfo() function
    void displayInfo() const override {
        cout << "Delivery Bike: ";

        // Calls the base class displayInfo()
        Vehicle::displayInfo();

        // Displays delivery box availability
        cout << "Delivery box: "
             << (hasDeliveryBox ? "Available" : "Not available")
             << endl;
    }
};


// Main function - program execution starts here
int main() {

    // Creates a vector of unique_ptr to store different vehicle objects
    vector<unique_ptr<Vehicle>> fleet;

    // Creates a Truck object and adds it to the fleet
    fleet.push_back(
        make_unique<Truck>(
            "TR001", "MH12AB1234", 10.5));

    // Creates a Delivery Van object and adds it to the fleet
    fleet.push_back(
        make_unique<DeliveryVan>(
            "DV001", "MH12CD5678", 50));

    // Creates a Bike object and adds it to the fleet
    fleet.push_back(
        make_unique<Bike>(
            "BK001", "MH12EF9012", true));

    // Displays the fleet heading
    cout << "===== Fleet Status =====" << endl;

    // Loops through every vehicle in the fleet
    for (const auto& vehicle : fleet) {

        // Starts the engine of the current vehicle
        vehicle->startEngine();

        // Displays vehicle-specific information
        // Runtime polymorphism calls the correct overridden function
        vehicle->displayInfo();

        // Prints a blank line between vehicle details
        cout << endl;
    }

    // Indicates successful program termination
    return 0;
}
