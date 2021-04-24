#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib> // for system()
#include <cstdint> // for uint32_t
#include <chrono>  // for currentYear() implementation
#include <ctime>   // for currentYear() implementation


//------------------- User includes ----------------------------

// A class that represents a form. A form has many fields
#include "Form.h"

// A class that represents a field. A field can have one or more validators
#include "Field.h"

// A class that represents a range validator.
// It validates if a field value is in a specific range.
// The type used as template parameter must implement < and > operators.
#include "RangeValidator.h"

// A class that represents a no-digit-characters validator.
// It validates that the field value contains no digits.
// Works only on std::string.
#include "NoDigitValidator.h"

// A class that represents an ID validator.
// ID validation is done using the control digit.
// Works only on the type 'uint32_t'.
#include "IDValidator.h"

// A class to represent a Non negative value validator.
// Template class must be able to be > 0;
#include "NonNegativeValidator.h"

// A class that implements a not-greater-than validator
// It validates that the value of the first parameter is the not greater than the value of the second one
// The types used as template parameter must be arithmetic (int-like)
#include "NotGreaterThanValidator.h"

// A class that implements a sum validator
// It validates that the value of the first parameter is the same as the sum of the two others
#include "SumValidator.h"

// A class that implements a sum validator
// It validates that the value of the first parameter is the same as the sum of the two others
#include "RoomValidator.h"

// A class that implements a date validator
// It validates that the date of the order has already passed
// The types used as template parameter must be arithmetic (int-like)
#include "DateValidator.h"


//------------------- Function declarations ----------------------------

// Prints welcome message
void displayWelcomeMessage();

// Prints goodbye message
void displayGoodbyeMessage();

// Prints error message
void displayErrorMessage();

// Prints price
void displayPrice(int totalPeople, int roomNum);

// Utility function for clearing the terminal screen
void clearScreen();

// Utility function for getting current year from computer clock
int currentYear();


//------------------- consts --------------------------

const int MIN_AGE = 18;
const int MAX_AGE = 120;
const int ROOMS_NUM = 10;


//------------------- main ----------------------------

