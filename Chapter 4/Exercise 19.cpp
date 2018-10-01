#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"
// exercise 19.

// the chek for the reiteration of names
bool error(vector<string> w) {
	bool is_first = true;
	sort(w.begin(), w.end());
	for (int i = 1; i < w.size(); ++i) {
		if (w[i] == w[i - 1]) return true;
		else return false;
	}
}

int main() {

	int score = 0;
	string name = " ";
	vector<int> scores;
	vector<string> names;

	cout << "For quit programm enter: NoName 0" << endl;
	cout << "Now you need to fill vetors with values." << endl;
	cout << "Please enter the name and score:" << endl;
	
	// enter values of names and sñores
	while (cin >> name >> score, (name != "NoName" && score != 0)) {
		scores.push_back(score);
		names.push_back(name);
	}

	// result output
	if (error(names)) {
		cout << "Error, 2 identical names detected!" << endl;
	}
	else {
		cout << "**********************************" << endl;
		cout << "RESULTS:" << endl;
		cout << "Name" << '\t' << "Score" << endl;
		for (int n = 0; n < names.size(); ++n) {
			cout << names[n] << '\t' << scores[n] << endl;
		}
	}

	return 0;
}
