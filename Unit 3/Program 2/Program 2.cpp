#include <iostream>  // Includes the input/output stream library.

// Function to calculate the area of a square.
int calculateArea(int side) {
    return side * side;  // Returns side × side.
}

// Function to calculate the area of a rectangle.
int calculateArea(int length, int width) {
    return length * width;  // Returns length × width.
}

// Function to calculate the area of a circle.
double calculateArea(double radius) {
    constexpr double PI = 3.141592653589793;  // Defines the value of PI.

    return PI * radius * radius;  // Returns π × radius × radius.
}


// Main function where program execution begins.
int main() {

    // Calls calculateArea(int) for calculating the area of a square.
    std::cout << "Square Area: " << calculateArea(5) << '\n';

    // Calls calculateArea(int, int) for calculating the area of a rectangle.
    std::cout << "Rectangle Area: " << calculateArea(6, 4) << '\n';

    // Calls calculateArea(double) for calculating the area of a circle.
    std::cout << "Circle Area: " << calculateArea(2.0) << '\n';

    return 0;  // Indicates successful program execution.
}

