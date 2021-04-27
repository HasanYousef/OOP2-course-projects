#pragma once

#include <iostream>
#include "Validator.h"

class NoDigitValidator : public Validator<std::string> {
public:
	bool validate(std::string str) const;
	virtual std::string errorMassge() const;
};

bool NoDigitValidator::validate(std::string str) const {
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
