#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Validator.h"

template <class T>
class Field {
public:
	Field(std::string label) : m_label(label) {};
	~Field() { delete m_value; }
	void addValidator(Validator<T>*);
	virtual void readInput();
	virtual bool validate() const;
private:
	std::string m_label;
	T* m_value = nullptr;
	std::vector<Validator<T>*> m_validators;
};

//==================================================

void Field<class T>::addValidator(Validator<T>* validator) {
	m_validators.push_back(validator);
}

template<class T>
void Field<T>::readInput() {
	std::cout << m_label << endl;
	std::cin >> m_value;
}

//returns true if the input is valid
template<class T>
bool Field<T>::validate() const {
	for(int i = 0; i < m_validators.size(); i++)
		if (!m_validators[i].validate(m_value));
			return false;
	return true;
}
