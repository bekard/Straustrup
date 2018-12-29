#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

void fill_vector(vector<int>& v)
{
	v.push_back(1);
	v.push_back(4);
	v.push_back(6);
	v.push_back(10);
	v.push_back(-1);
	v.push_back(32);
	v.push_back(7);
}

void add_to_file(const vector<int>& v, string oname)
{
	ofstream ost{ oname };
	if (!ost) error("unable to open output file", oname);
	for (int p = 0; p < v.size(); ++p)
		ost << v[p] << ' ';
}

int count_sum_iv(const vector<int>& v)
{
	int sum = 0;
	for (int x = 0; x < v.size(); ++x)
		sum += v[x];
	return sum;
}

int count_sum_if(string iname)
{
	ifstream ist{ iname };
	if (!ist) error("unable to open input file", iname);
	int x, sum = 0;
	while (ist >> x)
		sum += x;

	return sum;
}

void print_vector(vector<int>& v, string name)
{
	cout << name << '\n';
	for (int p = 0; p < v.size(); ++p)
		cout << v[p] << '\n';
}


 void check_sums(const int& s1, const int& s2)
{
	 if (s1 == s2) cout << s1 << " = " << s2 << '\n';
	 else error("sums are not the same");
}


int main()
{   
	vector<int>numbers;
	fill_vector(numbers);
	add_to_file(numbers, "mydata.txt");

	check_sums(count_sum_iv(numbers), count_sum_if("mydata.txt"));

	keep_window_open();
	return 0;
}