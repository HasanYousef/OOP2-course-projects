#pragma once

#include "NonNegativeValidator.h"

bool NonNegativeValidator::validate(int num) const {
    return (num >= 0);
}
