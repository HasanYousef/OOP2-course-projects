#pragma once

#include <iostream>
#include <string>
#include "Validator.h"

template <class T>
class Field {
public:
	Field(std::string label) m_label(label) : {};
	void addValidator(const Validator*);
private:
	std::string m_label;
	T* m_value = nullptr;
	Validator* m_validator = nullptr;
};