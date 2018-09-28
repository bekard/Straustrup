#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

vector <int> primes;

// number is prime?!
bool is_prime(int b) {
	for (int p = 0; p < primes.size(); ++p)
		if (b % primes[p] == 0) return false;
		else return true;
}

int main()

{
	// amount of the primes
	int n = 0; 
    primes.push_back(2);

	cout << "Please enter the amount of primes: ";
	cin >> n;
	for (int a = 3; primes.size() < n; ++ a) 
		if (is_prime(a)) primes.push_back(a);

	// output
	cout << n << " primes will be lower..." << endl;
	for (int i = 0; i < primes.size(); ++i)
		cout << primes[i] << endl;

	return 0;
}