#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

double ctok(double c)
// converts Celsius to Kelvin
{
	if (c < -273.15) error("Temperature below absolute zero!");
	double k = c + 273.15;
	return k;
}

double ktoc(double k)
// converts Kelvin to Celsius
{
	if (k < 0) error("Temperature below absolute zero!");
	double c = k - 273.15;
	return c;
}

int main()
try
{
	double temp = 0;
	double temp_conv = 0;
	char unit = ' ';
	char unit_conv = ' ';

	cout << "Please enter the tempetarure and unit: ";
	cin >> temp >> unit;
	switch (unit) {

	case 'c': case 'C':
		temp_conv = ctok(temp);
		unit_conv = 'K';
		break;
	
	case 'k': case 'K':
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