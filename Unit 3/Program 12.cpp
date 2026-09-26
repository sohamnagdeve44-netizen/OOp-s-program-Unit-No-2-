#include <iostream> // For input and output
#include <memory>   // For smart pointers
#include <vector>   // For vector container

// Abstract base class
class Shape {
public:
    // Pure virtual function to calculate area
    virtual double area() const = 0;

    // Pure virtual function to display shape name
    virtual void displayName() const = 0;

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

    // Calculates rectangle area
    double area() const override {
        return length * width;
    }

    // Displays shape name
    void displayName() const override {
        std::cout << "Rectangle";
    }
};

// Circle class inherits from Shape
class Circle : public Shape {
private:
    double radius; // Stores radius

public:
    // Constructor to initialize radius
    explicit Circle(double givenRadius) : radius(givenRadius) {}

    // Calculates circle area
    double area() const override {
        constexpr double PI = 3.141592653589793;
        return PI * radius * radius;
    }

    // Displays shape name
    void displayName() const override {
        std::cout << "Circle";
    }
};

int main() {
    // Create a vector to store Shape smart pointers
    std::vector<std::unique_ptr<Shape>> shapes;

    // Add Rectangle object to vector
    shapes.push_back(std::make_unique<Rectangle>(5.0, 3.0));

    // Add Circle object to vector
   
