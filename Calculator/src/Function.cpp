#pragma once

#include "Function.h"

Polynom* Function::get_polynom() const {
	return m_polynom;
}

Operator Function::get_operator() const {
	return m_operator;
}

Function* Function::get_left_function() const {
	return m_leftFunction;
}

Function* Function::get_right_function() const {
	return m_rightFunction;
}

double Function::calculate(double x) const {
	if (m_polynom) {
		return m_polynom->calculate(x);
	}
	else {
		double left = m_leftFunction->calculate(x);
		if (m_rightFunction) {
			double right = m_rightFunction->calculate(x);
			switch (m_operator)
			{
			case Operator::Add:
				return left + right;
			case Operator::Subtract:
				return left - right;
			case Operator::Multiply:
				return left * right;
			case Operator::Divide:
				return left / right;
			}
		}
		else
			return left;
	}
}

//print Polynom
std::ostream& operator<<(std::ostream& os, const Function& func) {
	if (m_polynom) {
		os << *(func.get_polynom());
	}
	else {
		Polynom *leftFunc = func.get_left_function(),
			*rightFunc = func.get_right_function();
		if (!rightFunc) {
			return os << *(func.get_left_function());
		}
		os << "( " << leftFunc*;
		switch (func.get_operator())
		{
		case Operator::Add:
			os << " + ";
		case Operator::Subtract:
			os << " - ";
		case Operator::Multiply:
			os << " * ";
		case Operator::Divide:
			os << " / ";
		}
		os << rightFunc* << " )";
	}
	return os;
}