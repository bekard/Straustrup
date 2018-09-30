#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

int main() {

	vector<string> words;
	vector<string> modes;
	vector<int> modes_cnt;
	string word = " ";
	string mode = " ";
	int mode_cnt = 1;
	bool is_first = true;

	cout << "I will find modes among the strings that you enter." << endl;
	cout << "Please enter the strings: " << endl;

	while (cin >> word) words.push_back(word);

	sort(words.begin(), words.end());

	// the first and last words in the vector
	string first = words[0];
	string last = words[words.size() - 1];


	// entering modes and the number of their repetitions
	// in the corresponding vectors
	for (int i = 0; i < words.size(); ++i) {
		if (is_first) {
			mode = words[i];
			is_first = false;
		}
		else if (words[i] == words[i - 1]) {
			mode = words[i];
			++mode_cnt;
		}
		else {
			modes.push_back(mode);
			modes_cnt.push_back(mode_cnt);
			mode_cnt = 1;
			mode = words[i];
		}
	}
	// entering the last pair into vectors
	modes.push_back(mode);
	modes_cnt.push_back(mode_cnt);
	is_first = true;

	// the variable for maximum repeat of mode
	int mode_cnt_max = 0;

	// searching for maximum repeat
	for (int p = 0; p < modes_cnt.size(); ++p) {
		if (is_first) {
			mode_cnt_max = modes_cnt[p];
			is_first = false;
		}
		else if (modes_cnt[p] > mode_cnt_max)
			mode_cnt_max = modes_cnt[p];
	}

	// output of results
	cout << "The first string is " << first << endl;
	cout << "The last string is " << last << endl;
	for (int a = 0; a < modes_cnt.size(); ++a) {
		if (modes_cnt[a] == mode_cnt_max) {
			cout << "The mode is sting " << modes[a]
				<< " and it occurs " << modes_cnt[a] << " times." << endl;
		}
	}

	return 0;
}