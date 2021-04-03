#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Function.h"

class Solver
{
public:
	Solver();
	void run();

private:
	void printHelp();
	Function* poly();
	void createFunc(Operator);
	int findFunc();

	std::vector<Function*> m_functions;	
};