#include <iostream>      // Used for input and output operations
#include <string>        // Used to work with string data
#include <utility>       // Used for std::move()

// Base class
class Person {

protected:
    std::string name;    // Stores the person's name

public:
    // Constructor of Person class
    explicit Person(std::string personName)
        : name(std::move(personName)) {}

    // Function to display the person's name
    void displayName() const {
        std::cout << "Name: " << name << '\n';
    }
};

// Student class inherits from Person
class Student : public Person {

private:
    int rollNumber;      // Stores student's roll number

public:
    // Constructor of Student class
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)),  // Calls Person constructor
          rollNumber(roll) {}              // Initializes roll number

    // Function to display student details
    void displayStudent() const {

        displayName();    // Calls inherited function from Person

        // Displays student's roll number
        std::cout << "Roll Number: " << rollNumber << '\n';
    }
};

// Main function - program execution starts here
int main() {

    // Creates Student object with name Amit and roll number 101
    Student student("Amit", 101);

    // Calls function to display student details
    student.displayStudent();

    // Indicates successful program execution
    return 0;
}
