#pragma once

#include "SumValidator.h"

bool SumValidator::validate() const {
	return (
		(m_adultsAbove18Field->getContent() + m_kidsUnder18Field->getContent())
			== m_totalPeopleField->getContent()
	);
}

void SumValidator::refillFields() const {
	m_totalPeopleField->readInput();
	m_kidsUnder18Field->readInput();
	m_adultsAbove18Field->readInput();
}

std::string SumValidator::errorMassge() const {
	return m_errorMessage;
}