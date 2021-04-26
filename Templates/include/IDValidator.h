#pragma once

#include <iostream>
#include "Validator.h"

class IDValidator : public Validator<uint32_t> {
public:
	bool validate(class T*) const;
private:
};