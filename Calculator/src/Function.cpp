#pragma once

#include "Function.h"

int Function::get_type() const {
	return m_type;

}
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
	else if (m_type == 0) {
		return sin(x);
	}
	else if (m_type == 1) {
		return log(x);
	}
	else {
		double left = m_leftFunction->calculate(x);
		if (m_rightFunction) {
			double right = m_rightFunction->calculate(x);
			switch (m_operator)
			{
			case Operator::Add:
				return left + right;
			case Operator::Multiply:
				return left * right;
			}
		}
		else
			return left;
	}
}

//print Function
std::ostream& operator<<(std::ostream& os, Function* func) {
	if (func == nullptr) {
		os << "x";
		return os;
	}
	Function* leftFunc = func->get_left_function(),
		* rightFunc = func->get_right_function();
	int funcType = func->get_type();
	if (funcType == 0) {
		os << "sin(" << leftFunc << ")";
		return os;
	}
	if (funcType == 1) {
		os << "ln(" << leftFunc << ")";
		return os;
	}
	Polynom *poly = func->get_polynom();
	if (poly) {
		os << *(poly);
	}
	else {
		if (!rightFunc) {
			return os << leftFunc;
		}
		os << "( " << leftFunc;
		switch (func->get_operator())
		{
		case Operator::Add:
			os << " + ";
			break;
		case Operator::Multiply:
			break;
			os << " * ";
		}
		os << rightFunc << " )";
	}
	return os;
}