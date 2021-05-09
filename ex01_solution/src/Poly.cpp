#include "Poly.h"

#include <iomanip>
#include <sstream>

namespace
{
bool allZeros(const std::vector<double>& values)
{
    for (auto i : values)
    {
        if (i)
        {
            return false;
        }
    }
    return true;
}
}

Poly::Poly(const std::vector<double>& coeffs)
    : m_coeffs(coeffs)
{
    if (allZeros(coeffs))
    {
        m_coeffs.clear();
    }
}

double Poly::operator()(double x) const
{
    auto res = 0.;
    auto currentX = 1.;

    for (decltype(m_coeffs.size()) i = 0; i < m_coeffs.size(); ++i)
    {
        res += m_coeffs[i] * currentX;
        currentX *= x;
    }

    return res;
}

std::string Poly::to_string(const std::string& arg) const
{
    if (m_coeffs.empty())
    {
        return "0";
    }

    auto sstr = std::ostringstream();
    sstr << std::setprecision(2) << std::fixed;

    auto first = true;
    for (auto i = m_coeffs.size(); i > 0; --i)
    {
        const auto c = m_coeffs[i - 1];
        if (c)
        {
            if (!first)
            {
                sstr << " + ";
            }
            sstr << c << "*(" << arg << ")^" << i - 1;
            first = false;
        }
    }

    return sstr.str();
}
