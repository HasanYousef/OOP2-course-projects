#pragma once

#include "NonNegativeValidator.h"

template<class T>
inline bool NonNegativeValidator<T>::validate(T* num) const
{
	return (num >= 0);
}

template<class T>
std::string NonNegativeValidator<T>::errorMassge() const {
	return "Can't be negative";
}

