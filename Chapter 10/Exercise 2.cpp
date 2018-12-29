#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

struct Reading {
	int hour;
	double temperature;
	char t_unit;
	Reading(int h, double t, char tu) :hour{ h }, temperature{ t }, t_unit{ tu }{}
		Reading() :hour{ 0 }, temperature{ 0 }, t_unit{ 'f' }{}
};

void fill_vector(vector<Reading>& v) {
	v.push_back(Reading(0, 20, 'f'));
	v.push_back(Reading(1, 18, 'c'));
	v.push_back(Reading(2, 17, 'f'));
	v.push_back(Reading(3, 16, 'f'));
	v.push_back(Reading(4, 15, 'c'));
	v.push_back(Reading(5, 14, 'f'));
	v.push_back(Reading(6, 14, 'c'));
	v.push_back(Reading(7, 15, 'c'));
	v.push_back(Reading(8, 16, 'f'));
	v.push_back(Reading(9, 18, 'c'));
	v.push_back(Reading(10, 20, 'c'));
	v.push_back(Reading(11, 21, 'c'));
	v.push_back(Reading(12, 22, 'f'));
	v.push_back(Reading(13, 23, 'c'));
	v.push_back(Reading(14, 24, 'f'));
	v.push_back(Reading(15, 19, 'f'));
	v.push_back(Reading(16, 18, 'c'));
	v.push_back(Reading(17, 20, 'c'));
	v.push_back(Reading(18, 21, 'f'));
	v.push_back(Reading(19, 22, 'c'));
	v.push_back(Reading(20, 25, 'f'));
	v.push_back(Reading(24, 58, 'c'));
	v.push_back(Reading(0, 87, 'f'));
	v.push_back(Reading(2, 89, 'c'));
	v.push_back(Reading(3, 150, 'f'));
	v.push_back(Reading(4, 428, 'c'));
	v.push_back(Reading(5, 26, 'f'));
	v.push_back(Reading(6, 0, 'f'));
	v.push_back(Reading(7, 2, 'c'));
	v.push_back(Reading(8, 89, 'c'));
	v.push_back(Reading(9, 120, 'c'));
	v.push_back(Reading(10, -1, 'f'));
	v.push_back(Reading(11, 2.3, 'c'));
	v.push_back(Reading(12, 20.5, 'f'));
	v.push_back(Reading(13, 40.85,'c'));
	v.push_back(Reading(14, -0.5,'c'));
	v.push_back(Reading(15, 1.11, 'f'));
	v.push_back(Reading(16, 0.35, 'f'));
	v.push_back(Reading(17, 170,'c'));
	v.push_back(Reading(18, 50,'c'));
	v.push_back(Reading(19, 21, 'f'));
	v.push_back(Reading(20, 23,'c'));
	v.push_back(Reading(21, 0, 'f'));
	v.push_back(Reading(22, -1,'c'));
	v.push_back(Reading(23, 55.1, 'f'));
	v.push_back(Reading(24, 12, 'f'));
	v.push_back(Reading(1, -15,'c'));
	v.push_back(Reading(2, 103, 'f'));
	v.push_back(Reading(3, 70, 'c'));
	v.push_back(Reading(4, 25, 'c'));
}

void fill_file(const vector<Reading>& temps) {
	cout << "enter the name of output file: ";
	string oname;
	cin >> oname;
	ofstream ost{ oname };
	if (!ost) error("impossible to open the file ", oname);

	for (int x = 0; x < temps.size(); ++x)
		ost << '(' << temps[x].hour << ','
		<< temps[x].temperature << temps[x].t_unit << ")\n";
}

int main()
{
	// create and fill vector with hours and temperatures
	vector<Reading>temps;
	fill_vector(temps);

	// add data to the file
	fill_file(temps);

	keep_window_open();
	return 0;
}