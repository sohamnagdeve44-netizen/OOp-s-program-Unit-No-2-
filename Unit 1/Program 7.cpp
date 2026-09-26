#include <iostream>              // Includes input/output library
using namespace std;             // Allows use of cout without std::

class Student {
public:
    static int count;            // Static variable shared by all objects

    // Constructor
    Student() {
        count++;                 // Increases count whenever an object is created
    }
};

// Initializes the static variable
int Student::count = 0;

int main() {
    // Creates three Student objects
    Student s1, s2, s3;

    // Displays the total number of objects created
    cout << Student::count;

    return 0;                    // Ends the program successfully
}
