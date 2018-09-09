#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

int main() {
	// Variables initialization
	int number_of_squares = 0;
	double grain_on_square = 1;
	double total = 0;

	// Data input
	cin >> number_of_squares;

	// Cicle
	for (int counter = 1; counter <= number_of_squares; ++counter) {
		total += grain_on_square;
		cout << counter << '\t' << grain_on_square << '\t' << total << endl;
		grain_on_square *= 2;
	}
	// For 'int' max correct result is number_of_squares == 31
	// For 'double' max correct result is number_of_squares == 65+

	return 0;
}