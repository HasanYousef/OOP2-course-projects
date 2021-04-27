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
	os << "-------------------------------------------------------------------------\n";
	for (int el = 0; el < dt.size(); el++) {
		auto field = dt.getField(el);
		os << field << " ";
		if(!field->validate()) {
			os << field->errorMassge();
		}
		os << "\n-------------------------------------------------------------------------\n";
	}
	return os;
}