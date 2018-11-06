#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

/*
exercise 9
*/

int result;
int counter = 0;

char get_symbol() {
	char ch;
	cin >> ch;

	switch (ch) {

	case '1': case '2': case '3': case '4': case '5': case '=':
	case '6': case '7': case '8': case '9': case '0': case 'q':
		return ch;

	default:
		error("Was entered not a number: ", ch);
		break;
	}
}

void get_result(int x) {
	if (counter == 1) result = x;
	else result = result * 10 + x;
}

void output_result(int x) {
	if (counter == 1) cout << result << " - " << result << " units.\n";
	if (counter == 2) cout << result << " - " << result / 10 << " dozen, " << result % 10 << " units.\n";
	if (counter == 3) cout << result << " - " << result / 100 << " hundred, " << result / 10 % 10 << " dozen, " << result % 10 << " units.\n";;
	if (counter == 4) cout << result << " - " << result / 1000 << " thousand, " << result / 100 % 10 << " hundred, " << result / 10 % 10 << " dozen, " << result % 10 << " units.\n";
	if (counter >= 5) error("Number must contain 1 - 4 digits!");
	result = 0;
	counter = 0;
}

int main()
try
{
	cout << "Enter number(1 - 4 digits)\n"
		<< "1) For exit enter q\n"
		<< "2) To print result enter =\n";
	while (cin) {
		char symb = get_symbol();

		switch (symb) {
		case 'q':
			cout << "bye!";
			return 1;

		case '=':
			output_result(result);
			break;

		default:
			int num = symb - '0';      // to get a number
			++counter;
			get_result(num);
			break;
		}
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