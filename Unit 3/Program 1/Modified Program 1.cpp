#include <iostream>   // Provides input/output operations such as std::cout
#include <string>     // Provides the std::string data type

// Function to add two integer values
int add(int first, int second) {
    return first + second;   // Returns the sum of two integers
}

// Function to add two double values
double add(double first, double second) {
    return first + second;   // Returns the sum of two decimal values
}

// Function to add three integer values
int add(int first, int second, int third) {
    return first + second + third;   // Returns the sum of three integers
}

// MODIFICATION: Overloaded add() function to join two strings
std::string add(std::string first, std::string second) {
    return first + second;   // Joins the two strings and returns the result
}

// Main function: program execution starts here
int main() {

    // Calls add(int, int) because two integer values are passed
    std::cout << "Sum of two integers: " << add(10, 20) << '\n';

    // Calls add(double, double) because two decimal values are passed
    std::cout << "Sum of two doubles: " << add(2.5, 3.7) << '\n';

    // Calls add(int, int, int) because three integer values are passed
    std::cout << "Sum of three integers: " << add(10, 20, 30) << '\n';

    // MODIFICATION: Calls add(string, string) to join two strings
    std::cout << "Joined strings: " << add("Hello ", "World!") << '\n';

    // Indicates that the program executed successfully
    return 0;
}
