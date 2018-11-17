#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

void print(vector<string>v) {
	cout << "reverse:\n";
	for (int a = 0; a < v.size(); ++a) 
		cout << v[a] << '\n';
}

void swap_in_new(const vector<string>& n) {
	vector<string>v;
	for (int a = (n.size() - 1); a >= 0; --a)
		v.push_back(n[a]);
	print(v);
}

void swap_in_old(vector<string>& n) {
	for (int a = 0, x = n.size() - 1; a <= x; ++a, --x)
		swap(n[a], n[x]);
	print(n);
}

int main()
try
{
	cout << "please, enter strings. to abort the input, enter q.\n";
	vector<string>words;
	for (string n; cin >> n && n != "q"; words.push_back(n));

	swap_in_old(words);

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