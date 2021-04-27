#pragma once

#include <iostream>
#include "Validator.h"
#include "Field.h"

class RoomValidator : public Validator<int> {
public:
	RoomValidator(std::string str, Field<BaseField>* f1,
		Field<BaseField>* f2, Field<BaseField>* f3) {
		m_label = str;
		m_field.push_back(f1);
		m_field.push_back(f2);
		m_field.push_back(f3);
	}
	std::string errorMassge() const;
private:
	std::string m_label;
	std::vector<Field<BaseField>*> m_field;
};