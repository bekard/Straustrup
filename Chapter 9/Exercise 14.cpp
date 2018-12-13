#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

// ---class--------------------------------------------------------------

class Money {
public:
	Money();
	Money(long int m);

	// helper functions
	long int get_amount() const { return amount; };
private:
	long int amount;
};

// ---constructors-------------------------------------------------------

Money::Money(long int m) :amount{ m }
{
	if (amount < 0) error("money can't be negative");
}

Money::Money() :amount{0} {}

// ---operators----------------------------------------------------------

ostream& operator<<(ostream& os, const Money& m)
{
	double d = m.get_amount();
	return os << d / 100 + (m.get_amount() % 100) / 100;
}

istream& operator>>(istream& is, Money& mm)
{
	double d;
	is >> d;
	const int dd = d;
	const double junior = ((d - dd) + 0.005) * 100;
	const int senior = dd*100;
	long int a;
	if (!is) return is;
	
	a = senior + junior;
	mm = Money(a);
	return is;
}

// ---main---------------------------------------------------------------

int main()
try
{
	Money m;
	cin >> m;
	cout << m.get_amount() << endl;
	keep_window_open();
}

catch (runtime_error e) {
	cout << e.what() << '\n';
	keep_window_open("~");	
}
catch (...) {
	cout << "exiting\n";
	keep_window_open("~");
}