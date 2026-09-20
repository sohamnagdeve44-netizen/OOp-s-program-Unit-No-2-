#include <iostream>      // Used for input and output
#include <string>        // Used for string data type
#include <utility>       // Used for std::move()

// Base class
class Employee {

protected:
    std::string name;    // Stores employee's name

public:

    // Constructor of Employee class
    explicit Employee(std::string employeeName)
        : name(std::move(employeeName)) {}
};

// Derived class inheriting from Employee
class Developer : public Employee {

private:
    std::string language;    // Stores programming language

public:

    // Constructor of Developer class
    Developer(std::string employeeName, std::string programmingLanguage)

        // Calls Employee constructor and initializes language
        : Employee(std::move(employeeName)),
          language(std::move(programmingLanguage)) {}

    // Function to display developer details
    void display() const {

        // Displays developer's name
        std::cout << "Developer: " << name << '\n';

        // Displays programming language
        std::cout << "Language: " << language << '\n';
    }
};

// Main function - program execution starts here
int main() {

    // Creates Developer object with name Neha and language C++
    Developer developer("Neha", "C++");

    // Calls display function
    developer.display();

    // Ends the program successfully
    return 0;
}
