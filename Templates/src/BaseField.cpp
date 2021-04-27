#pragma once

#include "BaseField.h"

void BaseField::readInput() {}
bool BaseField::validate() const { return false; };
std::string BaseField::errorMassge() const { return ""; };