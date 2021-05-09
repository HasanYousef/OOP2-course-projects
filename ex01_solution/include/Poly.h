#pragma once

#include "Function.h"

#include <vector>

class Poly : public Function
{
public:
    Poly(const std::vector<double>& coeffs);
    double operator()(double x) const override;
    std::string to_string(const std::string& arg) const override;

private:
    std::vector<double> m_coeffs;
};
