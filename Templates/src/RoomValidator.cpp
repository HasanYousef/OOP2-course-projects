#pragma once

#include "RoomValidator.h"

bool RoomValidator::validate() const {
	int capacity = 0;
	capacity += m_fields[0]->getContent() * 2;
	capacity += m_fields[1]->getContent() * 5;
	return  m_fields[2]->getContent() <= capacity;
}

void RoomValidator::refillFields() const {
	for(int i = 0; i < m_fields.size() - 1; i++)
		m_fields[i]->readInput();
}

std::string RoomValidator::errorMassge() const {
    return "the maximum is 10 rooms";
}
