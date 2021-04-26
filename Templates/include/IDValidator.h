#pragma once

#include <iostream>
#include <time.h>
#include "Validator.h"

template <class T>
class IDValidator : public Validator<T> {
	virtual bool validate(T*) const;
};

template <class T>
bool IDValidator<T>::validate(T* givenID) const {


	return true;
}