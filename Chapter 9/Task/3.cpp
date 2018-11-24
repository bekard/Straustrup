#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

class Date {
	int y, m, d;
public:
	Date(int y, int m, int d);
	void add_day();
	int month() { return m; }
	int day() { return d; }
	int year() { return y; }
};

Date::Date(int yy, int mm, int dd)
	:y{ yy }, m{ mm }, d{ dd }
{
	if (d < 1 || d > 31 || m < 1 || m > 12) error("Invalid date");
}

void Date::add_day()
{
	++d;
	if (d > 31) {
		++m;
		d = 1;
		if (m > 12) {
			++y;
			m = 1;
		}
	}
}

ostream& operator<< (ostream& os,Date& d)
{
	return os << '(' << d.year()
		<< ',' << d.month()
		<< ',' << d.day() << ')' << '\n';
}

int main()
try
{
	Date today{ 2009, 13, -5 };
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