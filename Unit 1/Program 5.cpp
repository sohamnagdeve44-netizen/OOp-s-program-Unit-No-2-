#include <iostream>              // Includes input/output library
using namespace std;             // Allows use of cout without std::

class Student {
public:
    string name;                 // Stores student's name
    int age;                     // Stores student's age

    // Function to display student details
    void show() {
        cout << name << " " << age << endl;
    }
};

int main() {
    Student s1;                  // Creates an object of Student class

    s1.name = "Amit";            // Assigns name to the object
    s1.age = 20;                 // Assigns age to the object

    s1.show();                   // Calls show() to display details

    return 0;                    // Ends the program successfully
}
