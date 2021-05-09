#pragma once

#include <string>

class Function
{
public:
    virtual ~Function() = default;
    virtual double operator()(double x) const = 0;
    virtual std::string to_string(const std::string& arg) const = 0;
};
