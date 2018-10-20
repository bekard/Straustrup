#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

int main()
try
{
	int N = 0; // the number of Fibonacci numbers
	int FibNum = 0;
	char answer = ' ';
	vector <int> Fibs; // Fibonacci numbers will be stored here

	// add two fisrt numbers in vector
	Fibs.push_back(0);
	Fibs.push_back(1);

	cout << "Hi! Do you want to see the largest ";
	cout << "Fibonacci number what fit in an int?\n";
	cout << "(To answer please press Y - for YES and N - for NO)\n";
	cin >> answer;

	switch (answer) {

	case 'Y':
		while (Fibs[Fibs.size() - 1] + Fibs[Fibs.size() - 2] >= Fibs[Fibs.size() - 1])
			Fibs.push_back(Fibs[Fibs.size() - 1] + Fibs[Fibs.size() - 2]);
		cout << "The largest Fibonacci number to fit an 'int' is " << Fibs[Fibs.size() - 1] << endl;
		break;
		
	case 'N':
		cout << "So...How many Fibonacci numbers do you want to see?\n";
		cin >> N;
		if (N < 1) throw 2;

		for (int a = 2; a < N; ++a)
			Fibs.push_back(Fibs[a - 2] + Fibs[a - 1]);

		for (int b = 0; b < N; ++b)
			cout << b << ")\t" << Fibs[b] << endl;
		break;

	default:
		throw 1;
		break;
	}

	/*
	if (answer != 'Y' && answer != 'N') throw 1;


	cout << "How many Fibonacci "
		<< "numbers do you want to see?\n";
	cin >> N;
	if (N < 1) throw 2;

	for (int a = 2; a < N; ++a)
		FibNumbers.push_back(FibNumbers[a - 2] + FibNumbers[a - 1]);

	for (int b = 0; b < N; ++b)
		cout << b + 1 << ")\t" << FibNumbers[b] << endl;
    */

	keep_window_open();
	return 0;
	
}

catch (int x) {
	if (x == 1) cerr << "Answer must be 'Y' or 'N'.\n";
	if (x == 2) cerr << "N must be more than zero!\n";
	cerr << "Error #" << x << endl;
	keep_window_open();
	return 2;
}
catch (...) {
	cerr << "Error!\n";
	keep_window_open();
	return 1;
}