#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "Function.h"

int main() {
	std::vector<double> consts = { 3, -2, 5 };
	Polynom* poly = new Polynom(consts);
	Function func(poly);
	std::cout << func;
	return EXIT_SUCCESS;
}