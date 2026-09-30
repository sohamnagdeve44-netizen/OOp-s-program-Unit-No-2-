#include <iostream>                         // Includes input/output library

class Distance {                            // Defines the Distance class
private:
    int meters;                             // Stores distance in meters

public:
    // Constructor to initialize the meters value
    explicit Distance(int value) : meters(value) {}

    // MODIFICATION: Overloaded == operator to compare two Distance objects
    bool operator==(const Distance& other) const {
        return meters == other.meters;      // MODIFICATION: Returns true if both values are equal
    }

    // Displays the distance
    void display() const {
        std::cout << meters << " meters\n"; // Prints distance in meters
    }
};

int main() {                                // Main function starts

    Distance first(120);                    // Creates first object with 120 meters
    Distance second(120);                   // MODIFICATION: Changed 90 to 120 for equality testing

    // Displays the first distance
    std::cout << "First distance: ";
    first.display();

    // Displays the second distance
    std::cout << "Second distance: ";
    second.display();

    // MODIFICATION: Uses overloaded == operator to check equality
    if (first == second) {
        // MODIFICATION: Message displayed when both distances are equal
        std::cout << "Both distances are equal\n";
    }
    else {
        // MODIFICATION: Message displayed when distances are not equal
        std::cout << "Both distances are not equal\n";
    }

    return 0;                               // Ends the program successfully
}
