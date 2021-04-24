#pragma once

#include "Field.h"

void Field::addValidator(const Validator* validator) {
	m_validators.push(validator);
}