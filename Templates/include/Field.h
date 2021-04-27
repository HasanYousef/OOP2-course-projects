#pragma once

#include <iostream>
#include <string>
#include <vector>
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

template <class T>
void Field<T>::printField() const {
	std::cout << m_label << " = " << m_value << "		";
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Field<T>& dt) {
	os << dt.getLabel() << " = " << dt.getContent() << "		";
}

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

template <class T>
void Field<T>::readInput() {
	std::cout << m_label << std::endl;
	std::cin >> m_value;
	m_entered = true;
}

template<class T>
std::string Field<T>::getLabel() const {
	return m_label;
}

template<class T>
T Field<T>::getContent() const {
	return m_value;
}
