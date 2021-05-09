#include "Add.h"

Add::Add(const std::shared_ptr<Function>& a, const std::shared_ptr<Function>& b)
    : m_a(a), m_b(b)
{
}

double Add::operator()(double x) const
{
    return (*m_a)(x) + (*m_b)(x);
}

std::string Add::to_string(const std::string& arg) const
{
    return "(" + m_a->to_string(arg) + ") + (" + m_b->to_string(arg) + ")";
}
