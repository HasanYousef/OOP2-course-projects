#include "Log.h"

#include <cmath>

Log::Log(int base, const std::shared_ptr<Function>& func)
    : m_base(base), m_func(func)
{
}

double Log::operator()(double x) const
{
    if (x <= 0 || x == 1) {
        throw std::exception("log func cant eval 1 or number <= 0\n");
    }
    return std::log((*m_func)(x)) / std::log(m_base);
}

std::string Log::to_string(const std::string& arg) const
{
    return "log_" + std::to_string(m_base) + "(" + m_func->to_string(arg) + ")";
}
