#include <iostream>   // For input and output
#include <string>     // For using string
#include <utility>    // For std::move

// Outer class
class University {

public:

    // Nested class inside University
    class Department {

    private:
        std::string name;   // Stores department name

    public:
        // Constructor to initialize department name
        explicit Department(std::string departmentName)
            : name(std::move(departmentName)) {}

        // Function to display department name
        void display() const {
            std::cout << "Department: " << name << '\n';
        }
    };
};

int main() {

    // Create Department object using scope resolution operator
    University::Department department(
        "Artificial Intelligence and Data Science"
    );

    // Display the department name
    department.display();

    return 0;   // End of program
}
