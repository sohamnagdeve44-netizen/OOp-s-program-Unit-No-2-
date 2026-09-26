#include <iostream>   // For input and output operations
#include <string>     // For using string
#include <utility>    // For std::move

// Abstract base class
class Employee {

protected:
    int employeeId;        // Stores employee ID
    std::string name;      // Stores employee name

public:
    // Constructor to initialize employee details
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}

    // Pure virtual function for salary calculation
    virtual double calculateSalary() const = 0;

    // Function to display basic employee details
    void displayBasicDetails() const {
        std::cout << "Employee ID: "
                  << employeeId << '\n';

        std::cout << "Name: "
                  << name << '\n';
    }

    // Virtual destructor
    virtual ~Employee() = default;
};

// PermanentEmployee inherits from Employee
class PermanentEmployee : public Employee {

private:
    double basicSalary;   // Stores basic salary
    double allowance;     // Stores additional allowance

public:
    // Constructor to initialize permanent employee
    PermanentEmployee(int id, std::string employeeName,
                      double basic, double extra)
        : Employee(id, std::move(employeeName)),
          basicSalary(basic),
          allowance(extra) {}

    // Override salary calculation
    double calculateSalary() const override {
        return basicSalary + allowance;
    }
};

// ContractEmployee inherits from Employee
class ContractEmployee : public Employee {

private:
    double hourlyRate;    // Stores hourly payment rate
    int hoursWorked;      // Stores total hours worked

public:
    // Constructor to initialize contract employee
    ContractEmployee(int id, std::string employeeName,
                     double rate, int hours)
        : Employee(id, std::move(employeeName)),
          hourlyRate(rate),
          hoursWorked(hours) {}

    // Override salary calculation
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

// Function to display employee pay slip
void displayPaySlip(const Employee& employee) {

    // Display employee ID and name
    employee.displayBasicDetails();

    // Display calculated salary
    employee.calculateSalary();

    std::cout << "Salary: "
              << employee.calculateSalary() << "\n\n";
}

int main() {

    // Create permanent employee object
    PermanentEmployee permanentEmployee(
        101, "Asha", 40000.0, 8000.0
    );

    // Create contract employee object
    ContractEmployee contractEmployee(
        102, "Vikas", 500.0, 80
    );

    // Display permanent employee pay slip
    displayPaySlip(permanentEmployee);

    // Display contract employee pay slip
    displayPaySlip(contractEmployee);

    return 0;   // End of program
}
