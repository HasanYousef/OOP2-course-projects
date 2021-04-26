#pragma once

#include <iostream>
#include <string>

template <class T>
class Validator {
public:
	virtual Validator(int, int) const = 0;	//Constructor for validators like RangeValidator
	virtual bool validate(T*) const = 0;
};