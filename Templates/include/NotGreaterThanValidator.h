#pragma once

#include <iostream>
#include "Validator.h"

template <class T>
class NotGreaterThanValidator : public Validator<T> {
public:
	bool validate(T*, T*) const;
private:
};

