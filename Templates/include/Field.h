#pragma once

#include <iostream>
#include <string>
#include "BaseField.h"
#include "Validator.h"

template <class T>
class Field : public BaseField {
public:
	Field(std::string label) : m_label(label) {};
	virtual void printField() const;
	void addValidator(Validator<T>*);
	virtual void readInput();
	virtual bool validate() const;
	T getContent() const;
	std::string errorMassge() const;
	std::string getLabel() const;
private:
	std::string m_label = "";
	T m_value;
	Validator<T>* m_validator = nullptr;
	bool m_entered = false;
};

// prints the label and the given input
template <class T>
void Field<T>::printField() const {
	std::cout << m_label << " = " << m_value << "		";
}

// adding a valuation test
template <class T>
void Field<T>::addValidator(Validator<T>* validator) {
	m_validator = validator;
}

//returns true if the input is valid
template<class T>
bool Field<T>::validate() const {
	return (m_entered && m_validator->validate(m_value));
}

template<class T>
std::string Field<T>::errorMassge() const
{
	return m_validator->errorMassge();
}

// reading the input from the user for this field and mark
// that their is a value entered
template <class T>
void Field<T>::readInput() {
	std::cout << m_label << std::endl;
	std::cin >> m_value;
	m_entered = true;
}

// getting the title of the field
template<class T>
std::string Field<T>::getLabel() const {
	return m_label;
}

// returning the input theat tee user gave
template<class T>
T Field<T>::getContent() const {
	return m_value;
}
