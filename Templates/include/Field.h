#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Validator.h"

class BaseField {};

template <class T>
class Field : public BaseField {
public:
	Field(std::string label) : m_label(label) {};
	void addValidator(BaseValidator*);
	void readInput();
	bool emptyInput() const;
private:
	std::string m_label;
	T* m_value = nullptr;
	BaseValidator* m_validator;
};

void Field<class T>::addValidator(BaseValidator* validator) {
	m_validator = validator;
}

template<class T>
void Field<T>::readInput() {
	std::cout << m_label << endl;
	std::cin >> m_value;
}

//return false if the input is wrong or there no input
template<class T>
bool Field<T>::emptyInput() const {
	return m_validators[0].wrongInput(m_value);
}
