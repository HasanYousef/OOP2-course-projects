#pragma once

#include <iostream>
#include <math.h>
#include <vector>

class Polynom {
public:
	Polynom(const std::vector<double>& consts) : m_consts(consts) {};
	unsigned int get_degree() const;
	double get_const(unsigned int pos) const;
	double calculate(double) const;
private:
	std::vector<double> m_consts;
};

// GLOBAL OPERATORS

std::ostream& operator<<(std::ostream&, const Polynom&);
