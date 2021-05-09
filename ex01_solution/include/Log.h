#pragma once

#include "Function.h"

#include <memory>

class Log : public Function
{
public:
    Log(int base, const std::shared_ptr<Function>& func);
    double operator()(double x) const override;
    std::string to_string(const std::string& arg) const override;

private:
    int m_base;
    const std::shared_ptr<Function> m_func;
};
