#include <iostream>          // Includes input/output library
using namespace std;         // Allows use of cout without std::

int main() {
    int marks = 45;          // Stores the student's marks

    // Checks whether marks are 40 or above
    if (marks >= 40) {
        cout << "Pass";      // Displays Pass if condition is true
    } else {
        cout << "Fail";      // Displays Fail if condition is false
    }

    return 0;                // Ends the program successfully
}
