#pragma once

#include <string>

// field template classes are inherticance from this class
class BaseField {
public:
	virtual void printField() const;
	virtual void readInput();
	virtual bool validate() const;
	virtual std::string errorMassge() const;
};

