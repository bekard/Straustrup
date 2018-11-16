#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

void print(vector<int>v) {
	cout << "reverse: ";
	for (int a = 0; a < v.size(); ++a) {
		if (a != v.size() - 1)  cout << v[a] << ", ";
		else cout << v[a] << '\n';
	}
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
	cout << "please, enter numbers. to abort the input, enter 000.\n";
	vector<int>numbers;
	for (int n; cin >> n && n != 000; numbers.push_back(n));

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