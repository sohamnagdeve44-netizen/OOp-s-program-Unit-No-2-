#include <iostream>   // Provides input/output functions like cout
#include <string>     // Provides the string data type

using namespace std;  // Allows using standard library names without std::


// Abstract base class representing an Employee
class Employee {
protected:
    int empId;             // Stores employee ID
    string name;           // Stores employee name
    string department;     // Stores employee department

public:
    // Constructor to initialize employee details
    Employee(int id, string n, string dept)
        : empId(id), name(n), department(dept) {}

    // Displays basic employee information
    void displayBasicInfo() const {
        cout << "ID: " << empId
             << " | Name: " << name
             << " | Department: " << department;
    }

    // Pure virtual function for salary calculation
    // Makes Employee an abstract class
    virtual double calculateSalary() const = 0;

    // Virtual destructor for proper object destruction
    virtual ~Employee() = default;
};


// Full-Time Employee class derived from Employee
class FullTimeEmployee : public Employee {
private:
    double monthlySalary;  // Stores monthly salary

public:
    // Constructor to initialize full-time employee details
    FullTimeEmployee(int id, string n, string dept, double salary)
        : Employee(id, n, dept), monthlySalary(salary) {}

    // Overrides the salary calculation function
    double calculateSalary() const override {
        return monthlySalary;  // Returns monthly salary
    }

    // Displays full-time employee details
    void display() const {
        displayBasicInfo();  // Displays common employee information

        cout << " | Type: Full-Time | Salary: Rs. "
             << calculateSalary() << endl;  // Displays salary
    }
};


// Part-Time Employee class derived from Employee
class PartTimeEmployee : public Employee {
private:
    double hourlyRate;  // Stores payment per hour
    int hoursWorked;   // Stores total hours worked

public:
    // Constructor to initialize part-time employee details
    PartTimeEmployee(int id, string n, string dept, double rate, int hours)
        : Employee(id, n, dept),
          hourlyRate(rate),
          hoursWorked(hours) {}

    // Overrides the salary calculation function
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;  // Salary = Rate × Hours
    }

    // Displays part-time employee details
    void display() const {
        displayBasicInfo();  // Displays common employee information

        cout << " | Type: Part-Time | Salary: Rs. "
             << calculateSalary() << endl;  // Displays salary
    }
};


// Intern class derived from Employee
class Intern : public Employee {
private:
    double stipend;  // Stores intern's fixed stipend

public:
    // Constructor to initialize intern details
    Intern(int id, string n, string dept, double stipendAmount)
        : Employee(id, n, dept),
          stipend(stipendAmount) {}

    // Overrides the salary calculation function
    double calculateSalary() const override {
        return stipend;  // Returns fixed stipend
    }

    // Displays intern details
    void display() const {
        displayBasicInfo();  // Displays common employee information

        cout << " | Type: Intern | Stipend: Rs. "
             << calculateSalary() << endl;  // Displays stipend
    }
};


// Main function - program execution starts here
int main() {

    // Creates a Full-Time Employee object
    FullTimeEmployee ft(101, "Amit", "IT", 65000);

    // Creates a Part-Time Employee object
    PartTimeEmployee pt(102, "Sneha", "HR", 250, 120);

    // Creates an Intern object
    Intern in(103, "Rahul", "Marketing", 15000);

    // Displays the heading
    cout << "===== Employee Payroll =====" << endl;

    // Displays Full-Time Employee details and salary
    ft.display();

    // Displays Part-Time Employee details and salary
    pt.display();

    // Displays Intern details and stipend
    in.display();

    // Indicates successful program termination
    return 0;
}
