#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

struct Date {
	int y;
	int m;
	int d;
};

ostream& operator<< (ostream& os, const Date& d)
{
	return os << '(' << d.y
		<< ',' << d.m
		<< ',' << d.d << ')' << '\n';
}

void init_day(Date& dd) {
	cout << "Enter the date (year, month, day): ";

	int y, m, d;
	cin >> y >> m >> d;
	
	if (y < 1800 || y > 2018) error("year must be between 1800 < y < 2018");
	if (m < 1 || m > 12) error("month must be between 1 < m < 12");
	if (d < 1 || d > 31) error("day must be between 1 < d < 31");

	dd.y = y;
	dd.m = m;
	dd.d = d;
}

Date add_one_day(Date dd) {
	if (dd.d == 31) {
		++dd.m;
		dd.d = 1;
		if (dd.m == 13) {
			++dd.y;
			dd.m = 1;
		}
	}
	else ++dd.d;
	return dd;
}

int main()
try
{
	Date today;
	Date tomorrow;
	init_day(today);
	tomorrow = add_one_day(today);

	cout << "today is " << today;
	cout << "romorrow is " << tomorrow;

	keep_window_open();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}