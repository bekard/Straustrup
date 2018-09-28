#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

vector<int> numbers;

int main()
{
	int max = 0;
	cout << "Please enter the max number: ";
	cin >> max;

	for (int a = 2; a <= max; ++a) 
		numbers.push_back(a);

	int size1 = 0;
	int size2 = 0;

	for (int p = 2; p * p <= max; ++p)
	{
		size1 = numbers.size();
		for (int n = size2; n <= size1 - 1; ++n)
			if (numbers[n] % p != 0 || numbers[n] == p) numbers.push_back(numbers[n]);
		size2 = size1;
	}

	cout << "The prime numbers between 1 and " << max << ":" << endl;
	for (int b = size2; b <= numbers.size() - 1; ++b)
		cout << " " << numbers[b] << endl;

	return 0;
}