#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Validator.h"

template <class T = char>
class Field {
public:
	Field(std::string label) : m_label(label) {};
	void addValidator(const Validator*);
	void readInput();
	bool emptyInput() const;
private:
	std::string m_label;
	T* m_value = nullptr;
	std::vector<Validator*> m_validators;
};