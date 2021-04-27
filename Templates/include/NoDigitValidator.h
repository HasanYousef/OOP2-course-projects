#pragma once

#include <iostream>
#include "Validator.h"

class NoDigitValidator : public Validator<std::string> {
public:
	bool validate(std::string str) const;
	virtual std::string errorMassge() const;
};
