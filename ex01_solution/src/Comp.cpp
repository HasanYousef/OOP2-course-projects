#include "Comp.h"

Comp::Comp(const std::shared_ptr<Function>& a, const std::shared_ptr<Function>& b)
    : m_a(a), m_b(b)
{
}

double Comp::operator()(double x) const
{
    return (*m_a)((*m_b)(x));
}

std::string Comp::to_string(const std::string& arg) const
{
    return m_a->to_string(m_b->to_string(arg));
}
