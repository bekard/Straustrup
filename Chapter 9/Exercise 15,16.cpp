#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

// ---class--------------------------------------------------------------

class Money {
public:

	enum Currency {
		USD, RUR, EUR
	};

	Money();
	Money(long int m, Currency c);

	// helper functions
	long int get_amount() const { return amount; };
	Currency get_currency() const { return cc; };

	long int usd_to_eur() const;
	long int usd_to_rur() const;
	long int eur_to_usd() const;
	long int eur_to_rur() const;
	long int rur_to_usd() const;
	long int rur_to_eur() const;
	friend long int convert(const Money& a,const Money& b);
private:
	long int amount;
	Currency cc;
};
// functions
Money::Currency which_currency(string s);
void test();

// ---constructors-------------------------------------------------------

Money::Money(long int m, Currency c) :amount{ m }, cc{ c }
{
	if (amount < 0) error("money can't be negative");
}

Money::Money() : amount{ 0 }, cc{ Currency::USD } {}

// ---operators----------------------------------------------------------

ostream& operator<<(ostream& os, const Money& m)
{
	double d = m.get_amount();
	Money::Currency c = m.get_currency();
	string cur;

	if (c == Money::USD) cur = "USD";
	else if (c == Money::EUR) cur = "EUR";
	else if (c == Money::RUR) cur = "RUR";
	else error("invalic currency");

	return os << d / 100 + (m.get_amount() % 100) / 100 << " " << cur;
}

istream& operator>>(istream& is, Money& mm)
{
	double d;
	string c;
	is >> d >> c;
	const int dd = d;
	const double junior = ((d - dd) + 0.005) * 100;
	const int senior = dd * 100;
	long int a;
	if (!is) return is;

	a = senior + junior;
	mm = Money{ a, which_currency(c) };
	return is;
}

Money operator+(const Money& a, Money& b)
{
	Money sum{a.get_amount() + convert(a, b), a.get_currency()};
	return sum;
}

// ---functions----------------------------------------------------------

Money::Currency which_currency(string s)
{
	Money::Currency c;
	if (s == "USD" || s == "usd") c = Money::USD;
	else if (s == "EUR" || s == "eur") c = Money::EUR;
	else if (s == "RUR" || s == "rur") c = Money::RUR;
	else error("invalid currency");
	return c;
}

long int Money::usd_to_eur() const
{
	long int x = amount * 0.88 + 0.5;
	return x;
}

long int Money::usd_to_rur() const
{
	long int x = amount * 66.76 + 0.5;
	return x;
}

long int Money::eur_to_usd() const
{
	long int x = amount * 1.13 + 0.5;
	return x;
}

long int Money::eur_to_rur() const
{
	long int x = amount * 75.43 + 0.5;
	return x;
}

long int Money::rur_to_usd() const
{
	long int x = amount * 0.015 + 0.5;
	return x;
}
 
long int Money::rur_to_eur() const
{
	long int x = amount * 0.013 + 0.5;
	return x;
}

long int convert(const Money& a,const Money& b)
{
	long int x;
	if (b.get_currency() != a.get_currency()) {

		if (a.get_currency() == Money::EUR && b.get_currency() == Money::USD)
			x = b.usd_to_eur();
		if (a.get_currency() == Money::RUR && b.get_currency() == Money::USD)
			x = b.usd_to_rur();
		if (a.get_currency() == Money::USD && b.get_currency() == Money::EUR)
			x = b.eur_to_usd();
		if (a.get_currency() == Money::RUR && b.get_currency() == Money::EUR)
			x = b.eur_to_rur();
		if (a.get_currency() == Money::USD && b.get_currency() == Money::RUR)
			x = b.rur_to_usd();
		if (a.get_currency() == Money::EUR && b.get_currency() == Money::RUR)
			x = b.rur_to_eur();
	}
	return x;
}

void test()
{
	Money us{ 720, Money::USD };
	Money eu{ 888, Money::EUR };
	Money ru{ 56900, Money::RUR };

	cout << us << " + " << eu << " = " << us + eu << endl;
	cout << us << " + " << ru << " = " << us + ru << endl;
	cout << eu << " + " << us << " = " << eu + us << endl;
	cout << eu << " + " << ru << " = " << eu + ru << endl;
	cout << ru << " + " << us << " = " << ru + us << endl;
	cout << ru << " + " << eu << " = " << ru + eu << endl;
}

// ---main---------------------------------------------------------------

int main()
try
{
	Money a, b;
	cin >> a >> b;
	cout << a << " + " << b << " = " << a + b << endl;
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