#pragma once

#include <iostream>

template <class T = char>
class Validator {
public:
	virtual bool wrongInput(T*);

private:
};