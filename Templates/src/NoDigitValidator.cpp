#pragma once

#include "NoDigitValidator.h"

// makes sure that there is no digit in the string
bool NoDigitValidator::validate(std::string str) const {
	if (str.length() == 0)
		return false;
	for (int chr = 0; chr < str.length(); chr++) {
		if (str[chr] >= '0' && str[chr] <= '9') {
			return false;
		}
	}
	return true;
}

std::string NoDigitValidator::errorMassge() const {
	return "Can't contain digits";
}