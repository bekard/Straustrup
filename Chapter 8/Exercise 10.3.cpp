#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

// version 10.2 added a function for an every operation.
// version 10.3 added enter numbers into the vector.

double max(vector<double>v) {
	return v[v.size() - 1];
}

double min(vector<double>v) {
	return v[0];
}

double middle(vector<double>v) {
	double mid;
	double sum = 0;
	for (int x = 0; x < v.size(); ++x)
		sum += v[x];
	mid = sum / v.size();
	return mid;
}

double median(vector<double>v) {
	double medi;
	const int vs = v.size();

	if (vs % 2 == 0) medi = (v[(vs-1) / 2] + v[(vs-1) / 2 + 1]) / 2;
	else medi = v[vs/ 2];

	return medi;
}

void find(vector<double>v) {

	cout << "Max = " << max(v) << '\n';
	cout << "Min = " << min(v) << '\n';
	cout << "Average = " << middle(v) << '\n';
	cout << "Median = " << median(v) << '\n';
}

void fill_vec(vector<double>&v) {
	cout << "fill the vector with numbers (for exit enter 9999)\n";
	double n;
	while (cin >> n && n != 9999)
		v.push_back(n);
	sort(v.begin(), v.end());
}

int main()
try
{
	vector<double>Numbers; 
	fill_vec(Numbers);
	find(Numbers);
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