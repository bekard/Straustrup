#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <algorithm>

void fill_file(const std::string& oname)
{
	std::ofstream ofs{ oname };
	if (!ofs) std::cerr << "error: can't open the output file " << oname;

	std::cout << "enter some lines:\n";

	for (std::string s; std::getline(std::cin, s);)
		if (s != "") ofs << s << '\n';

	std::cout << "strings added to file\n";
}

void write_categories(const std::string& oname, const std::string& iname)
{
	std::vector<int>v(11, 0);
	std::ifstream ifs{ iname };
	if (!ifs) std::cerr << "error: can't open the input file " << iname;

	for (char ch; ifs.get(ch);) {
		if (isspace(ch)) ++v[0];
		if (isalpha(ch)) ++v[1];
		if (isdigit(ch)) ++v[2];
		if (isxdigit(ch)) ++v[3];
		if (isupper(ch)) ++v[4];
		if (islower(ch)) ++v[5];
		if (isalnum(ch)) ++v[6];
		if (iscntrl(ch)) ++v[7];
		if (ispunct(ch)) ++v[8];
		if (isprint(ch)) ++v[9];
		if (isgraph(ch)) ++v[10];
	}


	std::ofstream ofs{ oname };
	if (!ofs) std::cerr << "error: can't open the output file " << oname;

	ofs << "is space\t" << v[0] << '\n';
	ofs << "is alpha\t" << v[1] << '\n';
	ofs << "is digit\t" << v[2] << '\n';
	ofs << "is xdigit\t" << v[3] << '\n';
	ofs << "is upper\t" << v[4] << '\n';
	ofs << "is lower\t" << v[5] << '\n';
	ofs << "is alnum\t" << v[6] << '\n';
	ofs << "is cntrl\t" << v[7] << '\n';
	ofs << "is punct\t" << v[8] << '\n';
	ofs << "is print\t" << v[9] << '\n';
	ofs << "is graph\t" << v[10] << '\n';
}

void print_file(const std::string& name)
{
	std::ifstream ifs{ name };
	if (!ifs) std::cerr << "error: can't open the input file " << name;

	for (std::string s; std::getline(ifs, s);)
		std::cout << s << '\n';
}

int main()
try
{
	std::cout << "please enter the name of the file for text:\n";
	std::string text;
	std::cin >> text;
	std::cout << "please enter the name of the file for categories:\n"; 
	std::string categories;
	std::cin >> categories;

	fill_file(text);
	write_categories(categories, text);

	std::cout << "\ntext:\n";
	print_file(text);
	std::cout << "\nsymbols by category:\n";
	print_file(categories);

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