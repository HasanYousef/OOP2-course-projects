#pragma once

#include <iostream>
#include "Validator.h"

class NonNegativeValidator : public Validator<int> {
public:
	bool validate(int) const;
private:
};
