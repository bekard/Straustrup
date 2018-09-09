#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

int main() {
	// Variables initialization
	int number_of_squares = 0;
	int grain_on_square = 1;
	int needed_grain = 0;

	// Entering the desired amount of grain
	cin >> needed_grain;

	// Cicle
	for (int total = 0; total < needed_grain;) 
	{	
		++number_of_squares;
		total += grain_on_square;
		cout << "squares " << number_of_squares
			<< "| on square " << grain_on_square
			<< "| total " << total << endl;
		grain_on_square *= 2;
	}

	cout << number_of_squares;

	return 0;
}