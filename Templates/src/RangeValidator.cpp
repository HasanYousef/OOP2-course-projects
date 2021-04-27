#pragma once

#include "RangeValidator.h"


template <class T>
bool RangeValidator<T>::validate(T* givenYear) const {
	return (givenYearn <= m_max && givenYear >= m_min);
}