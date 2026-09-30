#include <iostream>                         // Includes input/output library

// Function 1: Calculate area of a square
int calculateArea(int side) {               // Takes one integer argument
    return side * side;                     // Returns square area
}

// Function 2: Calculate area of a rectangle
int calculateArea(int length, int width) {  // Takes two integer arguments
    return length * width;                  // Returns rectangle area
}

// Function 3: Calculate area of a circle
double calculateArea(double radius) {       // Takes one double argument
    constexpr double PI = 3.141592653589793; // Constant value of PI
    return PI * radius * radius;            // Returns circle area
}

// Function 4: Calculate area of a triangle
// ******** NEW / MODIFIED FUNCTION ********
double calculateArea(double base, double height) { // Takes base and height as double
    return 0.5 * base * height;             // Formula: 1/2 × base × height
}

int main() {                                // Main function starts

    // Calls calculateArea(int side) for square
    std::cout << "Square Area: "
              << calculateArea(5) << '\n';

    // Calls calculateArea(int length, int width) for rectangle
    std::cout << "Rectangle Area: "
              << calculateArea(6, 4) << '\n';

    // Calls calculateArea(double radius) for circle
    std::cout << "Circle Area: "
              << calculateArea(2.0) << '\n';

    // ******** NEW / MODIFIED LINE ********
    // Calls calculateArea(double base, double height) for triangle
    std::cout << "Triangle Area: "
              << calculateArea(10.0, 5.0) << '\n';

    return 0;                               // Indicates successful execution
}
