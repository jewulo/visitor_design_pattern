#pragma once

#include <string>
#include "visitor.h"

/**
* The component interface declares an `accept` method that
* should take the base visitor as an argument.
*/
class Component {
public:
	virtual ~Component() {}
	virtual void Accept(Visitor* visitor) const = 0;
};

