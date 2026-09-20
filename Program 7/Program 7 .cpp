#include <iostream>  // Used for input and output operations

// Academic base class
class Academic {

public:

    // Function to display academic information
    void display() const {
        std::cout << "Academic information\n";
    }
};

// Sports base class
class Sports {

public:

    // Function to display sports information
    void display() const {
        std::cout << "Sports information\n";
    }
};

// Student inherits from both Academic and Sports
class Student : public Academic, public Sports {

public:

    // Function to display information from both base classes
    void displayAll() const {

        // Calls display() from Academic class
        Academic::display();

        // Calls display() from Sports class
        Sports::display();
    }
};

// Main function - program execution starts here
int main() {

    // Creates Student object
    Student student;

    // Calls Academic's display() using scope resolution
    student.Academic::display();

    // Calls Sports' display() using scope resolution
    student.Sports::display();

    // Calls function that displays both information
    student.displayAll();

    // Ends the program successfully
    return 0;
}
