#pragma once

#include <iostream>
#include <math.h>
#include <vector>
#include "Polynom.h"
#include "Macros.h"

class Function {
public:
	Function(Polynom*);
	Function(Function*);
	Function(Function*, Function*);
	Polynom* get_polynom() const;
	Operator get_operator() const;
	Function* get_left_function() const;
	Function* get_right_function() const;
	double calculate(double) const;

private:
	Function *m_leftFunction,
		*m_rightFunction;
	Operator m_operator;
	Polynom *m_polynom;
};

// GLOBAL OPERATORS

std::ostream& operator<<(std::ostream&, const Polynom&);