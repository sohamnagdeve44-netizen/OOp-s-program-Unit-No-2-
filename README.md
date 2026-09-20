Object-Oriented Programming with C++ – Unit II

 Student Details

- Student Name: Soham Nagdeve 
- PRN:125UAD1323
- Class/Division:S.Y Btech Div:B( AIDS)
- Course Name: Object-Oriented Programming with C++
- Course Code: ADPC303
- Programme: S.Y. B.Tech. Artificial Intelligence and Data Science
- Unit:II – Inheritance
- Language:C++


About This Repository

This repository contains C++ programs based on *Unit II: Inheritance* of the Object-Oriented Programming with C++ course.

The programs demonstrate fundamental and practical concepts of inheritance, including base and derived classes, protected members, different types of inheritance, constructor and destructor order, function overriding, abstract classes, virtual base classes, friend classes, and nested classes.

The repository also includes real-time application examples related to employee payroll, digital payments, and vehicle fleet management.



Unit II – Topics Covered

- Base and derived classes
- Protected members
- Relationship between base and derived classes
- Constructors and destructors in derived classes
- Function overriding
- Class hierarchies
- Public and private inheritance
- Types of inheritance
- Multiple-inheritance ambiguity
- Virtual base classes
- Abstract classes
- Friend classes
- Nested classes



List of Programs

A. Inheritance Practical Programs

 *1. Basic Single Inheritance* 
*Concept:* Base and derived classes

Demonstrates basic single inheritance using `Person` as the base class and `Student` as the derived class. It shows how a derived class can use accessible members of its base class.

 *2. Protected Member Access* 
Concept: Protected access specifier

Demonstrates how a derived class can directly access a protected data member inherited from its base class.

 *3. Public versus Private Inheritance* 
Concept: Inheritance modes

Demonstrates the difference between public and private inheritance and shows how the accessibility of inherited members changes.

 *4. Multilevel Inheritance* 
Concept: Three-level inheritance hierarchy

Demonstrates multilevel inheritance using the hierarchy:

`Person → Employee → Manager`

The program shows how properties and functions are inherited through multiple levels.

 *5. Hierarchical Inheritance* 
Concept: One base class with multiple derived classes

Demonstrates hierarchical inheritance using `Vehicle` as the common base class and `Car` and `Bike` as derived classes.

 *6. Multiple Inheritance* 
Concept: Two base classes

Demonstrates multiple inheritance where the `Student` class inherits from both `Academic` and `Sports` classes and calculates the total marks.

 *7. Resolving Multiple-Inheritance Ambiguity* 
Concept: Scope-resolution operator

Demonstrates how ambiguity caused by two base classes having functions with the same name can be resolved using the scope-resolution operator.

 *8. Constructor and Destructor Order* 
Concept:Object lifecycle

Demonstrates the order in which constructors and destructors are called in inheritance.

- Construction: Base → Derived
- Destruction: Derived → Base

 *9. Parameterized Base Constructor* 
Concept: Constructor initializer list

Demonstrates how a derived-class constructor initializes a parameterized constructor of its base class.

 *10. Function Overriding* 
Concept: `virtual` and `override`

Demonstrates function overriding using virtual functions, where derived classes provide their own implementation of a base-class function.

 *11. Abstract Class* 
Concept:Pure virtual function

Demonstrates the use of an abstract base class containing a pure virtual function. Derived classes implement the required functionality.

 *12. Virtual Base Class and Diamond Inheritance* 
Concept:Virtual inheritance

Demonstrates how a virtual base class prevents duplicate copies of a common base class in diamond inheritance.

 *13. Friend Class* 
Concept: Special access permission

Demonstrates how a friend class can access private members of another class when explicitly granted friendship.

 *14. Nested Class* 
Concept:Class inside another class

Demonstrates the creation and use of a nested class using `University` and its nested `Department` class.

 *15. Mini-Project – Vehicle Rental System* 
Concept: Integrated inheritance

Implements a vehicle rental application using a base `Vehicle` class and derived classes such as `Car` and `Bike`. The program calculates rental charges and demonstrates function overriding.

 *16. Mini-Project – Employee Payroll System* 
Concept: Abstract base class and function overriding

Implements an employee salary system using an abstract `Employee` class and derived classes for different employee types. Salary is calculated using overridden functions.



B. Unit II Real-Time Applications

The following programs are taken from the *Unit II section of the Unit-Wise Real-Time Applications and Live Examples* material.

 *17. Employee Payroll System* 
*Concepts:* Base and derived classes, protected members, hierarchical inheritance, constructor chaining, function overriding, and abstract base class.

Models full-time employees, part-time employees, and interns. All employee types share common information while implementing different salary-calculation methods.

 *18. Digital Payment Gateway* 
*Concepts:* Abstract class, hierarchical inheritance, pure virtual function, virtual destructor, and runtime polymorphism.

Demonstrates a payment gateway supporting different payment methods such as credit-card, UPI, and net-banking through a common interface.

 *19. Vehicle Fleet Management* 
*Concepts:* Base and derived classes, hierarchical inheritance, function overriding, virtual functions, and protected data.

Models a logistics fleet containing trucks, delivery vans, and delivery bikes. Common vehicle information is maintained in the base class while each derived class provides specialized information.

 *20. Mini-Project – Banking System with Account Hierarchy* 
Concept: Hierarchical inheritance and virtual functions

Implements a banking system using a base `Account` class and derived classes `SavingsAccount`, `CurrentAccount`, and `FixedDepositAccount`. The program includes account number, account holder name, balance, deposit and withdrawal operations, and interest calculation. Virtual functions are used to provide account-specific behavior.
