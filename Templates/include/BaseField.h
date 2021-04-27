#pragma once

#include <string>

class BaseField {
public:
	virtual void readInput();
	virtual bool validate() const;
	virtual std::string errorMassge() const;
};

