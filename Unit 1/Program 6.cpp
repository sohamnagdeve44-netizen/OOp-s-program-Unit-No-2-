#include <iostream>              // Includes input/output library
using namespace std;             // Allows use of cout without std::

class Demo {
public:

    // Constructor is called automatically when object is created
    Demo() {
        cout << "Constructor called\n";
    }

    // Destructor is called automatically when object is destroyed
    ~Demo() {
        cout << "Destructor called\n";
    }
};

int main() {
    Demo d;                      // Creates object, so constructor is called

    return 0;                    // Program ends, so destructor is called
}
