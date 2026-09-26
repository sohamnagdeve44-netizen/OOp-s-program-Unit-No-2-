#include <iostream>      // Used for input and output operations
#include <string>        // Used for string data type
#include <utility>       // Used for std::move()

// Base class
class Person {

protected:
    std::string name;    // Stores person's name

public:

    // Constructor of Person class
    explicit Person(std::string personName)
        : name(std::move(personName)) {}
};

// Student inherits from Person
class Student : public Person {

private:
    int rollNumber;      // Stores student's roll number

public:

    // Constructor of Student class
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)),  // Calls Person constructor
          rollNumber(roll) {}              // Initializes roll number

    // Function to display student details
    void display() const {

        // Displays student's name
        std::cout << "Name: " << name << '\n';

        // Displays student's roll number
        std::cout << "Roll Number: " << rollNumber << '\n';
    }
};

// Main function - program execution starts here
int main() {

    // Creates Student object with name Kiran and roll number 24
    Student student("Kiran", 24);

    // Calls display function
    student.display();

    // Ends the program successfully
    return 0;
}
