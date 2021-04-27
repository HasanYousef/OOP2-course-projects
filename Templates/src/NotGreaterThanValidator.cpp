#pragma once

#include "NotGreaterThanValidator.h"


template<class T>
bool NotGreaterThanValidator<T>::validate(T* par1, T* par2) const
{
	return (par1 <= par2);
}