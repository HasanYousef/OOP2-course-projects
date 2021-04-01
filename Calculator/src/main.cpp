#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "Function.h"

int main() {
	std::vector<double> consts = { 3, -2, 5 };
	Function func(Polynom(consts));
	std::cout << func;
	return EXIT_SUCCESS;
}