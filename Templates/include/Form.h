#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Field.h"
#include "RoomValidator.h"
#include "SumValidator.h"

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
	SumValidator* m_sumValidator = nullptr;		//form sum validator
	RoomValidator* m_roomValidator = nullptr;	// form room validator
};

// print operator
std::ostream& operator<<(std::ostream&, Form&);