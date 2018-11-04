#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

class Name_value {
public:
	string name;
	int score;
	Name_value(string st, int val)
		:name(st), score(val) { }
};

// вводится набор пар Имя Число;
// пары заносятся в вектор Name_values;
// прекратить ввод встретив NoName 0;
// убедиться, что каждое имя единственное и вывести сообщение об
// ошибке если имеется имя, введенное дважды;
// вывести пары на печать (имя - баллы) по одной в строке.

int main() 
try
{
	vector<Name_value> nv;
	string n = " ";
	int v = 0;

	cout << "Enter the pair (name score):\n";

	while (cin >> n >> v, n != "NoName") {
		for (int a = 0; a < nv.size(); ++a)
			if (n == nv[a].name) error("duplicate: ", n);
		nv.push_back(Name_value(n,v));
	}

	cout << "Results:\n";
	for (int b = 0; b < nv.size(); ++b)
		cout << nv[b].name << '\t' << nv[b].score << endl;

	keep_window_open();
}

catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}