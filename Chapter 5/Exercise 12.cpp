// exercise 12

#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

vector<int> int_to_vector(int a) {
	vector<int> v(4);
	v[0] = a / 1000;
	v[1] = a / 100 % 10;
	v[2] = a / 10 % 10;
	v[3] = a % 10;

	return v;
}

bool numbers_unique(vector<int> v) {
	bool unique = true;
	sort(v.begin(), v.end());
	for (int a = 1; a < v.size(); ++a)
		if (v[a] == v[a - 1]) unique = false;
	
	return unique;
}

int main()
try {
	int bulls = 0;
	int cows = 0;
	int guess = 0;
	vector<int> game(4);
	game[0] = 5;
	game[1] = 7;
	game[2] = 3;
	game[3] = 2;

	cout << "--- Bulls and cows ---\n"
		<< "To win you need to guess the number conceived by the game (it is four-digit and each digit in it is unique)\n"
		<< "1) You need to collect 4 bulls.\n"
		<< "2) Bull - it is the correct digit located on the right place\n"
		<< "3) Cow - it is the correct digit located on the wrong place\n"
		<< "4) Your input must be a four-digit number consisting of unique digits\n"
		<< "--- Good Luck! ---\n";

	while (bulls != 4) {
		cin >> guess;
		bulls = 0;
		cows = 0;
		vector<int> guess_in_vec = int_to_vector(guess);
		if (guess < 1000 || guess > 9999) throw 1;
		if (numbers_unique(guess_in_vec) == false) throw 2;

		for (int a = 0; a < guess_in_vec.size(); ++a)
			if (guess_in_vec[a] == game[a]) {
				++bulls;
			}
			else {
				for (int b = 0; b < game.size(); ++b)
					if (guess_in_vec[a] == game[b]) ++cows;
			}
		cout << "You have " << bulls << " bulls and " << cows << " cows. ";
		if (bulls != 4) cout  << "Try one more time!\n";
	}

	cout << "Congratulations, you win!\n";
	keep_window_open();
	return 0;
}

catch (int x) {
	switch (x) {

	case 1:
		cerr << "The number must be between 1000 and 9000!";
		break;
	case 2:
		cerr << "All digits in the number must be unique!";
	}

	cerr << "Error #" << x << endl;
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Error!\n";
	keep_window_open();
	return 2;
}