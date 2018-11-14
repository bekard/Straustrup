#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

void print(const vector<int>& v, const string& name) {
	for (int a = 0; a < v.size(); ++a) {
		cout << name << "(" << a << "): " << v[a] << '\n';
	}
}

int main()
try
{
	string name = "vtest";
	vector<int>vtest;
	vtest.push_back(1);
	vtest.push_back(2);
	vtest.push_back(4);
	vtest.push_back(-3);

	print(vtest, name);
	keep_window_open();
}

catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
	cout << e.what() << '\n';
	keep_window_open("~");	// For some Windows(tm) setups
}
catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
	cout << "exiting\n";
	keep_window_open("~");	// For some Windows(tm) setups
}