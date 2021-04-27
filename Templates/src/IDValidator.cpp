#pragma once

#include "IDValidator.h"

std::string IDValidator::errorMassge() const {
    return "Wrong control digit";
}

// checks if the control digit is the right one in the id
bool IDValidator::validate(uint32_t id) const {
	std::string str = std::to_string(id);

	if (str.length() != 9) // Make sure ID is formatted properly
		return false;

	int sum = 0,
		incNum;
	for (size_t i = 0; i < str.size(); i++)
		if (!isdigit(str[i]))
			return false;
		else
		{
			incNum = ((int)str[i] - '0') * ((i % 2) + 1);
			sum += (incNum > 9) ? incNum - 9 : incNum;
		}

	return (sum % 10 == 0);
}