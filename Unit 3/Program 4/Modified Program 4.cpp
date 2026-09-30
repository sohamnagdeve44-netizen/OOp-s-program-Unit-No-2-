#include <iostream>                         // Includes input/output library

class Counter {                             // Defines the Counter class
private:
    int value;                              // Stores the counter value

public:
    // Constructor initializes the counter with the given value
    explicit Counter(int initialValue = 0) : value(initialValue) {}

    // ---------------- PREFIX INCREMENT ----------------
    Counter& operator++() {                 // Prefix increment operator (++counter)
        ++value;                            // Increases value by 1
        return *this;                       // Returns the updated object
    }

    // ---------------- POSTFIX INCREMENT ----------------
    Counter operator++(int) {               // Postfix increment operator (counter++)
        Counter old = *this;                // Stores the old value
        ++value;                            // Increases value by 1
        return old;                         // Returns the old value
    }

    // ================= MODIFICATION ====================

    // ---------------- PREFIX DECREMENT ----------------
    Counter& operator--() {                 // MODIFICATION: Prefix decrement (--counter)
        --value;                            // MODIFICATION: Decreases value by 1
        return *this;                       // MODIFICATION: Returns the updated object
    }

    // ---------------- POSTFIX DECREMENT ----------------
    Counter operator--(int) {                // MODIFICATION: Postfix decrement (counter--)
        Counter old = *this;                // MODIFICATION: Stores the old value
        --value;                            // MODIFICATION: Decreases value by 1
        return old;                         // MODIFICATION: Returns the old value
    }

    // ---------------- DISPLAY FUNCTION ----------------
    void display() const {                  // Displays the current counter value
        std::cout << value << '\n';         // Prints the value
    }
};

int main() {                                // Main function starts
    Counter counter(5);                     // Creates Counter object with value 5

    // ---------------- PREFIX INCREMENT ----------------
    std::cout << "After prefix increment: "; // Prints message
    ++counter;                              // Calls prefix increment operator
    counter.display();                      // Displays 6

    // ---------------- POSTFIX INCREMENT ----------------
    std::cout << "Value returned by postfix increment: "; // Prints message
    Counter oldValue = counter++;           // Stores old value (6), counter becomes 7
    oldValue.display();                     // Displays returned old value 6

    std::cout << "Counter after postfix increment: "; // Prints message
    counter.display();                      // Displays current value 7

    // ================= MODIFICATION ====================

    // ---------------- PREFIX DECREMENT ----------------
    std::cout << "After prefix decrement: "; // MODIFICATION: Prints message
    --counter;                              // MODIFICATION: Calls prefix decrement (7 → 6)
    counter.display();                      // MODIFICATION: Displays 6

    // ---------------- POSTFIX DECREMENT ----------------
    std::cout << "Value returned by postfix decrement: "; // MODIFICATION
    Counter oldDecrementValue = counter--;   // MODIFICATION: Stores 6, counter becomes 5
    oldDecrementValue.display();             // MODIFICATION: Displays returned old value 6

    std::cout << "Counter after postfix decrement: "; // MODIFICATION
    counter.display();                      // MODIFICATION: Displays current value 5

    return 0;                               // Ends the program
}
