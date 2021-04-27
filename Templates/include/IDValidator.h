#pragma once

#include <iostream>
#include <time.h>
#include "Validator.h"

// checks if the control digit is the right one in the id
class IDValidator : public Validator<uint32_t> {
	virtual bool validate(uint32_t) const;
	std::string errorMassge() const;
};

