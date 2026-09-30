#include <iostream> // For input and output
#include <string>   // For string
#include <utility>  // For std::move

// Abstract base class
class Employee {
protected:
    int employeeId;       // Stores employee ID
    std::string name;     // Stores employee name

public:
    // Constructor to initialize employee details
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}

    // Pure virtual function to calculate salary
    virtual double calculateSalary() const = 0;

    // Displays basic employee details
    void displayBasicDetails() const {
        std::cout << "Employee ID: " << employeeId << '\n';
        std::cout << "Name: " << name << '\n';
    }

    // Virtual destructor
    virtual ~Employee() = default;
};

// Permanent employee class
class PermanentEmployee : public Employee {
private:
    double basicSalary; // Stores basic salary
    double allowance;   // Stores allowance

public:
    // Constructor to initialize permanent employee
    PermanentEmployee(int id, std::string employeeName,
                      double basic, double extra)
        : Employee(id, std::move(employeeName)),
          basicSalary(basic), allowance(extra) {}

    // Calculates salary for permanent employee
    double calculateSalary() const override {
        return basicSalary + allowance;
    }
};

// Contract employee class
class ContractEmployee : public Employee {
private:
    double hourlyRate; // Stores hourly payment rate
    int hoursWorked;   // Stores hours worked

public:
    // Constructor to initialize contract employee
    ContractEmployee(int id, std::string employeeName,
                     double rate, int hours)
        : Employee(id, std::move(employeeName)),
          hourlyRate(rate), hoursWorked(hours) {}

    // Calculates salary for contract employee
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

// Function to print employee payslip
void printPaySlip(const Employee& employee) {
    employee.displayBasicDetails(); // Display employee details
    std::cout << "Salary: Rs. "
              << employee.calculateSalary() << "\n\n";
}

int main() {
    // Create permanent employee
    PermanentEmployee permanentEmployee(
        101, "Asha", 40000.0, 8000.0);

    // Create contract employee
    ContractEmployee contractEmployee(
        102, "Vikas", 500.0, 80);

    // Display permanent employee payslip
    printPaySlip(permanentEmployee);

    // Display contract employee payslip
    printPaySlip(contractEmployee);

    return 0; // End of program
}
