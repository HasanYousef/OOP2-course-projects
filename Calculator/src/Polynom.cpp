#pragma once

#include "Polynom.h"

unsigned int Polynom::get_degree() const {
	return m_consts.size;
}

double Polynom::get_const(unsigned int pos) const {
	return m_consts[pos];
}

double Polynom::calculate(double x) const {
	double sum = 0;
	int degree = get_degree();
	for (unsigned int i = 0; i < degree; i++) {
		sum += get_const(i) * pow(x, i);
	}
	return sum;
}

//print Polynom
std::ostream& operator<<(std::ostream& os, const Polynom& poly) {
	int degree = poly.get_degree();
	for (unsigned int i = 0; i < degree; i++) {
		double c = poly.get_const(i);
		if (i != 0)
			os << " + ";
		if (c != 0)
			os << c << "*x^" << i;
	}
	return os;
}