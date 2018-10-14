#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

double ctok(double c) //temperature conversion
{                     //in degrees Celsius
                      //in temperature in degrees Kelvin
	double k = c + 273.15;
	return k;
}

int main() {

	try {
		double c = 0;       //declare the input variable
		cout << "Please enter degrees:";
		cin >> c;           //enter the temperature

		if (c < -273.15) throw 1;

		double k = ctok(c); //convert the temperature
		cout << k << '\n';  //output the result
		keep_window_open();
		return 0;
	}

	catch (int x) {
		cout << "Temperature below absolute zero." << endl;
		keep_window_open();
		return 1;
	}
}