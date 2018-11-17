#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

int find_max(vector<int>v);

void maxv(){
	vector<int>v;
	const int quit = 9999;

	cout << "fill the vector with integers (for exit enter " << quit << ")\n";
	for (int n; cin >> n && n != quit;)
		v.push_back(n);

	cout << "the max number is: " << find_max(v) << '\n';
}

int find_max(vector<int>v) {
	sort(v.begin(), v.end());
	 return v[v.size()-1];
}

int main()
try
{
	maxv();
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