#pragma once

#include <iostream>
#include "Validator.h"
#include "Field.h"

// checks if the number of total people = kids + adults
class SumValidator : public Validator<int> {
public:
	SumValidator(std::string errMsg, Field<int>* f1, Field<int>* f2, Field<int>* f3) :
		m_errorMessage(errMsg),
		m_totalPeopleField(f1),
		m_kidsUnder18Field(f2),
		m_adultsAbove18Field(f3) {}
	virtual bool validate() const;
	void refillFields() const;
	virtual std::string errorMassge() const;
private:
	std::string m_errorMessage;
	Field<int>* m_totalPeopleField,		//storing the fields related to the number of people
		*m_kidsUnder18Field,
		*m_adultsAbove18Field;
};