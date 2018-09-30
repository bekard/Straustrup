#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

int main() {

	double a = 0;
	double b = 0;
	double c = 0;
	double x1 = 0;
	double x2 = 0;

	// greeting
	cout << "******************************************************" << endl;
	cout << "*  This programm will help you the square equation.  *" << endl;
	cout << "******************************************************" << endl;
	cout << " The equation looks like this: ax^2 + bx + c." << endl;

	// the input variables
	cout << " Please enter the 'a': ";
	cin >> a;
	cout << " Please enter the 'b': ";
	cin >> b;
	cout << " Please enter the 'c': ";
	cin >> c;

	double D = b * b - 4 * a * c;
	if (D > 0) {
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		cout << " The roots of equation: " << endl;
		cout << " x1 = " << x1 << endl;
		cout << " x2 = " << x2 << endl;
	}
	else if (D < 0)
		cout << "Error, the equation has no roots!";
	else {
		x1 = -b / (2 * a);
		x2 = x1;
		cout << " The equation has one root: " << endl;
		cout << " x = " << x1 << endl;
	}

	return 0;
}