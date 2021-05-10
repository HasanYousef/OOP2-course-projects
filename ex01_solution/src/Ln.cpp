#include "Ln.h"

#include <cmath>

double Ln::operator()(double x) const
{
	if (x <= 0 || x ==1) {
		throw std::exception("Ln func cant eval 1 or number <= 0\n");
	}
	return std::log(x);
}

std::string Ln::to_string(const std::string& arg) const
{
    return "ln(" + arg + ")";
}
