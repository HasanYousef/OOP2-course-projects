#pragma once

#include "Field.h"

template<class T>
void Field<T>::addValidator(const Validator* validator) {
	m_validators.push(validator);
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
