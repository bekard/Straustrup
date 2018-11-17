#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

void print_until_s(vector<string>v,const string& quit) {
	for (int x = 0; x < v.size(); ++x) {
		if (v[x] == quit) return;
		cout << v[x] << '\n';
	}
}

void print_until_ss(vector<string>v,const string& quit) {
	cout << "----------------------------------------------\n";
	bool first_time = true;
	for (int x = 0; x < v.size(); ++x) {
		if (v[x] == quit) {
			if (first_time == true) first_time = false;
			else return;
		}
		cout << v[x] << '\n';
	}
}

int main()
try
{
	vector<string>w;
	w.push_back("hello");
	w.push_back("and");
	w.push_back("now");
	w.push_back("quit");
	w.push_back("hi");
	w.push_back("again!");
	w.push_back("quit");

	print_until_s(w, "quit");
	print_until_ss(w, "quit");
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