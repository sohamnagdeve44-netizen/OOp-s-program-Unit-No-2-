#include <iostream>          // Includes input/output library
using namespace std;         // Allows use of cout without std::

int main() {
    // Creates an array of 5 marks
    int marks[5] = {78, 82, 91, 67, 88};

    // Loop through all array elements
    for (int i = 0; i < 5; i++) {
        cout << marks[i] << " ";   // Prints each mark
    }

    return 0;                // Ends the program successfully
}
