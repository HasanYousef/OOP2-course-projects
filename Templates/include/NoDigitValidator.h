#pragma once

#include <iostream>
#include "Validator.h"

//checks if the string doesn't have any digit
class NoDigitValidator : public Validator<std::string> {
public:
	bool validate(std::string str) const;
	virtual std::string errorMassge() const;
};
