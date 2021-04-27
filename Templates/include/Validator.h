#pragma once

#include <iostream>
#include <string>

template <class T>
class Validator {
public:
	virtual validator(T*, T*) const = 0;	//Constructor for validators like RangeValidator
	virtual bool validate(T*) const = 0;
	virtual std::string errorMassge() const;
};

template <class T>
std::string Validator<T>::errorMassge() const {
	return "The input you intered is not valid.";
}