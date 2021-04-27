#pragma once

#include <iostream>
#include <time.h>
#include "Validator.h"

class IDValidator : public Validator<uint32_t> {
	virtual bool validate(uint32_t) const;
	std::string errorMassge() const;
};

bool IDValidator::validate(uint32_t id) const {
    int incNum, num, el = 0, sum = 0;
    while (id != 0) {
        num = id % 10;
        incNum = num * ((el % 2) + 1);
        sum += (incNum > 9) ? incNum - 9 : incNum;
        id = id / 10;
        el++;
    }
    if (el != 8)
        return false;
    return (sum % 10 == 0);
}

std::string IDValidator::errorMassge() const {
    return "Wrong control digit";
}