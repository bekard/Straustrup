#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

void print(const vector<int>& v, const string& name) {
	for (int a = 0; a < v.size(); ++a) {
		cout << name << "(" << a+1 << "): " << v[a] << '\n';
	}
}

void fibonacci(int x, int y, vector<int>& v, int n) {
	v.push_back(x);
	v.push_back(y);

	if (x > y) error("the first integer must be less than the second");
	if (n <= 0) error("'n' must be more than zero");

	for (int a = 2; a < n; ++a)
		v.push_back(v[a - 2] + v[a - 1]);
}

int main()
try
{
	int val1 = 0;
	int val2 = 0;
	int n = 0;

	cout << "Please, enter 2 integers from which the sequence will"
		<< "start and then the amount of Fibonacci numbers.\n"
		<< "For exit enter - q.\n";

	while (cin >> val1 >> val2 >> n) {
		vector<int>fib;
		fibonacci(val1, val2, fib, n);

		print(fib, "fib");
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
