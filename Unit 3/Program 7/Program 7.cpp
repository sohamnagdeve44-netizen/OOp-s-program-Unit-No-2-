#include <iostream> // For input and output

class Complex {
private:
    int real;       // Stores real part
    int imaginary;  // Stores imaginary part

public:
    // Constructor to initialize complex number
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}

    // Declares + operator as a friend function
    friend Complex operator+(int value, const Complex& number);

    // Displays the complex number
    void display() const {
        std::cout << real;

        // Display + or - based on imaginary value
        if (imaginary >= 0) {
            std::cout << " + ";
        } else {
            std::cout << " - ";
        }

        // Display imaginary value
        std::cout << (imaginary >= 0 ? imaginary : -imaginary) << "i\n";
    }
};

// Defines the overloaded + operator
Complex operator+(int value, const Complex& number) {
    // Add integer to real part
    return Complex(value + number.real, number.imaginary);
}

int main() {
    // Create a complex number
    Complex number(2, 3);

    // Add integer 10 to the complex number
    Complex result = 10 + number;

    // Display the result
    std::cout << "Result: ";
    result.display();

    return 0; // End of program
}
