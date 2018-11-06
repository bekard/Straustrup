#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

int bulls;
int cows;
char letter;

char first;
char second;
char third;
char fourth;

vector<char>game;

void fill_game() {
	game.push_back('q');
	game.push_back('w');
	game.push_back('e');
	game.push_back('r');
}

void get_let(int c) {
	char ch;
	cin >> ch;


	switch (ch) {
	case 'q': case 'w': case 'e': case 'r': case 't': case 'y':
	case 'u': case 'i': case 'o': case 'p': case 'a': case 's':
	case 'd': case 'f': case 'g': case 'h': case 'j': case 'k':
	case 'l': case 'z': case 'x': case 'c': case 'v': case 'b':
	case 'n': case 'm':
		if (c == 1) first = ch;
		if (c == 2) second = ch;
		if (c == 3) third = ch;
		if (c == 4) fourth = ch;
		break;

	case ' ':


	default:
		error("Not letter was entered: ", ch);
		break;
	}
}

bool are_unique() {
	vector<char> v;
	v.push_back(first);
	v.push_back(second);
	v.push_back(third);
	v.push_back(fourth);

	sort(v.begin(), v.end());

	for (int a = 1; a < v.size(); ++a)
		if (v[a] == v[a - 1]) return false;
	return true;
}

void check() {
	vector<char> v;
	v.push_back(first);
	v.push_back(second);
	v.push_back(third);
	v.push_back(fourth);;

	for (int a = 0; a < v.size(); ++a) {
		if (v[a] != game[a]) {
			for (int b = 0; b < game.size(); ++b)
				if (v[a] == game[b]) ++cows;
		}
		else ++bulls;
	}
}

int main()
try
{
	fill_game();

	cout << "Game has been started! Good luck!\n";
	while (bulls != 4) {
		bulls = 0;
		cows = 0;
		first = ' ';
		second = ' ';
		third = ' ';
		fourth = ' ';
		int count = 0;

		while (cin) {
			++count;
			if (count == 5) break;
			get_let(count);
		}

		if (are_unique() == true) check();
		else error("Letters must be uniaue!");

		if (bulls != 4) cout << bulls << " bulls / " << cows << " cows. Try one more time!\n";
		else cout << "Congratulations, you win!\n";
	}
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