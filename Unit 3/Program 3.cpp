#include <iostream> // For input and output

class Number {
private:
    int value; // Stores the number

public:
    // Constructor to initialize value
    explicit Number(int givenValue) : value(givenValue) {}

    // Overloads unary minus (-) operator
    Number operator-() const {
        return Number(-value); // Returns negative of value
    }

    // Displays the value
    void display() const {
        std::cout << value << '\n';
    }
};

int main() {
    Number first(25); // Create object with value 25

    Number second = -first; // Apply unary minus operator

    // Display original value
    std::cout << "Original value: ";
    first.display();

    // Display negated value
    std::cout << "Negated value: ";
    second.display();

    return 0; // End of program
}
