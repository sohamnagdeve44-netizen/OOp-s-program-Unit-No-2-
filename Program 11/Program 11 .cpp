#include <iostream>  // Includes input-output library

// Abstract base class
class Shape {

public:

    // Pure virtual function for calculating area
    virtual double area() const = 0;

    // Virtual destructor
    virtual ~Shape() = default;
};

// Rectangle class inherits from Shape
class Rectangle : public Shape {

private:
    double length;  // Stores length of rectangle
    double width;   // Stores width of rectangle

public:

    // Constructor to initialize length and width
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // Overrides the area function of Shape
    double area() const override {

        // Calculates and returns rectangle area
        return length * width;
    }
};

// Circle class inherits from Shape
class Circle : public Shape {

private:
    double radius;  // Stores radius of circle

public:

    // Constructor to initialize radius
    explicit Circle(double givenRadius)
        : radius(givenRadius) {}

    // Overrides the area function of Shape
    double area() const override {

        // Calculates and returns circle area
        return 3.141592653589793 * radius * radius;
    }
};

// Main function
int main() {

    // Creates a Rectangle object with length 5 and width 3
    Rectangle rectangle(5.0, 3.0);

    // Creates a Circle object with radius 2
    Circle circle(2.0);

    // Displays the area of the rectangle
    std::cout << "Rectangle Area: "
              << rectangle.area() << '\n';

    // Displays the area of the circle
    std::cout << "Circle Area: "
              << circle.area() << '\n';

    // Indicates successful program execution
    return 0;
}
