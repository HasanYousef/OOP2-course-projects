#pragma once

#include "Validator.h"

template<class T>
bool Validator<T>::wrongInput(T*) {
	return false;
}