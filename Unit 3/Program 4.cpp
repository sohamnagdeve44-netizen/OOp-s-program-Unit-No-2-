#include <iostream> // For input and output

class Counter {
private:
    int value; // Stores the counter value

public:
    // Constructor to initialize the counter
    explicit Counter(int initialValue = 0) : value(initialValue) {}

    // Overloads prefix ++ operator
    Counter& operator++() {
        ++value;        // Increase value first
        return *this;   // Return updated object
    }

    // Overloads postfix ++ operator
    Counter operator++(int) {
        Counter old = *this; // Store old value
        ++value;             // Increase value
        return old;          // Return old value
    }

    // Displays the counter value
    void display() const {
        std::cout << value << '\n';
    }
};

int main() {
    Counter counter(5); // Create counter with value 5

    // Prefix increment: value increases before use
    std::cout << "After prefix increment: ";
    ++counter;
    counter.display();

    // Postfix increment: old value is returned first
    std::cout << "Value returned by postfix increment: ";
    Counter oldValue = counter++;
    oldValue.display();

    // Display updated counter value
    std::cout << "Counter after postfix increment: ";
    counter.display();

    return 0; // End of program
}
