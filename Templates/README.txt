Templates
#########################################################################################

authors:
	Omar Yousef  211869284
	Hasan Yousef 322309220

about the program:
	This program let the user to fill an form for family vacation in Hotel that its about 20 room - 10 for family and 
	10 for two people the user start to fill information and if there an error in info the program will print the form 
	and tell him where is the error and what is the error

Design:
              in this program we get the main func ready and we make a form class that have the fields and on every field
	there are a class validator that check if its valid or no there are a lot types of validator  
    
About the files:
              Form.h/.cpp:
                       we save in this class all the fields and validators we want to make the form and print it.
              Field.h/cpp:
                        this class we use for a member in form this class have all what we need for the qustion 
	          in the form and we save the answer on it this class template becuse its take a many of
	          inpute (string, int.....).
              validator.h/.cpp:
                       this class is template this check if the input is valid or not we have a member of it in the field
	         its template becuse we check inputs from diffrent things like string input and else also 
	         this class if the father of many typse of clasees.
              DateValidator.h/.cpp:
                       this class inhert from validator the its check if the date its valid or no.
	IDValidator.h/.cpp:
	        this class inhert from validator the its check if the IDits valid or no.
	NoDigitValidator.h/.cpp:
	        this class inhert from validator its take a string and check if its have no Digits.
	NonNegativeValidator.h/.cpp:
	        this class inhert from validator the its check if the the number we get its positive.
	NotGreaterValidator.h/cpp:
	        this class inhert from validator the its take two paramters and check if the the first 	
	        paramter not greater than the second paramter.
	RangeValidator.h/.cpp:
	        this class inhert from validator the its check if the input on Range.
	SumValidator.h/.cpp:
	        It validates that the value of the first parameter is the same as the sum of the two others .

Data Structures:
              Vector of Field on the Form class.
	Vector of Validators on the Form class.

Notable Algorithms:
               
Bug:

Another Notes:
