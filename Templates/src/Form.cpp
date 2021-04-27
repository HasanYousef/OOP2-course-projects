#pragma once

#include "Form.h"

std::ostream& operator<<(std::ostream& os, Form& dt) {
	os << "-------------------------------------------------------------------------\n";
	for (int el = 0; el < dt.size(); el++) {
		auto field = dt.getField(el);
		field->printField();
		if(!field->validate()) {
			os << field->errorMassge();
		}
		os << "\n-------------------------------------------------------------------------\n";
	}
	return os;
}

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
		if (!m_fields[el]->validate()) {
			return false;
		}
	}
	while (!m_sumValidator->validate())
		m_sumValidator->refillFields();
	while (!m_sumValidator->validate() || !m_roomValidator->validate()) {
		m_roomValidator->refillFields();
		m_sumValidator->refillFields();
	}
	std::cout << this;
	return true;
}

void Form::addField(BaseField* field) {
	m_fields.push_back(field);
}

void Form::addValidator(SumValidator* validator) {
	m_sumValidator = validator;
}

void Form::addValidator(RoomValidator* validator) {
	m_roomValidator = validator;
}
int Form::size() const {
	return m_fields.size();
}