int main()
{
    // Creating the form fields
    auto nameField          = std::make_unique<Field<std::string>>("What is your name?");
    auto idField            = std::make_unique<Field<uint32_t>>   ("What is your ID?");
    auto yearOfBirthField   = std::make_unique<Field<int>>        ("What is your year of birth?");
    auto startDateField     = std::make_unique<Field<int>>        ("What is the date on which you wish to start your vacation? (ddmmyyyy)");
    auto nightsNumField     = std::make_unique<Field<int>>        ("How many nights do you wish to invite?");
    auto pairRoomsField     = std::make_unique<Field<int>>        ("How many pair rooms do you want?");
    auto familyRoomsField   = std::make_unique<Field<int>>        ("How many family rooms do you want?");
    auto totalPeopleField   = std::make_unique<Field<int>>        ("How many people?");
    auto kidsUnder18Field   = std::make_unique<Field<int>>        ("Number of children under 18?");
    auto adultsAbove18Field = std::make_unique<Field<int>>        ("Number of adults over 18?");
    
    // Creating the field validators
    auto nameValidator             = std::make_unique<NoDigitValidator>();
    auto idValidator               = std::make_unique<IDValidator>();
    auto ageValidator              = std::make_unique<RangeValidator<int>>(currentYear() - MAX_AGE, currentYear() - MIN_AGE);
    auto dateValidator             = std::make_unique<DateValidator<int>>();
    auto nightsValidator           = std::make_unique<NonNegativeValidator<int>>();
    auto totalPeopleValidator      = std::make_unique<NonNegativeValidator<int>>();
    auto totalPairRoomsValidator   = std::make_unique<NotGreaterThanValidator<int>>(ROOMS_NUM);
    auto totalFamilyRoomsValidator = std::make_unique<NotGreaterThanValidator<int>>(ROOMS_NUM);
    auto kidsUnder18Validator      = std::make_unique<NonNegativeValidator<int>>();
    auto adultsAbove18Validator    = std::make_unique<NonNegativeValidator<int>>();
  
    // Adding the validators to the fields
    nameField         ->addValidator(nameValidator.get());
    idField           ->addValidator(idValidator.get());
    yearOfBirthField  ->addValidator(ageValidator.get());
    startDateField    ->addValidator(dateValidator.get());
    nightsNumField    ->addValidator(nightsValidator.get());
    totalPeopleField  ->addValidator(totalPeopleValidator.get());
    pairRoomsField    ->addValidator(totalPairRoomsValidator.get());
    familyRoomsField  ->addValidator(totalFamilyRoomsValidator.get());
    kidsUnder18Field  ->addValidator(kidsUnder18Validator.get());
    adultsAbove18Field->addValidator(adultsAbove18Validator.get());

    // Creating form validators
    auto peopleSumFieldsValidator = std::make_unique<SumValidator>(
        "Number of adults and children doesn't match total number of people",
        totalPeopleField.get(),
        kidsUnder18Field.get(),
        adultsAbove18Field.get());
    auto peopleVsRoomsFieldsValidator = std::make_unique<RoomValidator>(
        "Number of people doesn't match to the maximum number of people that can be entered as you invite",
        pairRoomsField.get(),
        familyRoomsField.get(),
        totalPeopleField.get());

    // Creating the form and adding the fields to it
    auto myForm = Form();
    myForm.addField(nameField.get());
    myForm.addField(idField.get());
    myForm.addField(yearOfBirthField.get());
    myForm.addField(startDateField.get());
    myForm.addField(nightsNumField.get());
    myForm.addField(pairRoomsField.get());
    myForm.addField(familyRoomsField.get());
    myForm.addField(totalPeopleField.get());
    myForm.addField(kidsUnder18Field.get());
    myForm.addField(adultsAbove18Field.get());

    // Adding form validator
    myForm.addValidator(peopleSumFieldsValidator.get());
    myForm.addValidator(peopleVsRoomsFieldsValidator.get());

    // Getting the information from the user
    clearScreen();
    displayWelcomeMessage();

    // Get the input only for empty or not valid fields
    myForm.fillForm();

    // Validation loop
    while (!myForm.validateForm())
    {
        // Displays all form fields with value (and error if not valid)
        clearScreen();
        displayErrorMessage();
        std::cout << myForm << '\n';
        myForm.fillForm();
    }

    clearScreen();
    displayGoodbyeMessage();
    std::cout << myForm << '\n';
    displayPrice(totalPeopleField.get()->getContent(), pairRoomsField.get()->getContent() + familyRoomsField.get()->getContent());
}

void displayWelcomeMessage()
{
    std::cout << "+---------------------------------------------------+\n"
                 "|                 Hello and welcome                 |\n"
                 "|       Please fill the details of the order        |\n"
                 "+---------------------------------------------------+\n";
}

void displayErrorMessage()
{
    std::cout << "+---------------------------------------------------+\n"
                 "| There was an error in at least one of the fields! |\n"
                 "|            Please correct the error(s)            |\n"
                 "+---------------------------------------------------+\n";
}

void displayGoodbyeMessage()
{
    std::cout << "+---------------------------------------------------+\n"
                 "|                    Thank you!                     |\n"
                 "|           These are your order details:           |\n"
                 "+---------------------------------------------------+\n";
}

void displayPrice(int totalPeople, int roomNum)
{
    const auto price = totalPeople * 100 + roomNum * 300;
    const auto priceStr = std::to_string(price);
    const auto spaces = std::string(23 - priceStr.size() / 2, ' ');
    std::cout << "+---------------------------------------------------+\n"
                 "|                   The price is:                   |\n"
                 "|" << spaces << priceStr << " NIS " << spaces << "|\n"
                 "+---------------------------------------------------+\n";
}

void clearScreen()
{
    system("cls"); // Windows specific
}

int currentYear()
{
    using clock = std::chrono::system_clock;
    const auto now = clock::to_time_t(clock::now());
    auto calendarTime = std::tm{};
    localtime_s(&calendarTime, &now);
    return calendarTime.tm_year + 1900;
}