// exercise 14

#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

vector<int> mondays;
vector<int> tuesdays;
vector<int> wednesdays;
vector<int> thursdays;
vector<int> fridays;
vector<int> saturdays;
vector<int> sundays;
char answer = ' ';
bool continuation = true;
int rejected = 0;
string day = " ";
int number = 0;

void write_value(string a, int b) {
	
	if (a == "Monday" || a == "monday" || a == "Mon" || a == "mon")
		mondays.push_back(b);
	else if (a == "Tuesday" || a == "tuesday" || a == "Tue" || a == "tue")
		tuesdays.push_back(b);
	else if (a == "Wednesday" || a == "wednesday" || a == "Wed" || a == "wed")
		wednesdays.push_back(b);
	else if (a == "Thursday" || a == "thursday" || a == "Thu" || a == "thu")
		thursdays.push_back(b);
	else if (a == "Friday" || a == "friday" || a == "Fri" || a == "fri")
		fridays.push_back(b);
	else if (a == "Saturday" || a == "saturday" || a == "Sat" || a == "sat")
		saturdays.push_back(b);
	else if (a == "Sunday" || a == "sunday" || a == "Sun" || a == "sun")
		sundays.push_back(b);
	else if (a == "quit" || a == "q") continuation = false;
	else
		++rejected;
}

int get_sum(vector<int> v) {
	int sum = 0;
	for (int a = 0; a < v.size(); ++a)
		sum += v[a];
	return sum;
}

void print_day(string day, vector<int> v) {
	cout << day << " sum: " << get_sum(v) << endl;
}

void print_results() {
	cout << "--RESULTS--" << endl;
	print_day("Mondays", mondays);
	print_day("Tuesdays", tuesdays);
	print_day("Wednesdays", wednesdays);
	print_day("Thursdays", thursdays);
	print_day("Fridays", fridays);
	print_day("Saturdays", saturdays);
	print_day("Sundays", sundays);
	cout << "Rejected: " << rejected << endl;
}

int main()
try {
	while (continuation == true) {
		cout << "Please enter the day and the number (for exit enter 'q' and '0'):\n";
		cin >> day >> number;
		write_value(day, number);

/*		cout << "Do you want to add another value?(answer 'y' - for YES and 'n' - for NO)\n";
		cin >> answer;
		if (answer == 'y') continuation = true;
		else if (answer == 'n') continuation = false;
		else error("Answer must be 'y' or 'n'!");
*/
	}
	print_results();
	keep_window_open();
	return 0;
}

catch (...) {
	cerr << "Error!\n";
	keep_window_open();
	return 1;
}