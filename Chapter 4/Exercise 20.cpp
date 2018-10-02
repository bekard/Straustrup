#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"
// exercise 20.

/*
Измените программу из упр. 1 9 так, чтобы при вводе имени она выводила
соответствующее количество баллов или сообщение "Имя не найдено".
*/

// chek for the reiteration of names
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
	bool finded = false;

	cout << "For quit programm enter: NoName 0" << endl;
	cout << "Now you need to fill vetors with values." << endl;
	cout << "Please enter the name and score:" << endl;

	// enter the values of names and scores
	while (cin >> name >> score, (name != "NoName" && score != 0)) {
		scores.push_back(score);
		names.push_back(name);
	}

	// the result output
	if (error(names)) {
		cout << "Error, 2 identical names detected!" << endl;
	}
	else {
		cout << "*****************************************************************" << endl;
		cout << "Please enter the name of person to get his score: ";
		cin >> name;
		for (int i = 0; i < names.size(); ++i) {
			if (name == names[i]) {
				score = scores[i];
				finded = true;
			}
		}
		if (finded == true) cout << name << "'s score is " << score << endl;
		else cout << "Sorry, name '" << name << "' is not found." << endl;
	}

	return 0;
}