#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

// exercise 7:
// quadratic equation ax^2 + bx + c = 0

int main()
try
{
	double a = 0;
	double b = 0;
	double c = 0;
	double x1 = 0;
	double x2 = 0;
	double D = 0;

	cout << "To solve the quadratic equation, enter the variables below:\n";
	cout << "Please enter 'a':";
	cin >> a;
	cout << "Please enter 'b':";
	cin >> b;
	cout << "Please enter 'c':";
	cin >> c;

	D = b * b - 4 * a * c;
	if (D < 0) throw 1;

	x1 = (-b + sqrt(D)) / (2 * a);
	x2 = (-b - sqrt(D)) / (2 * a);

	cout << "Answer:\n";
	if (x1 == x2) cout << "x = " << x1 << endl;
	else cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;

	keep_window_open();
	return 0;
}

catch (int x) {
	cerr << "Discriminant below zero! The equation has no solutions\n";
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Exception: Something goes wrong.\n";
	keep_window_open();
	return 2;
}