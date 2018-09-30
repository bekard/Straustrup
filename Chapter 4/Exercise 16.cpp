#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

int main() {

	vector<int>numbers;
	vector<int>modes;
	vector<int>modes_cnt;
	int n = 0;
	int mode = 0;
	int mode_cnt = 1;
	bool is_first = true;

	cout << "I will find modes among the numbers that you enter." << endl;
	cout << "Please enter the numbers: " << endl;

	while (cin >> n) numbers.push_back(n);

	sort(numbers.begin(), numbers.end());

	// entering mods and the number of their repetitions
	// in the corresponding vectors
	for (int i = 0; i < numbers.size(); ++i) {
		if (is_first) {
			mode = numbers[i];
			is_first = false;
		}
		else if (numbers[i] == numbers[i - 1]) {
			mode = numbers[i];
			++mode_cnt;
		}
		else {
			modes.push_back(mode);
			modes_cnt.push_back(mode_cnt);
			mode_cnt = 1;
			mode = numbers[i];
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
	for (int a = 0; a < modes_cnt.size(); ++a) {
		if (modes_cnt[a] == mode_cnt_max) {
			cout << "The mode is number " << modes[a]
				<< " and if occurs " << modes_cnt[a] << " times." << endl;
		}
	}

	return 0;
}