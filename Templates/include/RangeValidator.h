#pragma once

#include "Validator.h"

template <class T>
class RangeValidator : public Validator<int> {
public:
	RangeValidator(int max, int min) : m_max(max), m_min(min) {};
	virtual bool validate(int) const;
private:
	int m_max = 0, m_min = 0;
};

template <class T>
bool RangeValidator<T>::validate(int givenYear) const {
	return (givenYear <= m_max && givenYear >= m_min);
}