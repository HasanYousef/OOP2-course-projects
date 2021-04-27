#pragma once

#include "Form.h"

// printing the form with the error messages if needed 
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

// looping through the fields so the user can fill them
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

// validates the form and keep asking the user to reqnser the issued fields
bool Form::validateForm() {
	for (int el = 0; el < m_fields.size(); el++) {
		if (!m_fields[el]->validate()) {
			return false;
		}
	}
	// making sure that the num of peopls is valid
	while (!m_sumValidator->validate())
		m_sumValidator->refillFields();
	// making sure that the num of peopls is valid and less than the rooms capacity
	while (!m_sumValidator->validate() || !m_roomValidator->validate()) {
		m_roomValidator->refillFields();
		m_sumValidator->refillFields();
	}
	std::cout << this;
	return true;
}

// inserting a new field to the form
void Form::addField(BaseField* field) {
	m_fields.push_back(field);
}

// inserting a new validator to the form
void Form::addValidator(SumValidator* validator) {
	m_sumValidator = validator;
}

void Form::addValidator(RoomValidator* validator) {
	m_roomValidator = validator;
}

// retuning the number of fields in the form
int Form::size() const {
	return m_fields.size();
}