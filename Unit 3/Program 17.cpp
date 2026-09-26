#include <iostream>      // Provides input/output functions like cout and endl
#include <memory>        // Provides smart pointers like unique_ptr and make_unique
#include <vector>        // Provides the vector container

using namespace std;     // Allows us to use cout, vector, etc. without std::

/*
    Shape is an abstract class.
    It provides common functions that every shape must implement.
*/
class Shape {
public:

    // Pure virtual function to calculate area
    virtual double area() const = 0;

    // Pure virtual function to draw the shape
    virtual void draw() const = 0;

    // Virtual destructor
    // It ensures proper destruction of derived class objects
    virtual ~Shape() = default;
};


/*
    Circle class inherits from Shape.
*/
class Circle : public Shape {

private:
    double radius;       // Stores the radius of the circle

public:

    // Constructor to initialize radius
    explicit Circle(double r) : radius(r) {}

    // Overrides the area() function of Shape
    double area() const override {
        return 3.14159265359 * radius * radius;
        // Formula: π × r × r
    }

    // Overrides the draw() function of Shape
    void draw() const override {
        cout << "Drawing circle with radius "
             << radius << endl;
    }
};


/*
    Rectangle class inherits from Shape.
*/
class Rectangle : public Shape {

private:
    double length;       // Stores length of rectangle
    double width;        // Stores width of rectangle

public:

    // Constructor to initialize length and width
    Rectangle(double l, double w)
        : length(l), width(w) {}

    // Calculates area of rectangle
    double area() const override {
        return length * width;
        // Formula: length × width
    }

    // Displays rectangle information
    void draw() const override {
        cout << "Drawing rectangle "
             << length << " x " << width << endl;
    }
};


/*
    Triangle class inherits from Shape.
*/
class Triangle : public Shape {

private:
    double base;         // Stores base of triangle
    double height;       // Stores height of triangle

public:

    // Constructor to initialize base and height
    Triangle(double b, double h)
        : base(b), height(h) {}

    // Calculates area of triangle
    double area() const override {
        return 0.5 * base * height;
        // Formula: 1/2 × base × height
    }

    // Displays triangle information
    void draw() const override {
        cout << "Drawing triangle with base "
             << base
             << " and height "
             << height << endl;
    }
};


int main() {

    /*
        Creates a vector that stores unique pointers
        to Shape objects.
    */
    vector<unique_ptr<Shape>> shapes;

    // Creates a Circle object and adds it to the vector
    shapes.push_back(make_unique<Circle>(5.0));

    // Creates a Rectangle object and adds it to the vector
    shapes.push_back(make_unique<Rectangle>(4.0, 6.0));

    // Creates a Triangle object and adds it to the vector
    shapes.push_back(make_unique<Triangle>(3.0, 8.0));


    // Displays the heading
    cout << "=== CAD Shape System ===" << endl;


    /*
        Range-based for loop.
        Each shape is accessed using a reference.
    */
    for (const auto& shape : shapes) {

        // Calls the appropriate draw() function
        shape->draw();

        // Calls the appropriate area() function
        cout << "Area: "
             << shape->area()
             << " square units"
             << endl;
    }

    // Program ends automatically.
}
