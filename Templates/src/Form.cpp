#pragma once

#include "Form.h"

void Form::fillForm() {
	for (int el = 0; el < m_fields.size(); el++) {
		if (m_fields[el]->emptyInput()) {
			m_fields[el]->readInput();
		}
	}
}

bool Form::validateForm() {
	for (int el = 0; el < m_fields.size(); el++) {
		if ( m_fields[el]->emptyInput()) {
			return false;
		}
	}
	return true;
}
