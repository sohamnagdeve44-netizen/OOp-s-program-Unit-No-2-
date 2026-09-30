#include <iostream>                                      // Include iostream for input/output

class Complex {                                          // Define Complex class
private:
    int real;                                            // Store real part
    int imaginary;                                       // Store imaginary part

public:
    // Constructor to initialize real and imaginary parts
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}    // Initialize data members

    // ⭐ MODIFICATION 1:
    // Changed binary '+' operator to binary '-' operator
    Complex operator-(const Complex& other) const {

        // ⭐ MODIFICATION 2:
        // Subtract real parts and imaginary parts
        return Complex(real - other.real,
                       imaginary - other.imaginary);
    }

    // Function to display complex number
    void display() const {
        std::cout << real;                               // Display real part

        if (imaginary >= 0) {                             // Check if imaginary part is positive
            std::cout << " + ";                          // Display + sign
        } else {
            std::cout << " - ";                          // Display - sign
        }

        // Display imaginary value without negative sign twice
        std::cout << (imaginary >= 0 ? imaginary : -imaginary)
                  << "i";                                // Display i
    }
};

int main() {                                              // Main function

    Complex first(2, 3);                                  // First complex number: 2 + 3i
    Complex second(4, 5);                                 // Second complex number: 4 + 5i

    // ⭐ MODIFICATION 3:
    // '-' operator is used instead of '+' operator
    Complex difference = first - second;

    std::cout << "First complex number: ";                // Display message
    first.display();                                     // Display first number

    std::cout << "\nSecond complex number: ";             // Display message
    second.display();                                    // Display second number

    // ⭐ MODIFICATION 4:
    // Changed output label from "Sum" to "Difference"
    std::cout << "\nDifference: ";
    difference.display();                                // Display subtraction result

    return 0;                                             // End program
}
