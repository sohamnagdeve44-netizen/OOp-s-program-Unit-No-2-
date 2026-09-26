#include <iostream>              // Includes input/output library
using namespace std;             // Allows use of cout without std::

class Test {
private:
    int value;                   // Private data member

public:
    // Parameterized constructor
    Test(int v) {
        value = v;               // Assigns v to value
    }

    // Inline function to return the value
    inline int getValue() {
        return value;            // Returns the private value
    }

    // Friend function declaration
    friend void show(Test t);
};

// Definition of friend function
void show(Test t) {
    cout << t.value;             // Friend function can access private data
}

int main() {
    Test obj(50);                // Creates object and initializes value to 50

    // Calls inline function and displays the value
    cout << obj.getValue() << endl;

    show(obj);                   // Calls friend function to display the value

    return 0;                    // Ends the program successfully
}
