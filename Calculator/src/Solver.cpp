#pragma
#include "Solver.h"

//----------------------------------------------
Solver::Solver() {
	Function* f = new Function(0);
	m_functions.push_back(f);
	f = new Function(1);
	m_functions.push_back(f);
}

//----------------------------------------------
void Solver::run() {
	std::string command, input;
	Function* f;
	int funNum, func;
	while (true) {
		f = NULL; //we rest the func adder
		std::cout << "This is the function list: " << std::endl;
		//print the functions
		funNum = 0;
		for (int func = 0; func < m_functions.size(); func++) {
			if (!m_functions[func]->isDeleted()) {
				std::cout << funNum << ": " << m_functions[func] << std::endl;
				funNum++;
			}
		}
		std::cout << "Please enter a command (help for command list): ";
		//read the inpute
		std::cin >> command;
		//do the command
		if (command == "eval") {
			int value;
			func = findFunc();
			std::cin >> value;
			if (func != -1) {
				std::cout << std::setprecision(2) << m_functions[func]->calculate(value) << std::endl;
			}
		}
		else if (command == "poly") {
			// function not work
			f = poly();
			if (f) {
				m_functions.push_back(f);
			}
		}
		else if (command == "mul") {
			createFunc(Operator::Multiply);
		}
		else if (command == "add") {
			createFunc(Operator::Add);
		}
		else if (command == "comp") {
			
		}
		else if (command == "log") {
			// log(num) / log(base) = log N num
			int base;
			func = findFunc();
			if (func != -1) {
				std::cin >> base;
			}
			// not finish
		}
		else if (command == "del") {
			func = findFunc();
			if (func != -1) {
				m_functions[func]->deleteIt();
			}
		}
		else if (command == "help") {
			printHelp();
		}
		else if (command == "exit") {
			std::cout << "Goodbye" << std::endl;
			return;
		}
		else {
			std::cout << "Wrong Input" << std::endl;
		}
	}
}

//----------------------------------------------
void Solver::createFunc(Operator oper) {
	int num1, num2, 
		func1 = -1, 
		func2 = -1,
		deletedNum = -1;
	std::cin >> num1 >> num2;
	//looking for the functions in the array
	for (int i = 0; i < m_functions.size(); i++) {
		if (!(m_functions[i]->isDeleted()))
			deletedNum++;
		if (num1 == deletedNum && func1 < 0)
			func1 = i;
		if (num2 == deletedNum && func2 < 0)
			func2 = i;
	}

	if (func1 != -1 && func2 != -1) {
		m_functions.push_back(new Function(m_functions[func1],
			oper, m_functions[func2]));
	}
	else {
		std::cout << "Wrong Input" << std::endl;
	}
}

//----------------------------------------------
void Solver::printHelp() {
	std::cout << " Following is the list of the calculator's available commands:" << 
		std::endl << "eval(uate) num x - Evaluates function #num on x" << std::endl <<
		"poly(nomial) N c0 c1 ... cN - 1 - Creates a polynomial with N coefficients" << 
		std::endl << "mul(tiply) num1 num2 - Creates a function that is the multiplication of"
		<<  std::endl << "function #num1 and function #num2" << std::endl <<
		"add num1 num2 - Creates a function that is the sum of function #num1 and" <<
		std::endl << "function #num2" << std::endl << 
		"comp(osite) num1 num2 - Creates a function that is the composition of"
		<< std::endl << "function #num1 and function #num2" << std::endl <<
		"log N num - Creates a function that computes log N of function #num" << std::endl
		<< "del(ete) num - Deletes function #num from function list " << std::endl;
}

//----------------------------------------------
Function* Solver::poly() {
	std::vector<double> vec;
	int degree, num;
	std::cin >> degree;
	while (std::cin >> num) {
		vec.push_back(num);
	}
	if (vec.size() != degree) {
		return NULL;
	}
	Polynom* p = new Polynom(vec);
	return new Function(p);
}

int Solver::findFunc() {
	int funNum,
		deletedNum = 0;
	std::cin >> funNum;
	for (int func = 0; func < m_functions.size(); func++) {
		if (m_functions[func]->isDeleted()) {
			deletedNum++;
		}
		if ((func - deletedNum) == funNum) {
			return func;
		}
	}
	return -1;
}