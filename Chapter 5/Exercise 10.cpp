#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

int main()
try
{
	vector <double> numbAll;
	vector <double> numbDif;
	double N = 0;
	double number = 0;
	double sum = 0;

	// enther the amount of amount of digits to summ 
	cout << "Please enter the amount of digits to summ:\n";
	cin >> N;
	if (N < 1) throw 1;

	// enter the numbers in vector
	cout << "Now please enter the numbers:\n";
	while (cin >> number) numbAll.push_back(number);
	if (N > numbAll.size()) throw 2;

	// counts summ
	for (int a = 0; a < N; ++a)
		sum += numbAll[a];
	cout << "The summ = " << sum << endl;

	// counts the difference between adjacent numbers
	if (numbAll.size() <= 1) cout << "No adjacent numbers!\n";
	else {
		for (int x1 = 0, x2 = 1; x2 < numbAll.size(); ++x1, ++x2)
			numbDif.push_back(numbAll[x1] - numbAll[x2]);
		
		// the results output
		cout << "The differences between adjacent numbers:\n";
		for (int a = 0; a < numbDif.size(); ++a)
			cout << a + 1 << ") " << numbDif[a] << endl;
	}

	keep_window_open();
	return 0;
}
catch (int x) {
	if (x == 1) cerr << "The amount of digits must to be more than 0!\n";
	else if (x == 2) cerr << "The number of digits to add"
		<< "is greater than was entered!\n";
	keep_window_open();
	return 1;
}