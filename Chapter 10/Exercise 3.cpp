#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

struct Reading
{
	int hour;
	double temperature;
	Reading(int h, double t) :hour{ h }, temperature{ t }{}
	Reading() :hour{ 0 }, temperature{ 0 }{}
};

ostream& operator<<(ostream& os, const Reading& r)
{
	return os << '(' << r.hour << ',' << r.temperature << ')';
}

istream& operator>>(istream& is, Reading& r)
{
	int hour;
	double temperature;
	is >> hour >> temperature;
	if (!is) return is;
	r = Reading(hour, temperature);
	return is;
}

void fill_from_file(vector<Reading>& v)
{
	cout << "please enter the name of the input file: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname };
	if (!ist) error("Impossible to open the file ", iname);

	Reading r;
	while (ist >> r)
		v.push_back(r);
}

double count_average(const vector<Reading>& v)
{
	double sum = 0;
	for (int x = 0; x < v.size(); ++x)
		sum += v[x].temperature;

	return sum / v.size();
}

double count_median(const vector<Reading>& v)
{
	double res;
	vector<double>t;
	for (int n = 0; n < v.size(); ++n)
		t.push_back(v[n].temperature);

	sort(t.begin(), t.end());
	if (t.size() % 2 != 0) res = t[t.size() / 2];
	else res = (t[t.size() / 2] + t[t.size() / 2 - 1]) / 2;

	return res;
}

int main()
{
	vector<Reading>temps;
	fill_from_file(temps);
	cout << "average: " << count_average(temps) << '\n';
	cout << "median: " << count_median(temps) << '\n';

	keep_window_open();
	return 0;
}