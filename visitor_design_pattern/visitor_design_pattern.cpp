// visitor_design_pattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// https://refactoring.guru/design-patterns/visitor/cpp/example

#include <array>
#include <iostream>

//#include "component.h"
#include "concrete_component.h"
#include "concrete_visitor.h"

/**
* The Visitor Design Patternis a behavioral design pattern that lets
* you separate algorithms from the objects on which they operate.
*/


/**
 * The client code can run visitor operations over any set of elements without
 * figuring out their concrete classes. The accept operation directs a call to
 * the appropriate operation in the visitor object.
 */
void ClientCode(std::array<const Component*, 2> components, Visitor* visitor) {
    // ...
    for (const Component* comp : components) {
        comp->Accept(visitor);
    }
    // ...
}
int main()
{
    std::array<const Component*, 2> components{ new ConcreteComponentA, new ConcreteComponentB };

    std::cout << "The client code works with all visitors via the base Visitor interface:\n";
    ConcreteVisitor1* visitor1 = new ConcreteVisitor1;
    ClientCode(components, visitor1);

    std::cout << "\n";

    std::cout << "It allows the same client code to work with different types of visitors:\n";
    ConcreteVisitor2* visitor2 = new ConcreteVisitor2;
    ClientCode(components, visitor2);

    for (const Component* comp : components) {
        delete comp;
    }

    delete visitor1;
    delete visitor2;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
