#pragma once

#include <iostream>
#include <vector>
#include "Validator.h"
#include "Field.h"

class RoomValidator : public Validator<int> {
public:
	RoomValidator(std::string str, Field<int>* f1,
		Field<int>* f2, Field<int>* f3) {
		m_label = str;
		m_fields.push_back(f1);
		m_fields.push_back(f2);
		m_fields.push_back(f3);
	}
	void refillFields() const;
	virtual bool validate() const;
	std::string errorMassge() const;
private:
	std::string m_label;
	std::vector<Field<int>*> m_fields;
};