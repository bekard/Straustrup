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

vector<int> new_game() {
	vector<int> v(4);
	v[0] = randint(10);
	v[1] = randint(10);
	while (v[0] == v[1]) v[1] = randint(10);
	v[2] = randint(10);
	while (v[0] == v[2] || v[1] == v[2]) v[2] = randint(10);
	v[3] = randint(10);
	while (v[0] == v[3] || v[1] == v[3] || v[2] == v[3]) v[3] = randint(10);
	return v;
}

int main()
try {
	bool continuation = true;
	char answer = ' ';
	int seed = 0;
	int guess = 0;
	vector<int> solution(4);

	cout << "--- Bulls and cows ---\n"
		<< "To win you need to guess the number conceived by the game (it is four-digit and each digit in it is unique)\n"
		<< "1) You need to collect 4 bulls.\n"
		<< "2) Bull - it is the correct digit located on the right place\n"
		<< "3) Cow - it is the correct digit located on the wrong place\n"
		<< "4) Your input must be a four-digit number consisting of unique digits\n"
		<< "--- Good Luck! ---\n";

	while (continuation == true) {
		int bulls = 0;
		int cows = 0;
		cout << "Before the game started, please enter the seed (it's just an any number):\n";
		cin >> seed;
		srand(seed);
		solution = new_game();

		cout << "Please enter your guess:\n";

		while (bulls != 4) {
			cin >> guess;
			bulls = 0;
			cows = 0;
			vector<int> guess_in_vec = int_to_vector(guess);
			if (guess < 1000 || guess > 9999) throw 1;
			if (numbers_unique(guess_in_vec) == false) throw 2;

			for (int a = 0; a < guess_in_vec.size(); ++a)
				if (guess_in_vec[a] == solution[a]) {
					++bulls;
				}
				else {
					for (int b = 0; b < solution.size(); ++b)
						if (guess_in_vec[a] == solution[b]) ++cows;
				}
			cout << "You have " << bulls << " bulls and " << cows << " cows. ";
			if (bulls == 4) cout << "Congratulations, you win!\n";
			else cout << "Try one more time!\n";
		}
		cout << "Do you wanna play another game?(y - yes, n - no)\n";
		cin >> answer;
		if (answer != 'y' && answer != 'n') throw 3;
		if (answer == 'n') continuation = false;
	}

	cout << "Thanks for the game! Good bye!\n";
	keep_window_open();
	return 0;
}

catch (int x) {
	switch (x) {
	case 1:
		cerr << "The number must be between 1000 and 9000!\n";
		break;

	case 2:
		cerr << "All digits in the number must be unique!\n";
		break;

	case 3:
		cerr << "Answer must be 'y' or 'n'!\n";
		break;
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