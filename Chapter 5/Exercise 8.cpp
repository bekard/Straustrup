#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

// exercise 8:

int main()
try
{
	vector <int> numbers;
	int sum = 0;
	int N = 0; // number of first digits to be summed

	cout << "Please enter the number of first digits to be summed: ";
	cin >> N;
	cout << "Please enter multiple integer values: " << endl;
	for (int a = 0; cin >> a;) 
		numbers.push_back(a);

	// if N is greater than the number of entered values,
	// an exception is thrown.
	if (N > numbers.size()) throw 1;

	for (int b = 0; b < N; ++b)
			sum += numbers[b];

	cout << "Summ of the first " << N << " numbers = " << sum << endl;

	system("pause");
	return 0;
}

// the output of error exception
catch (int x) {
	cerr << "The number of values requested"
		<< "is more than the number entered!" << endl;
	system("pause");
	return 1;
}