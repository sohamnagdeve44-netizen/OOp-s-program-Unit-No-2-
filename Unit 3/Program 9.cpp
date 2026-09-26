#include <iostream> // For input and output

// Base class
class Animal {
public:
    // Virtual function for sound
    virtual void sound() const {
        std::cout << "Animal makes a sound\n";
    }

    // Virtual destructor
    virtual ~Animal() = default;
};

// Derived class Dog
class Dog : public Animal {
public:
    // Overrides the sound function
    void sound() const override {
        std::cout << "Dog barks\n";
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    // Overrides the sound function
    void sound() const override {
        std::cout << "Cat meows\n";
    }
};

int main() {
    Dog dog; // Create Dog object
    Cat cat; // Create Cat object

    // Base pointer points to Dog object
    Animal* animal = &dog;
    animal->sound(); // Calls Dog's sound()

    // Base pointer now points to Cat object
    animal = &cat;
    animal->sound(); // Calls Cat's sound()

    return 0; // End of program
}
