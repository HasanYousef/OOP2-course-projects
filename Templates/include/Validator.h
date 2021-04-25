#pragma once

#include <iostream>
#include <string>

class BaseValidator {};

template <class T = std::string>
class Validator : public BaseValidator {
public:
	Validator() {};
	virtual bool validate(class T) const {};
};