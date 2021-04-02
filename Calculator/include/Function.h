#pragma once

#include <iostream>
#include <math.h>
#include <vector>
#include "Polynom.h"
#include "Macros.h"

class Function {
public:
	Function(int type) : m_type(type) {};
	Function(Polynom* poly) : m_polynom(poly) {};
	Function(Function* lf, Operator op, Function* rf = nullptr)
		: m_leftFunction(lf), m_rightFunction(rf), m_operator(op) {};
	int get_type() const;
	Polynom* get_polynom() const;
	Operator get_operator() const;
	Function* get_left_function() const;
	Function* get_right_function() const;
	virtual double calculate(double) const;

private:
	Polynom* m_polynom = nullptr;
	Function *m_leftFunction = nullptr,
		*m_rightFunction = nullptr;
	Operator m_operator = Operator::Add;
	int m_type = 3; //if 0 = sin, if 1 = ln, if 3 = else
};

// GLOBAL OPERATORS

std::ostream& operator<<(std::ostream&, Function*);