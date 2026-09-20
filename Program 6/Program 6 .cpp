#include <iostream>  // Used for input and output operations

// Base class for academic marks
class Academic {

protected:
    int academicMarks;  // Stores academic marks

public:

    // Constructor of Academic class
    explicit Academic(int marks)
        : academicMarks(marks) {}

    // Function to display academic marks
    void showAcademic() const {
        std::cout << "Academic Marks: "
                  << academicMarks << '\n';
    }
};

// Base class for sports marks
class Sports {

protected:
    int sportsMarks;  // Stores sports marks

public:

    // Constructor of Sports class
    explicit Sports(int marks)
        : sportsMarks(marks) {}

    // Function to display sports marks
    void showSports() const {
        std::cout << "Sports Marks: "
                  << sportsMarks << '\n';
    }
};

// Student inherits from both Academic and Sports
class Student : public Academic, public Sports {

public:

    // Constructor of Student class
    Student(int academic, int sports)
        : Academic(academic),    // Calls Academic constructor
          Sports(sports) {}       // Calls Sports constructor

    // Function to calculate and display total marks
    void showTotal() const {
        std::cout << "Total Marks: "
                  << academicMarks + sportsMarks << '\n';
    }
};

// Main function - program execution starts here
int main() {

    // Creates Student object with academic marks 80
    // and sports marks 15
    Student student(80, 15);

    // Displays academic marks
    student.showAcademic();

    // Displays sports marks
    student.showSports();

    // Displays total marks
    student.showTotal();

    // Ends the program successfully
    return 0;
}
