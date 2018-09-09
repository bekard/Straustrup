#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"
int main()
{   // Инициализация вектора
	vector<string> numbers;
	numbers.push_back("zero");
	numbers.push_back("one");
	numbers.push_back("two");
	numbers.push_back("three");
	numbers.push_back("four");
	numbers.push_back("five");
	numbers.push_back("six");
	numbers.push_back("seven");
	numbers.push_back("eight");
	numbers.push_back("nine");

	/*	
	else if (cin >> w_number) {
	while (w_number != numbers[counter] && counter <= 10)
		++counter;
	cout << counter;
	*/

	// Инициализация переменных
	int counter = 0;
	string w_number = "";

	while (w_number != numbers[counter] && counter <= 10)
		++counter;
	if (w_number == numbers[counter])
		cout << counter;
	else if (w_number == "0")
		cout << "zero";
	else if (w_number == "1")
		cout << "one";
	else if (w_number == "2")
		cout << "two";
	else if (w_number == "3")
		cout << "three";
	else if (w_number == "4")
		cout << "four";
	else if (w_number == "5")
		cout << "five";
	else if (w_number == "6")
		cout << "six";
	else if (w_number == "7")
		cout << "seven";
	else if (w_number == "8")
		cout << "eight";
	else if (w_number == "9")
		cout << "nine";
	else
		cout << "Error!";

	return 0;
}