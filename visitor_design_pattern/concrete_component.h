#pragma once

#include <string>
#include "component.h"

/**
* Each concrete Component must implement the `Accept` method
* in such a way that should take the base visitor interface
* as an argument
*/
class ConcreteComponentA : public Component {
	/**
	 * Note that we're calling `visitConcreteComponentA`, which matches the
	 * current class name. This way we let the visitor know the class of the
	 * component it works with.
	 */
public:
	void Accept(Visitor* visitor) const override {
		visitor->VisitConcreteComponentA(this);
	}
	/**
	 * Concrete Components may have special methods that don't exist in their base
	 * class or interface. The Visitor is still able to use these methods since
	 * it's aware of the component's concrete class.
	 */
	std::string ExclusiveMethodOfConcreteComponentA() const {
		return "A";
	}
};

class ConcreteComponentB : public Component {
	/**
	 * Note that we're calling `visitConcreteComponentA`, which matches the
	 * current class name. This way we let the visitor know the class of the
	 * component it works with.
	 */
public:
	void Accept(Visitor* visitor) const override {
		visitor->VisitConcreteComponentB(this);
	}
	/**
	 * Concrete Components may have special methods that don't exist in their base
	 * class or interface. The Visitor is still able to use these methods since
	 * it's aware of the component's concrete class.
	 */
	std::string SpecialMethodOfConcreteComponentB() const {
		return "B";
	}
};
