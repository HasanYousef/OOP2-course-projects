#pragma
#include "Solver.h"

//----------------------------------------------
Solver::Solver() {
	Function* f = new Function(0);
	m_functions.push_back(f);
	f = new Function(1);
	m_functions.push_back(f);
	m_isDeleted = { false, false };
}

//----------------------------------------------
void Solver::run() {
	std::string command, input;
	Function* f;
	while (true) {
		f = NULL; //we rest the func adder
		std::cout << "This is the function list: " << std::endl;
		//print the functions
		for (int func = 0; func < m_functions.size(); func++) {
			if (!m_isDeleted[func]) {
				std::cout << m_functions[func] << std::endl;
			}
		}
		std::cout << "Please enter a command (help for command list): ";
		//read the inpute
		std::cin >> command;
		//do the command
		if (command == "eval") {

		}
		else if (command == "poly") {
			// function not work
			Polynom* p = poly();
			if (p) {
				m_functions.push_back(f);
				m_isDeleted.push_back(false);
			}
			p = NULL;
		}
		else if (command == "mul") {
			createFunc(Operator::Multiply);
			m_isDeleted.push_back(false);
		}
		else if (command == "add") {
			createFunc(Operator::Add);
			m_isDeleted.push_back(false);;
		}
		else if (command == "comp") {
			int num;
			std::cin >> num;

			m_isDeleted.push_back(false);
		}
		else if (command == "log") {

		}
		else if (command == "del") {
			//change to try catch
			std::getline(std::cin, input);
			if (isdigit(input[1])) {
				m_isDeleted[int(input[1] - '0')] = false;
			}
		}
		else if (command == "help") {
			printHelp();
		}
		else if (command == "exit") {
			std::cout << "Goodbye" << std::endl;
		}
	}
}

//----------------------------------------------
void Solver::createFunc(Operator oper) {
	std::string input;
	int num1, num2;
	std::cin >> num1 >> num2;
	m_functions.push_back(new Function(m_functions[num1], oper, m_functions[num2]));
	m_isDeleted.push_back(false);
}

//----------------------------------------------
void Solver::printHelp() {
	std::cout << " Following is the list of the calculator's available commands:" << std::endl
		<< "eval(uate) num x - Evaluates function #num on x" << std::endl <<
		"poly(nomial) N c0 c1 ... cN - 1 - Creates a polynomial with N coefficients" << std::endl
		<< "mul(tiply) num1 num2 - Creates a function that is the multiplication of" << std::endl
		<< "function #num1 and function #num2" << std::endl <<
		"add num1 num2 - Creates a function that is the sum of function #num1 and" << std::endl
		<< "function #num2" << std::endl
		<< "comp(osite) num1 num2 - Creates a function that is the composition of"
		<< std::endl << "function #num1 and function #num2" << std::endl <<
		"log N num - Creates a function that computes log N of function #num" << std::endl
		<< "del(ete) num - Deletes function #num from function list " << std::endl;
}

//----------------------------------------------
Polynom* Solver::poly() {
	std::vector<double> vec;
	int degree, num;
	std::cin >> degree;
	while (std::cin >> num) {
		vec.push_back(num);
	}
	if (vec.size() != degree) {
		return NULL;
	}
	return (new Polynom(vec));
	
}