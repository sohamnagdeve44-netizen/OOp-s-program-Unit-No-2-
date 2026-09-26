#include <iostream>              // Includes input/output library
using namespace std;             // Allows use of cout without std::

int add(int, int);               // Function declaration (prototype)

int main() {
    int a = 10, b = 20;          // Declares and initializes two integers

    // Calls add() function and displays the returned sum
    cout << "Sum = " << add(a, b) << endl;

    return 0;                    // Ends the program successfully
}

// Function definition to add two numbers
int add(int x, int y) {
    return x + y;                // Returns the sum of x and y
}
