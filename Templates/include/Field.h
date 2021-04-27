#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Validator.h"

class BaseField {
public:
	virtual void readInput() {};
	virtual bool validate() const { return false; };
	virtual std::string errorMassge() const { return ""; };
};

template <class T>
class Field : public BaseField {
public:
	Field(std::string label) : m_label(label) {};
	void addValidator(Validator<T>*);
	void readInput();
	virtual bool validate() const;
	T getContent() const;
	std::string errorMassge() const;
	std::string getLabel() const;
private:
	std::string m_label;
	T m_value;
	std::vector<Validator<T>*> m_validators;
};

template<class T>
void Field<T>::readInput() {
	std::cout << m_label << std::endl;
	std::cin >> m_value;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Field<T>& dt) {
	os << dt.getLabel() << " = " << dt.getContent() << "		";
}

template <class T>
void Field<T>::addValidator(Validator<T>* validator) {
	m_validators.push_back(validator);
}

//returns true if the input is valid
template<class T>
bool Field<T>::validate() const {
	for (int i = 0; i < m_validators.size(); i++)
		if (!m_validators[i]->validate(m_value))
			return false;
	return true;
}

template<class T>
std::string Field<T>::errorMassge() const
{
	for (int i = 0; i < m_validators.size(); i++)
		m_validators[i]->errorMassge();
}

template<class T>
std::string Field<T>::getLabel() const {
	return m_label;
}

template<class T>
T Field<T>::getContent() const {
	return m_value;
}
