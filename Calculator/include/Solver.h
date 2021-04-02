#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "Function.h"

class Solver
{
public:
	Solver();
	void run();

private:
	void printHelp();
	Polynom* poly();
	void createFunc(Operator);

	std::vector<Function*> m_functions;
	std::vector<bool> m_isDeleted;	
};