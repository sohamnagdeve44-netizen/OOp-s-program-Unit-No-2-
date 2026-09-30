#include <iostream> // For input and output

// Base class
class Shape {
public:
    // Virtual function to calculate area
    virtual double area() const {
        return 0.0;
    }

    // Virtual destructor
    virtual ~Shape() = default;
};

// Rectangle class inherits from Shape
class Rectangle : public Shape {
private:
    double length; // Stores length
    double width;  // Stores width

public:
    // Constructor to initialize length and width
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // Overrides area() for rectangle
    double area() const override {
        return length * width; // Calculate rectangle area
    }
};

// Circle class inherits from Shape
class Circle : public Shape {
private:
    double radius; // Stores radius

public:
    // Constructor to initialize radius
    explicit Circle(double givenRadius) : radius(givenRadius) {}

    // Overrides area() for circle
    double area() const override {
        constexpr double PI = 3.141592653589793;
        return PI * radius * radius; // Calculate circle area
    }
};

// Function to display area of any Shape
void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.area() << '\n';
}

int main() {
    // Create Rectangle object
    Rectangle rectangle(5.0, 3.0);

    // Create Circle object
    Circle circle(2.0);

    // Display rectangle area
    printArea(rectangle);

    // Display circle area
    printArea(circle);

    return 0; // End of program
}
