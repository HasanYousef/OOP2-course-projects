#pragma once

#include <iostream>
#include <vector>
#include "Field.h"
#include "SumValidator.h"
#include "RoomValidator.h"

class Form {
public:
	void addField(BaseField*);
	void addValidator(SumValidator*);
	void addValidator(RoomValidator*);
	void fillForm();
	BaseField* getField(int);
	bool validateForm();
	int size() const;
private:
	std::vector<BaseField*> m_fields;
	SumValidator* m_sumValidator = nullptr;
	RoomValidator* m_roomValidator = nullptr;
};

std::ostream& operator<<(std::ostream& os, Form& dt) {
	/*os << "-------------------------------------------------------------------------\n";
	for (int el = 0; el < dt.size(); el++) {
		auto field = dt.getField(el);
		os << field << " ";
		if(!field->validate()) {
			os << field->errorMassge();
		}
		os << "\n-------------------------------------------------------------------------\n";
	}*/
	return os;
}

void Form::fillForm() {
	/*for (int el = 0; el < m_fields.size(); el++) {
		if (!m_fields[el]->validate()) {
			m_fields[el]->readInput();
		}
	}*/
}

BaseField* Form::getField(int el) {
	return m_fields[el];
}

bool Form::validateForm() {
	/*for (int el = 0; el < m_fields.size(); el++) {
		if (m_fields[el]->validate()) {
			return false;
		}
	}*/
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