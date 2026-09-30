#include <iostream> // For input and output

// Abstract base class
class Shape {
public:
    // Pure virtual function
    virtual double area() const = 0;

    // Virtual destructor
    virtual ~Shape() = default;
};

// Rectangle inherits from Shape
class Rectangle : public Shape {
private:
    double length; // Stores length
    double width;  // Stores width

public:
    // Constructor to initialize length and width
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // Implements the pure virtual area() function
    double area() const override {
        return length * width; // Calculate rectangle area
    }
};

int main() {
    // Create Rectangle object
    Rectangle rectangle(8.0, 4.0);

    // Calculate and display area
    std::cout << "Rectangle Area: " << rectangle.area() << '\n';

    return 0; // End of program
}
