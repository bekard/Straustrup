#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

double ctok(double c) //temperature conversion
{                     //in degrees Celsius
                      //in temperature in degrees Kelvin
	double k = c + 273.15;
	return k;
}

int main()
{
	double c = 0;       //declare the input variable
	cin >> c;           //enter the temperature
	double k = ctok(c); //convert the temperature
	cout << k << '\n';  //output the result
	keep_window_open();
}