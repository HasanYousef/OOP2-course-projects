#pragma once

#include <iostream>
#include <string>

template <class T>
class Validator {
public:
	virtual bool validate(T) const;
	virtual std::string errorMassge() const;
};

template <class T>
bool Validator<T>::validate(T) const {
	return false; 
}

template <class T>
std::string Validator<T>::errorMassge() const {
	return "The input you intered is not valid.";
}