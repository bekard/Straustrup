#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
public:
	Date(int y, Month m, int d);
	void add_day();
	int year() { return y; }
	Month month() { return m; }
	int day() { return d; }
private:
	int y;
	Month m;
	int d;
};

Date::Date(int yy, Month mm, int dd)
	:y{ yy }, m{ mm }, d{ dd }
{
	if (d < 1 || d > 31 || m < Month::jan || m > Month::dec) error("Invalid date");
}

void Date::add_day()
{
	++d;
	if (d > 31) error("Invalid date");
}

ostream& operator<< (ostream& os,Date& d)
{
	return os << '(' << d.year()
		<< ',' << int(d.month())
		<< ',' << d.day() << ')' << '\n';
}

int main()
try
{
	Date today{ 2009, Month::may, 20 };
	Date tomorrow = today;
	tomorrow.add_day();

	cout << "today is " << today;
	cout << "tomorrow is " << tomorrow;

	keep_window_open();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}