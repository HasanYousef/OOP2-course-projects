#pragma once

#include <iostream>
#include "Validator.h"
#include "Field.h"

class RoomValidator : public Validator<int> {
public:
	RoomValidator(std::string str, BaseField* f1,
		BaseField* f2, BaseField* f3) {
		m_label = str;
		m_field.push_back(f1);
		m_field.push_back(f2);
		m_field.push_back(f3);
	}
	virtual bool validate() { return false; };
	std::string errorMassge() const;
private:
	std::string m_label;
	std::vector<BaseField*> m_field;
};