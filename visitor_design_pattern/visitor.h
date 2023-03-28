#pragma once

/**
* The Visitor Interface declares a set of visiting methods that correspond  to
* component classes. The signature of a visiting method allows the visitor to
* identify the exact class of the component that it is dealing with.
*/

class ConcreteComponentA;
class ConcreteComponentB;

class Visitor {
public:
    virtual void VisitConcreteComponentA(const ConcreteComponentA* element) const = 0;
    virtual void VisitConcreteComponentB(const ConcreteComponentB* element) const = 0;
};

