#include <iostream>
using namespace std;

// Function to add two integers
int add(int first, int second) {
    return first + second;
}

// Function to add two double values
double add(double first, double second) {
    return first + second;
}

// Function to add three integers
int add(int first, int second, int third) {
    return first + second + third;
}

int main() {

    // Calls add() for two integers
    cout << "Sum of two integers: " << add(10, 20) << '\n';

    // Calls add() for two double values
    cout << "Sum of two doubles: " << add(2.5, 3.7) << '\n';

    // Calls add() for three integers
    cout << "Sum of three integers: " << add(10, 20, 30) << '\n';

    return 0;  // End of program
}
