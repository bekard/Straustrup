#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

vector<int> primes;

bool is_prime(int x)
{
	for (int p = 0; p < primes.size(); ++p)
		if (x % primes[p] == 0) return false;
	return true;
}

int main()
{
	primes.push_back(2);

	for (int i = 3; i < 100; ++i)
		if (is_prime(i)) primes.push_back(i);

	cout << "Primes: \n";
	for (int p = 0; p < primes.size(); ++p)
		cout << primes[p] << endl;

	return 0;
}
