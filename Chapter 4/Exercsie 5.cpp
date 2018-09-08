#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"
int main()
{
	// Variables initialization
	double a = 0; // first number
	double b = 0; // second number
	char c;    // sign

			   // Enter the values 
	cin >> a >> b >> c;

	// sum +
	if (c == '+')
		cout << "Sum of 'a' and 'b' is " << a + b << '\n';

	// difference
	else if (c == '-')
		cout << "Difference between " << a << " and "
		<< b << " is " << a - b;
	// multiplication *
	else if (c == '*')
		cout << a << " multiply on " << b << " equally "
		<< a * b;

	// division /
	else if (c == '/')
		cout << "Quotien between " << a << " and " << b
		<< " equally " << a / b;

	else
		cout << "I don't know.";

return 0;
}