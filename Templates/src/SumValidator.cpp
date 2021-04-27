#pragma once

#include "SumValidator.h"

bool SumValidator::validate() {
	return true;
}

std::string SumValidator::errorMassge() const {
	return m_errorMessage;
}