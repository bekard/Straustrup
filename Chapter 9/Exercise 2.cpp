#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

class Name_pairs {
public:
	Name_pairs(vector<string>name, vector<double>age);
	Name_pairs();
	void read_names();
	void read_ages();
	void print();
	void sort_pairs();
private:
	vector<string>name{}; // vectors are empty
	vector<double>age{};
};

Name_pairs::Name_pairs()
	:name{ vector<string>{} }, age{ vector<double>{} }
{
}

Name_pairs::Name_pairs(vector<string>n, vector<double>a)
	: name{ n }, age{ a }
{
}

void Name_pairs::read_names()
{
	cout << "Enter names (for exit enter NoName).\n";
	string n;
	while (cin >> n && n != "NoName")
		name.push_back(n);
}

void Name_pairs::read_ages()
{
	cout << "For each name anter the age.\n";
	const double max_age = 122;
	const double min_age = 0;
	double a;

	for (int x = 0; x < name.size(); ++x) {
		cout << name[x] << " - ";
		cin >> a;
		if (a <= min_age || a > max_age) error("Invalid age");
		age.push_back(a);
	}
}

void Name_pairs::print()
{
	cout << "Name pairs:\n";
	for (int x = 0; x < name.size(); ++x)
		cout << name[x] << '\t' << age[x] << endl;
}

void Name_pairs::sort_pairs()
{
	cout << "Sort.\n";
	const vector<double>age_copy = age;
	const vector<string>name_copy = name;
	sort(name.begin(), name.end());
	
	for (int x = 0; x < name.size(); ++x) {
		for (int n = 0; n < name_copy.size(); ++n)
			if (name[x] == name_copy[n]) age[x] = age_copy[n];
	}
}

int main()
try
{
	Name_pairs pairs1;
	pairs1.read_names();
	pairs1.read_ages();
	pairs1.print();
	
	pairs1.sort_pairs();
	pairs1.print();

	keep_window_open();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}