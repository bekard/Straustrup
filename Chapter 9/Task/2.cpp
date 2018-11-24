#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"



Date::Date(int yy, int mm, int dd)
	:y{ yy }, m{ mm }, d{ dd }
{
}

ostream& operator<< (ostream& os, const Date& d)
{
	return os << '(' << d.y
		<< ',' << d.m
		<< ',' << d.d << ')' << '\n';
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
	Date today{ 1963, 6, 19 };
	Date tomorrow = add_one_day(today);

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