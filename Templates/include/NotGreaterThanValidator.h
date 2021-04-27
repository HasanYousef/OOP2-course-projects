#pragma once

#include <iostream>
#include "Validator.h"

//checks if the number is smaller or equals to the max
template <class T>
class NotGreaterThanValidator : public Validator<T> {
public:
	NotGreaterThanValidator(int max) : m_max(max) {};
	bool validate(T) const;
private:
	int m_max;
};

// retuns true if the number is bigger than the max
template<class T>
bool NotGreaterThanValidator<T>::validate(T num) const {
	return (num <= m_max);
}