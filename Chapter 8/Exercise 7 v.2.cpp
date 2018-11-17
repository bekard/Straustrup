#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

void fill_names(vector<string>&names) {
	cout << "enter names. for exit enter q.\n";

	string n;
	while (cin >> n && n != "q")
		names.push_back(n);
}

void print(vector<string>n, vector<int>a) {
	cout << "\nguys' ages:\n";
	for (int x = 0; x < n.size(); ++x)
		cout << n[x] << ", " << a[x] << '\n';
}

void fill_ages(const vector<string>& n, vector<int>& a) {
	int age;
	for (int x = 0; x < n.size(); ++x) {
		cout << n[x] << "'s age - ";
		cin >> age;
		a.push_back(age);
	}
}

void sort_ages(const vector<string>&norig, const vector<string>&ncopy, vector<int>&ages) {
	vector<int>ages_copy = ages;
	for (int x = 0; x < norig.size(); ++x) {
		for (int a = 0; a < ncopy.size(); ++a) {
			if (ncopy[a] == norig[x]) {
				ages[x] = ages_copy[a];
				break;
			}
		}
	}
}

int main()
try
{
	vector<int>ages;
	vector<string>names;

	fill_names(names);
	fill_ages(names, ages);
	vector<string>names_copy = names;


	print(names, ages);

	sort(names.begin(), names.end());
	sort_ages(names, names_copy, ages);

	print(names, ages);

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