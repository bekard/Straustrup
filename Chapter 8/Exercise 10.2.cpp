#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

// version 10.2 added a function for an every operation.

int max(vector<int>v) {
	return v[v.size() - 1];
}

int min(vector<int>v) {
	return v[0];
}

int middle(vector<int>v) {
	int mid;
	int sum = 0;
	for (int x = 0; x < v.size(); ++x)
		sum += v[x];
	mid = sum / v.size();
	return mid;
}

int median(vector<int>v) {
	int medi;
	if (v.size() % 2 == 0)
		medi = (v[v.size() / 2] + v[v.size() / 2 + 1]) / 2;
	else medi = v[v.size() / 2 + 1];
	return medi;
}

void find(vector<int>v) {     // 1 2 3 4 5 6 7 8 9 10
	sort(v.begin(), v.end()); //{-31, -5, -1, 4, 7, 9, 12, 82, 100}

	cout << "Max = " << max(v) << '\n';
	cout << "Min = " << min(v) << '\n';
	cout << "Average = " << middle(v) << '\n';
	cout << "Median = " << median(v) << '\n';
}

int main()
try
{
	vector<int>Numbers; //{12, -5, 7, 82, 4, 100, -1, 26, -31, 9}
	Numbers.push_back(12);
	Numbers.push_back(-5);
	Numbers.push_back(7);
	Numbers.push_back(82);
	Numbers.push_back(4);
	Numbers.push_back(100);
	Numbers.push_back(-1);
	Numbers.push_back(26);
	Numbers.push_back(-31);
	Numbers.push_back(9);

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