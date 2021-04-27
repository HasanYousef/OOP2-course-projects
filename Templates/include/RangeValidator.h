#pragma once

#include "Validator.h"

template <class T>
class RangeValidator : public Validator<T> {
public:
	RangeValidator(int max, int min) : m_max(max), m_min(min) {};
	virtual bool validate(T*) const;
private:
	int m_max = 0, m_min = 0;
};