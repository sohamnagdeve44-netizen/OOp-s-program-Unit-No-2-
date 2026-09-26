#include <iostream>  // Used for input and output operations

// Base class
class Base {

public:

    // Public function of Base class
    void show() const {
        std::cout << "Base public function\n";  // Display message
    }
};

// Public inheritance from Base
class PublicDerived : public Base {
    // Base's public members remain public
};

// Private inheritance from Base
class PrivateDerived : private Base {

public:

    // Public function to access Base's show() function
    void callBaseShow() const {
        show();  // Calls show() inherited from Base
    }
};

int main() {

    // Creates object of PublicDerived
    PublicDerived publicObject;

    // show() is public because of public inheritance
    publicObject.show();

    // Creates object of PrivateDerived
    PrivateDerived privateObject;

    // Calls Base's show() through a public function
    privateObject.callBaseShow();

    // Cannot directly call show() because of private inheritance
    // privateObject.show();  // Error: show() is private through private inheritance

    // Indicates successful program execution
    return 0;
}
