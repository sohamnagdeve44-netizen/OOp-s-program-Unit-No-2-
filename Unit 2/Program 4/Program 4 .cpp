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

    // Function to display person's name
    void showPerson() const {
        std::cout << "Name: " << name << '\n';
    }
};

// Employee inherits from Person
class Employee : public Person {

protected:
    int employeeId;      // Stores employee ID

public:

    // Constructor of Employee class
    Employee(std::string employeeName, int id)
        : Person(std::move(employeeName)),  // Calls Person constructor
          employeeId(id) {}                 // Initializes employee ID

    // Function to display employee ID
    void showEmployee() const {
        std::cout << "Employee ID: " << employeeId << '\n';
    }
};

// Manager inherits from Employee
class Manager : public Employee {

private:
    int teamSize;        // Stores number of team members

public:

    // Constructor of Manager class
    Manager(std::string managerName, int id, int size)
        : Employee(std::move(managerName), id), // Calls Employee constructor
          teamSize(size) {}                     // Initializes team size

    // Function to display manager details
    void showManager() const {

        showPerson();     // Calls function inherited from Person
        showEmployee();   // Calls function inherited from Employee

        // Displays team size
        std::cout << "Team Size: " << teamSize << '\n';
    }
};

// Main function - program execution starts here
int main() {

    // Creates Manager object with name, ID and team size
    Manager manager("Ravi", 501, 8);

    // Calls function to display manager details
    manager.showManager();

    // Ends the program successfully
    return 0;
}
