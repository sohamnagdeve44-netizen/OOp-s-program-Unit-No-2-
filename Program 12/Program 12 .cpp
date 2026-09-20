#include <iostream>      // For input and output operations
#include <string>        // For using string data type
#include <utility>       // For std::move

// Base class
class Person {

protected:
    std::string name;    // Stores the person's name

public:
    // Constructor to initialize the name
    explicit Person(std::string personName)
        : name(std::move(personName)) {}

    // Function to display the person's name
    void displayName() const {
        std::cout << "Name: " << name << '\n';
    }
};

// Student virtually inherits from Person
class Student : virtual public Person {

public:
    // Student constructor
    Student() : Person("Unknown") {}
};

// Employee virtually inherits from Person
class Employee : virtual public Person {

public:
    // Employee constructor
    Employee() : Person("Unknown") {}
};

// TeachingAssistant inherits from both Student and Employee
class TeachingAssistant : public Student, public Employee {

public:
    // Constructor to initialize TeachingAssistant
    explicit TeachingAssistant(std::string assistantName)

        // Directly initialize the virtual base class Person
        : Person(std::move(assistantName)),

          // Call Student constructor
          Student(),

          // Call Employee constructor
          Employee() {}
};

int main() {

    // Create TeachingAssistant object with name "Riya"
    TeachingAssistant assistant("Riya");

    // Display the name
    assistant.displayName();

    return 0;              // End of program
}
