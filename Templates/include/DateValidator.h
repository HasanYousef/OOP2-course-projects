#pragma once

#include <time.h>
#include "Validator.h"

template <class T>
class DateValidator : public Validator<T> {
	bool validate(T*) const;
	std::string errorMassge() const;
};

