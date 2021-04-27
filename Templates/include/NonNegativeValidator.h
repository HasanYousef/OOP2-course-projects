#pragma once

#include <iostream>
#include "Validator.h"

// checks if the number is not negative
template <class T>
class NonNegativeValidator : public Validator<T>{
public:
	bool validate(T) const;
	std::string errorMassge() const;
private:
};

// retuns true if the number is not negative
template<class T>
inline bool NonNegativeValidator<T>::validate(T num) const
{
	return (num >= 0);
}

template<class T>
std::string NonNegativeValidator<T>::errorMassge() const {
	return "Can't be negative";
}
