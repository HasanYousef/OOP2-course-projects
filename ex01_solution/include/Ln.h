#pragma once

#include "Function.h"

class Ln : public Function
{
public:
    double operator()(double x) const override;
    std::string to_string(const std::string& arg) const override;
};
