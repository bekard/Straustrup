#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

const int not_a_reading = -7777;
const int not_a_month = -1;

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

//------------------------------------------------------------------------------

struct Day {
	vector<double> hour{ vector<double>(24,not_a_reading) };
};

struct Month {
	int month{ not_a_month };
	vector<Day> day{ 32 };
};

struct Year {
	int year;
	vector<Month> month{ 12 };
};

struct Reading {
	int day;
	int hour;
	double temperature;
};

//------------------------------------------------------------------------------

void end_of_loop(istream& ist, char term, const string& msg);
bool is_valid(const Reading& r);
int month_to_int(const string& m);
string int_to_month(const int& m);
void fill_months(vector<string>& m);
void print_day(ostream& ost, const Day& d, const int& day_num);
void print_month(ostream& ost, const Month& m);
void print_year(ostream& ost, const Year& y);

//------------------------------------------------------------------------------

void end_of_loop(istream& ist, char term, const string& msg)
{
	if (ist.fail()) {
		ist.clear();
		char ch;
		if (ist >> ch && ch == term) return;
		error(msg);
	}
}

bool is_valid(const Reading& r)
{
	if (r.day < 1 || 31 < r.day) return false;
	if (r.hour < 0 || 23 < r.hour) return false;
	if (r.temperature < implausible_min || implausible_max < r.temperature)
		return false;
	return true;
}

int month_to_int(const string& m)
{
	vector<string>months;
	fill_months(months);
	for (int x = 0; x < months.size(); ++x)
		if (m == months[x]) return x;
	return -1;
}

string int_to_month(const int& m)
{
	if (m < 0 || m > 11) error("bad month index");
	vector<string>months;
	fill_months(months);
	return months[m];
}

void fill_months(vector<string>& m)
{
	m.push_back("jan");
	m.push_back("feb");
	m.push_back("mar");
	m.push_back("apr");
	m.push_back("may");
	m.push_back("jun");
	m.push_back("jul");
	m.push_back("aug");
	m.push_back("sep");
	m.push_back("oct");
	m.push_back("nov");
	m.push_back("dec");
}

void print_day(ostream& ost, const Day& d, const int& day_num)
{
	for (int x = 0; x < d.hour.size(); ++x) {
		if (d.hour[x] != not_a_reading)
			ost << "\t\t" << day_num << '\t' << x << ":00"
			<< '\t' << d.hour[x] << "f\n";
	}
}

void print_month(ostream& ost, const Month& m)
{
	if (m.month == not_a_month) return;
	ost << '\t' << int_to_month(m.month) << '\n';
	for (int x = 1; x < m.day.size(); ++x)
		print_day(ost, m.day[x], x);
}

void print_year(ostream& ost, const Year& y)
{
	ost << y.year << ":\n";
	for (int x = 0; x < y.month.size(); ++x)
		print_month(ost, y.month[x]);
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Reading& r)
{
	char ch1;
	if (is >> ch1 && ch1 != '(') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	char ch2;
	int d;
	int h;
	double t;
	is >> d >> h >> t >> ch2;
	if (!is || ch2 != ')')
		error("bad recordong");
	r.day = d;
	r.hour = h;
	r.temperature = t;
	return is;
}

istream& operator>>(istream& is, Month& m)
{
	char ch = 0;
	if (is >> ch && ch != '{') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	string month_marker;
	string mm;
	is >> month_marker >> mm;
	if (!is || month_marker != "month")
		error("the wrong beginning of the Month");
	m.month = month_to_int(mm);

	Reading r;
	int duplicates = 0;
	int invalids = 0;
	for (Reading r; is >> r;) {
		if (is_valid(r)) {
			if (m.day[r.day].hour[r.hour] != not_a_reading)
				++duplicates;
			m.day[r.day].hour[r.hour] = r.temperature;
		}
		else
			++invalids;
	}
	if (invalids)
		error("incorrect data in Month, count: ", invalids);
	if (duplicates)
		error("repeated readings in Month, count: ", duplicates);
	end_of_loop(is, '}', "incorrect end of the Month");
	return is;
}

istream& operator>>(istream& is, Year& y)
{
	char ch;
	is >> ch;
	if (ch != '{') {
		is.unget();
		is.clear(ios::failbit);
		return is;
	}

	string year_marker;
	int yy;
	is >> year_marker >> yy;
	if (!is || year_marker != "year")
		error("incorrect begin of the Year");
	y.year = yy;
	while (true) {
		Month m;
		if (!(is >> m)) break;
		y.month[m.month] = m;
	}

	end_of_loop(is, '}', "incorrect end of the Year");
	return is;
}

//------------------------------------------------------------------------------

int main()
try
{
	cout << "enter the name of the input file\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname }; // in program from file
	if (!ifs) error("can't open the input file\n");

	ifs.exceptions(ifs.exceptions() | ios_base::badbit);

	cout << "enter the name of the output file\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname }; // out program in file
	if (!ofs) error("can't open the output file ", oname);

	vector<Year> ys;
	while (true) {
		Year y;
		if (!(ifs >> y)) break;
		ys.push_back(y);
	}
	cout << "Recorded " << ys.size() << " year records\n";

	for (int x = 0; x < ys.size(); ++x)
		print_year(ofs, ys[x]);

	keep_window_open();
}


catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	return 2;
}