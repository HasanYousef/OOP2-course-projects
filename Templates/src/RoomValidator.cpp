#pragma once

#include "RoomValidator.h"

bool RoomValidator::validate() const {
    return false;
}

std::string RoomValidator::errorMassge() const {
    return "the maximum is 10 rooms";
}
