#include <iostream> // For input and output

class Complex {
private:
    int real;       // Stores real part
    int imaginary;  // Stores imaginary part

public:
    // Constructor to initialize real and imaginary parts
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {}

    // Overloads + operator for adding complex numbers
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real,
                       imaginary + other.imaginary);
    }

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

int main() {
    // Create two complex number objects
    Complex first(2, 3);
    Complex second(4, 5);

    // Add two complex numbers using overloaded + operator
    Complex sum = first + second;

    // Display first complex number
    std::cout << "First complex number: ";
    first.display();

    // Display second complex number
    std::cout << "Second complex number: ";
    second.display();

    // Display the sum
    std::cout << "Sum: ";
    sum.display();

    return 0; // End of program
}
