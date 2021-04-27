#pragma once

#include "Form.h"

void Form::fillForm() {
	for (int el = 0; el < m_fields.size(); el++) {
		if (!m_fields[el]->validate()) {
			m_fields[el]->readInput();
		}
	}
}

BaseField* Form::getField(int el) {
	return m_fields[el];
}

bool Form::validateForm() {
	for (int el = 0; el < m_fields.size(); el++) {
		if ( m_fields[el]->validate()) {
			return false;
		}
	}
	return true;
}

void Form::addField(BaseField* field) {
	m_fields.push_back(field);
}

void Form::addValidator(BaseValidator* validator) {
	m_validators.push_back(validator);
}

int Form::size() const {
	return m_fields.size();
}