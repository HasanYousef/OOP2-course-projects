#pragma once

#include <iostream>
#include <math.h>
#include <vector>
#include "Polynom.h"
#include "Macros.h"

class Function {
public:
	Function(Polynom* poly) : m_polynom(poly) {};
	Function(Function* lf, Function* rf = nullptr) 
		: m_leftFunction(lf), m_rightFunction(rf) {};
	Polynom* get_polynom() const;
	Operator get_operator() const;
	Function* get_left_function() const;
	Function* get_right_function() const;
	double calculate(double) const;

private:
	Function *m_leftFunction = nullptr,
		*m_rightFunction = nullptr;
	Operator m_operator = Operator::Add;
	Polynom *m_polynom = nullptr;
};

// GLOBAL OPERATORS

std::ostream& operator<<(std::ostream&, const Function&);