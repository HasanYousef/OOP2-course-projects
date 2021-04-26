#pragma once

#include <iostream>
#include "Validator.h"

template <class T>
class RangeValidator : public Validator {
public:
	bool validate(class T*) const;
private:
};

