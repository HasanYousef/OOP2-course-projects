#pragma once

#include <iostream>
#include <vector>
#include "Field.h"

class Form {
public:
	void addField(BaseField*);
	template <class T>
	void addValidator(const Validator*);
	void fillForm();
	bool validateForm();
private:
	std::vector<BaseField*> m_fields;
	std::vector<Validator*> m_validators;
};

void Form::addField(BaseField* field) {
	m_fields.push_back(field);
}

template <class T>
void Form::addValidator(const Validator* validator) {
	m_validators.push_back(validator);
}