#pragma once

#include <iostream>
#include <string>

class BaseValidator{
	virtual bool validate(class T*) const = 0;
};

template <class T>
class Validator : BaseValidator {
public:
	Validator() {};
	virtual bool validate(class T*) const { return true; };
};