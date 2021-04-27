#pragma once

#include "Validator.h"

// checks if the number is in the range of max and min
template <class T>
class RangeValidator : public Validator<int> {
public:
	RangeValidator(int min, int max) : m_min(min), m_max(max) {};
	virtual bool validate(int) const;
private:
	int m_max = 0, m_min = 0;
};

// retuns true if the number is in the range
template <class T>
bool RangeValidator<T>::validate(int givenYear) const {
	return (givenYear <= m_max && givenYear >= m_min);
}