#pragma once

#include "SumValidator.h"

bool SumValidator::validate(int) {
	return true;
}

std::string SumValidator::errorMassge() const {
	return m_errorMessage;
}