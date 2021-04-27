#pragma once

#include "Field.h"

template <class T>
std::ostream& operator<<(std::ostream& os, const Field<T>& dt) {
	os << dt.getLabel() << " = " << dt.getContent() << "		";
}

void Field<class T>::addValidator(Validator<T>* validator) {
	m_validators.push_back(validator);
}

//returns true if the input is valid
template<class T>
bool Field<T>::validate() const {
	for (int i = 0; i < m_validators.size(); i++)
		if (!m_validators[i]->validate(m_value));
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
int Field<T>::getContent() const {
	return *m_value;
}
