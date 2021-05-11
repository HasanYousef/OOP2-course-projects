Calculator
#########################################################################################

authors:
	Omar Yousef
	Hasan Yousef

about the program:
               in this program we make a functions and evaluate them we start with ln(x) and sin(x) and
	we can make a complexe function from him like to add dunction on function or to mul
	two functions also to composite we also can make a polynom and do the same things with 
	functions (add, Mul, composite)

Design:
               we have the FunctionCalculator this class that control and manage all the things between the another
	classes, also we have function class that there are 4 class inheritance from this class this make 
	easy to know and know the type of function  (ln, add func, mul func, log, polynom..)
	in the solver, we have all the function we need
        
About the files:
               FunctionCalculator
		this class mange all the work between the classes its have 
		vector of functions that let us to save and mange them.
	function:
		this class have virtual function that we need them on
		all another calsses that inhert from it.
	Ln:
		this class have every thing that we need for the lnx func
	sin:
		this class have every thing that we need for the sin(x) func		
	Add:
		this class is about to functions that they add to another
		for example func1 + func 2
	Mull
		this class is about to functions that they mul to another
		for example func1 * func 2
	Mull
		this class is about to functions that they comp to another
		for example func1( func 2)
	Polynom:
		this class have vector of double that we save the consts of the polynom
		and we print and calculate by virtual function
	LogFunc:
		this class mange the Log function with base that choosen we have
		a function member in class to make it more easy

Data Structures:
              vector of FunctionsList 
	vector of ActionMap

Notable Algorithms:
	we just use this log condition: loge[base](num) = ln(num) / ln(base)
       
Bug:

Another Notes:
      