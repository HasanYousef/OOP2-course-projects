#include "Sin.h"

#include <cmath>

double Sin::operator()(double x) const
{
    return std::sin(x);
}

std::string Sin::to_string(const std::string& arg) const
{
    return "sin(" + arg + ")";
}
