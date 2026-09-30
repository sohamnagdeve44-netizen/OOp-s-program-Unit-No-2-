#include <iostream>      // Provides cout and endl
#include <string>        // Provides string class
#include <cctype>        // Provides isalpha()

using namespace std;     // Allows us to use cout, string, etc.

// Class used to validate different types of data
class Validator {

public:

    // Function to validate marks
    // Marks should be between 0 and 100
    bool validate(int marks) const {
        return marks >= 0 && marks <= 100;
    }

    // Function to validate amount
    // Amount should be greater than 0 and up to 10,00,000
    bool validate(double amount) const {
        return amount > 0.0 && amount <= 1000000.0;
    }

    // Function to validate a person's name
    bool validate(const string& name) const {

        // Check if the name is empty
        if (name.empty()) {
            return false;
        }

        // Check every character in the name
        for (char ch : name) {

            // Character must be an alphabet or a space
            if (!isalpha(static_cast<unsigned char>(ch)) && ch != ' ') {
                return false;
            }
        }

        // Name is valid
        return true;
    }
};


int main() {

    // Create an object of Validator class
    Validator validator;

    // Display true/false instead of 1/0
    cout << boolalpha;

    // Validate marks = 88
    cout << "Marks 88 valid: "
         << validator.validate(88) << endl;

    // Validate marks = 120
    cout << "Marks 120 valid: "
         << validator.validate(120) << endl;

    // Validate amount = 4500.50
    cout << "Amount 4500.50 valid: "
         << validator.validate(4500.50) << endl;

    // Validate name containing only alphabets and space
    cout << "Name Priya Sharma valid: "
         << validator.validate(string("Priya Sharma")) << endl;

    // Validate name containing numbers
    cout << "Name Priya123 valid: "
         << validator.validate(string("Priya123")) << endl;
}
