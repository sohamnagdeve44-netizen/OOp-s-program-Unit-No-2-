#include <iostream>          // Provides input/output functions like cout and endl
using namespace std;         // Allows us to use cout without writing std::cout

// Class representing a complex number
class Complex {

private:
    double real;             // Stores the real part
    double imag;             // Stores the imaginary part

public:

    // Constructor to initialize real and imaginary parts
    // Default values are 0.0 if no values are provided
    Complex(double r = 0.0, double i = 0.0)
        : real(r), imag(i) {}

    // Overloading + operator
    // Adds two complex numbers
    Complex operator+(const Complex& other) const {

        // Add real parts and imaginary parts separately
        return Complex(real + other.real,
                       imag + other.imag);
    }

    // Overloading - operator
    // Subtracts two complex numbers
    Complex operator-(const Complex& other) const {

        // Subtract real parts and imaginary parts separately
        return Complex(real - other.real,
                       imag - other.imag);
    }

    // Overloading * operator
    // Multiplies two complex numbers
    Complex operator*(const Complex& other) const {

        /*
           Formula:
           (a + bi)(c + di)
           = (ac - bd) + (ad + bc)i
        */

        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    // Overloading == operator
    // Checks whether two complex numbers are equal
    bool operator==(const Complex& other) const {

        // Both real and imaginary parts must be equal
        return real == other.real &&
               imag == other.imag;
    }

    // Function to display the complex number
    void display() const {

        // Prints real part + imaginary part
        cout << real << " + "
             <<
