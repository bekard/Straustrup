#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

// double df = 9.0 / 5 * dc + 32;

double ctok(double c)
// converts Celsius to Fahrenheit
{
	if (c < -273.15) error("Temperature below absolute zero!");
	double k = 9.0 / 5.0 * c + 32;
	return k;
}

double ktoc(double k)
// converts Fahrenheit to Celsius
{
	if (k < 0) error("Temperature below absolute zero!");
	double c = (k - 32) * 5.0 / 9.0;
	return c;
}

int main()
try
{
	double temp = 0;
	double temp_conv = 0;
	char unit = ' ';
	char unit_conv = ' ';

	cout << "Please enter the tempetarure and unit ";
	cout << "(for Celsius [c or C], for Fahrenheit [f or F]." << endl;
	cin >> temp >> unit;
	switch (unit) {

	case 'c': case 'C':
		temp_conv = ctok(temp);
		unit_conv = 'F';
		break;
	
	case 'f': case 'F':
		temp_conv = ktoc(temp);
		unit_conv = 'C';
		break;

	default:
		error("Incorrect unit.");
		break;
	}

	cout << "Temperature: " << temp_conv << " " << unit_conv;
    cout << endl;
	keep_window_open();
	return 0;
}

catch (exception& e) {
	cerr << "Error: " << e.what() << endl;
	return 1;
}

catch (...) {
	cerr << "Unknown exception!\n";
	return 2;
}