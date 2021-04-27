#pragma once

#include <iostream>
#include <time.h>
#include "Validator.h"

class IDValidator : public Validator<uint32_t> {
	virtual bool validate(uint32_t) const;
	std::string errorMassge() const;
};