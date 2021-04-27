#pragma once

#include <iostream>
#include "Validator.h"

template <class T>
class NotGreaterThanValidator : public Validator<T> {
public:
	bool validate(T*, T*) const;
private:
};

template<class T>
bool NotGreaterThanValidator<T>::validate(T* par1, T* par2) const
{
	return (par1 <= par2);
}