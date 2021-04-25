#pragma once

#include <iostream>
#include <vector>
#include "Field.h"

class Form {
public:
	template <class T>
	void addField(Field<T>*);
	template <class T>
	void addValidator(Validator<T>*);
	void fillForm();
	bool validateForm();
private:
	std::vector<Field<>*> m_fields;
	std::vector<Validator<>*> m_validators;
};

template <class T>
void Form::addField(Field<T>* field) {
	m_fields.push_back(field);
}

template <class T>
void Form::addValidator(Validator<T>* validator) {
	m_validators.push_back(validator);
}