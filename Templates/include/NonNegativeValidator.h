#pragma once

#include <iostream>
#include "Validator.h"

template <class T>
class NonNegativeValidator : public Validator<T>{
public:
	bool validate(T) const;
	std::string errorMassge() const;
private:
};

template<class T>
inline bool NonNegativeValidator<T>::validate(T num) const
{
	return (num >= 0);
}

template<class T>
std::string NonNegativeValidator<T>::errorMassge() const {
	return "Can't be negative";
}
