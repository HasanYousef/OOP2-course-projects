#pragma once

#include <iostream>
#include "Validator.h"
#include "Field.h"

class SumValidator : public Validator<int> {
public:
	SumValidator(std::string errMsg, Field<int>* f1, Field<int>* f2, Field<int>* f3) :
		m_errorMessage(errMsg),
		m_totalPeopleField(f1),
		m_kidsUnder18Field(f2),
		m_adultsAbove18Field(f3) {}
	virtual bool validate(int);
	virtual std::string errorMassge() const;
private:
	std::string m_errorMessage;
	Field<int>* m_totalPeopleField,
		*m_kidsUnder18Field,
		*m_adultsAbove18Field;
};