#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

void find(vector<int>v) {     // 1 2 3 4 5 6 7 8 9 10
	sort(v.begin(), v.end()); //{-31, -5, -1, 4, 7, 9, 12, 82, 100}
	int min = v[0];
	int max = v[v.size() - 1];
	int sum = 0;
	int middle;
	int median;

	for (int x = 0; x < v.size(); ++x)
		sum += v[x];

	middle = sum / v.size();

	if (v.size() % 2 == 0)
		median = (v[v.size() / 2] + v[v.size() / 2 + 1]) / 2;
	else median = v[v.size() / 2 + 1];
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