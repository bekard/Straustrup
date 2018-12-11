#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

// exercise 13, add denominator of two numbers

// =====================================================================

class Rational {
public:
	// constructors
	Rational(int n, int d);
	Rational();

	// helper functions:
	int get_numer() const { return numerator; }
	int get_denum() const { return denominator; }
	Rational& operator=(const Rational& y);
	double division();

private:
	int numerator;
	int denominator;
};

// operators
Rational operator+(Rational x, Rational y);
Rational operator-(Rational x, Rational y);
Rational operator*(Rational x, Rational y);
Rational operator/(Rational x, Rational y);
bool operator==(const Rational& x, const Rational& y);
bool operator!=(const Rational& x, const Rational& y);
ostream& operator<<(ostream& os, const Rational& x);
istream& operator>>(istream& is, Rational& x);

// =====================================================================
// Constructors
Rational::Rational(int n, int d)
	:numerator{ n }, denominator{ d }
{
	if (denominator == 0) error("denominator can't be 0");
}

Rational::Rational()
	: numerator{ 0 }, denominator{ 0 }
{
}

// ---------------------------------------------------------------------
// Helper functions:
double Rational::division()
{
	return numerator / denominator;
}

// ---------------------------------------------------------------------
// Operators

Rational operator+(Rational x, Rational y)
{
	Rational z{
		x.get_numer()*y.get_denum() + y.get_numer()*x.get_denum(),
		x.get_denum()*y.get_denum()
	}; return z;
}

Rational operator-(Rational x, Rational y)
{
	Rational z{
		x.get_numer()*y.get_denum() - y.get_numer()*x.get_denum(),
		x.get_denum()*y.get_denum()
	}; return z;
}

Rational operator*(Rational x, Rational y)
{
	Rational z{
		x.get_numer()*y.get_numer(),
		x.get_denum()*y.get_denum()
	}; return z;
}

Rational operator/(Rational x, Rational y)
{
	Rational z{
		x.get_numer()*y.get_denum(),
		x.get_denum()*y.get_numer()
	}; return z;
}

Rational& Rational::operator=(const Rational& x)
{
	numerator = x.get_numer();
	denominator = x.get_denum();
	return *this;
}

bool operator==(const Rational& x, const Rational& y)
{
	return x.get_numer() == y.get_numer()
		&& x.get_denum() == y.get_denum();
}

bool operator!=(const Rational& x, const Rational& y)
{
	return !(x == y);
}

ostream& operator<<(ostream& os, const Rational& x)
{
	return os << x.get_numer() << '/' << x.get_denum();
}

istream& operator>>(istream& is, Rational& x)
{
	int n, d;
	is >> n >> d;
	if (!is) return is;
	x = Rational(n, d);
	return is;
}

// =====================================================================

int main()
try
{
	Rational x{ 2,5 };
	Rational y{ 1,3 };

	cout << x << " + " << y << " = " << x + y << endl;
	cout << x << " - " << y << " = " << x - y << endl;
	cout << x << " * " << y << " = " << x * y << endl;
	cout << x << " / " << y << " = " << x / y << endl;

	cin >> x;
	cout << x << " + " << y << " = " << x + y << endl;

	keep_window_open();
	return 0;
}

catch (runtime_error e) {
	cout << e.what() << '\n';
	keep_window_open("~");	
}
catch (...) {
	cout << "exiting\n";
	keep_window_open("~");
}