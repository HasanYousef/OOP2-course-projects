#pragma once

#include <iostream>
#include "Validator.h"

template <class T>
class NonNegativeValidator : public Validator<T>{
public:
	bool validate(T*) const;
	std::string errorMassge() const;
private:
};

