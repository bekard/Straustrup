#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <algorithm>

void input(std::ofstream& ofs)
{
	for (std::string line; std::getline(std::cin, line);)
		std::cout << line << '\n';
}

void fill_file(const std::string& fname)
{
	std::ofstream ofs{ fname };
	if (!ofs) std::cerr << "can't open the input file " << fname;

	std::cout << "please enter the text:\n";

	for (std::string line; std::getline(std::cin, line);) // line == "", and it goes to file, why!?
		if(line != "") ofs << line << '\n';
}

void reverse_string(std::string& s)
{
	for (int x = 0, y = s.size() - 1; x < y; ++x, --y) {
		char temp = s[x];
		s[x] = s[y];
		s[y] = temp;
	}
}

void reverse_file(const std::string& f)
{
	std::ifstream ifs{ f };
	if (!ifs) std::cerr << "can't open the output file " << f;

	std::vector<std::string> fstrings;
	for (std::string line; std::getline(ifs, line);) {
		reverse_string(line);
		fstrings.push_back(line);
	}

	std::ofstream ofs{ f };
	if (!ofs) std::cerr << "can't open the input file " << f;

	for (int x = 0; x < fstrings.size(); ++x)
		ofs << fstrings[x] << '\n';
}

void print_file(const std::string& f)
{
	std::ifstream ifs{ f };
	if (!ifs) std::cerr << "can't open the output file " << f;

	for (std::string line; std::getline(ifs, line);)
		std::cout << line << '\n';
}

int main()
try
{
	std::cout << "please enter the name of output file:\n";
	std::string fname;
	std::cin >> fname;
	
	fill_file(fname);
	reverse_file(fname);
	std::cout << "reversed:\n";
	print_file(fname);

	return 0;
}

catch (std::exception& e) {
	std::cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	std::cerr << "Oops: unknown exception!\n";
	return 2;
}