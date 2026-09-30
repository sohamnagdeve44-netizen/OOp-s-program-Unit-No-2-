#include <iostream> // For input and output

class Distance {
private:
    int meters; // Stores distance in meters

public:
    // Constructor to initialize distance
    explicit Distance(int value) : meters(value) {}

    // Overloads > operator to compare distances
    bool operator>(const Distance& other) const {
        return meters > other.meters; // Returns true if first is greater
    }

    // Displays the distance
    void display() const {
        std::cout << meters << " meters\n";
    }
};

int main() {
    // Create two distance objects
    Distance first(120);
    Distance second(90);

    // Display first distance
    std::cout << "First distance: ";
    first.display();

    // Display second distance
    std::cout << "Second distance: ";
    second.display();

    // Compare two distances using overloaded > operator
    if (first > second) {
        std::cout << "First distance is greater\n";
    } else {
        std::cout << "Second distance is greater or equal\n";
    }

    return 0; // End of program
}
