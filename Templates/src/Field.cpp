#pragma once

#include "Field.h"

void Field<std::string>::readInput() {
	std::cout << m_label << std::endl;
	std::cin >> m_value;
}

void Field<unsigned int>::readInput() {
	std::cout << m_label << std::endl;
	std::cin >> m_value;
}

void Field<int>::readInput() {
	std::cout << m_label << std::endl;
	std::cin >> m_value;
}