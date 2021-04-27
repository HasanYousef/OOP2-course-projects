#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Validator.h"


class BaseField {
public:
	virtual void readInput() = 0;
	virtual bool validate() const = 0;
	virtual std::string errorMassge() const = 0;
};

template <class T>
class Field : public BaseField {
public:
	Field(std::string label) : m_label(label) {};
	~Field() { delete m_value; }
	void addValidator(Validator<T>*);
	void readInput();
	virtual bool validate() const;
	int getContent() const;
	std::string errorMassge() const;
	std::string getLabel() const;
private:
	std::string m_label;
	T m_value;
	std::vector<Validator<T>*> m_validators;
};

template<class T>
void Field<T>::readInput() {
	std::cout << m_label << std::endl;
	m_value = new T();
	std::cin >> *m_value;
}