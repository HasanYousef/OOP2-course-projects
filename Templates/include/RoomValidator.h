#pragma once

#include <iostream>
#include <vector>
#include "Validator.h"

class BaseField;

class RoomValidator : public Validator<int> {
public:
	RoomValidator(std::string str, BaseField* f1,
		BaseField* f2, BaseField* f3) {
		m_label = str;
		m_field.push_back(f1);
		m_field.push_back(f2);
		m_field.push_back(f3);
	}
	virtual bool validate() const;
	std::string errorMassge() const;
private:
	std::string m_label;
	std::vector<BaseField*> m_field;
};