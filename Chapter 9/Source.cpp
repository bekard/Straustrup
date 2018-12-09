#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

bool leapyear(int y)
{
	if (y % 4) return false;
	if (y % 100 == 0 && y % 400) return false;
	return true;
}

int main()
try
{
	vector<int>years;
	years.push_back(0);
	years.push_back(2000);
	years.push_back(1900);
	years.push_back(2009);
	years.push_back(2400);
	years.push_back(1968);
	years.push_back(1950);
	years.push_back(2010);
	years.push_back(2012);
	years.push_back(2020);
	years.push_back(1968);

	for (int x = 0; x < years.size(); ++x) {
		cout << years[x] << " is";
		if (leapyear(years[x]) == false) cout << " not";
		cout << " a leapyear.\n";
	}

	cout << "Please enter a year:\n";

	int y;
	while (cin >> y) {
		cout << y << " is";
		if (leapyear(y) == false) cout << " not";
		cout << " a leapyear.\n";
	}

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