#pragma once

#include <iostream>
#include <vector>
#include "Field.h"

class Form {
public:
	void addField(BaseField*);
	void addValidator(BaseValidator*);
	void fillForm();
	bool validateForm();
private:
	std::vector<BaseField*> m_fields;
	std::vector<BaseValidator*> m_validators;
};

void Form::addField(BaseField* field) {
	m_fields.push_back(field);
}

void Form::addValidator(BaseValidator* validator) {
	m_validators.push_back(validator);
}