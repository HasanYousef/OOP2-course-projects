#pragma once

#include <iostream>
#include <vector>
#include "Field.h"

class Form {
public:
	void addField(Field*);
private:
	std::vector<Field*> m_fields;
};