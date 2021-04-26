#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Validator.h"

class BaseField {
public:
	BaseField() {};
	virtual void readInput();
	virtual bool emptyInput() const;
};

template <class T>
class Field : public BaseField {
public:
	Field(std::string label) : m_label(label) {};
	~Field() { delete m_value; }
	void addValidator(BaseValidator*);
	virtual void readInput();
	virtual bool emptyInput() const;
private:
	std::string m_label;
	T* m_value = nullptr;
	BaseValidator* m_validator;
};

//==================================================

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
	return m_validators.validate(m_value);
}
