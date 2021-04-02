#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "Function.h"
#include "Solver.h"

void run();
void printHelp();
Function* buildPoly(std::string polynom);

int main() {
	Solver slv = Solver();
	slv.run();
	return EXIT_SUCCESS;
}

void run() {
	std::vector<Function*> functions;
	functions.push_back(new Function(0));
	functions.push_back(new Function(1));
	std::vector<bool> isDeleted({false, false});

	std::string command, input;
	Function* f;
	while (true) {
		f = NULL; //we rest the func adder
		std::cout << "This is the function list: " << std::endl;
		//print the functions
		for (int func = 0; func < functions.size(); func++) {
			if (!isDeleted[func]) {
				std::cout << functions[func] << std::endl;
			}
		}
		std::cout << "Please enter a command (help for command list): ";
		//read the input
		std::cin >> command;
		//do the command
		if (command == "eval") {

		}
		else if (command == "poly") {
			// function not work
			f = buildPoly(input);
			if (f) {
				functions.push_back(f);
			}
			isDeleted.push_back(true);
		}
		else if (command == "mul") {
			getline(std::cin, input);
			if (isdigit(input[1]) && isdigit(input[3])) {
				f = new Function(functions[int(input[1] - '0')]
					, Multiply, functions[int(input[3] - '0')]);
				functions.push_back(f);
			}
			isDeleted.push_back(true);
		}
		else if (command == "add") {
			getline(std::cin, input);
			if (isdigit(input[1]) && isdigit(input[3])) {
				f = new Function(functions[int(input[1] - '0')]
					, Add, functions[int(input[3] - '0')]);
				functions.push_back(f);
			}
			isDeleted.push_back(true);
		}
		else if (command == "comp") {
			getline(std::cin, input);
			if (isdigit(input[1]) && isdigit(input[3])) {
				f = new Function(functions[int(input[1] - '0')]);
				functions.push_back(f);
			}
			isDeleted.push_back(true);
		}
		else if (command == "log") {

		}
		else if (command == "del") {
			//change to try catch
			getline(std::cin, input);
			if (isdigit(input[1])) {
				isDeleted[int(input[1] - '0')] = false;
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
void printHelp() {
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
Function * buildPoly(std::string polynom) {
	std::vector<double> vec;
	int degree, num;
	std::cin >> degree;
	while (std::cin >> num) {
		vec.push_back(num);
	}
	if (vec.size() != degree) {
		return NULL;
	}
	Polynom* poly = new Polynom(vec);
	return (new Function(poly));
}