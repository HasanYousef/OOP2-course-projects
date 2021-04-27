#pragma once

#include "DateValidator.h"

template <class T>
bool DateValidator<T>::validate(T* givenDate) const {
	time_t tt;
	time(&tt);
	tm TM = *localtime(&tt);

	int currYear = TM.tm_year + 1900,
		currMonth = TM.tm_mon,
		currDay = TM.tm_mday;

	int givenYear,
		givenMonth,
		givenDay;
	givenYear = *givenDate % 10000;
	*givenDate /= 10000;
	givenMonth = *givenDate % 100;
	*givenDate /= 100;
	givenDay = *givenDate % 100;
	*givenDate /= 100;

	//checking if the date passed or not
	if (givenYear > currYear)
		return false;
	if (givenYear == currYear) {
		if (givenMonth > currMonth)
			return false;
		if (givenMonth == currMonth) {
			if (givenDay > currDay)
				return false;
		}
	}

	return true;
}

template<class T>
std::string DateValidator<T>::errorMassge() const {
	return "Out of range";
}
