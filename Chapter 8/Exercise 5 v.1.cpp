#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

void print(vector<int>v) {
	cout << "reverse:\n";
	for (int a = 0; a < v.size(); ++a)
		cout << v[a] << '\n';
}

void swap_in_new(const vector<int>& n) {
	vector<int>v;
	for (int a = (n.size() - 1); a >= 0; --a)
		v.push_back(n[a]);
	print(v);
}

void swap_in_old(vector<int>& n) {
	for (int a = 0, x = n.size() - 1; a <= x; ++a, --x)
		swap(n[a], n[x]);
	print(n);
}

int main()
try
{
	vector<int>numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);

	swap_in_old(numbers);

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