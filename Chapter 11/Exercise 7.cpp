#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>

//-------------------------------------------------------------------------
// other functions

bool is_punct(const char& c)
{
	switch (c) {
	case '.': case ';': case '!':
	case '?': case ',':
		return true;
		break;
	default:
		return false;
	}
}

void delete_wspace_hyphen(std::string& s)
{
	for (int x = 0; x < s.size(); ++x) {

		if (is_punct(s[x])) s[x] = ' ';

		else if (s[x] == '-') {
			++x;
			if (!isalpha(s[x])) s[x - 1] = ' ';
		}
	}
}

void to_lower(std::string& s)
{
	for (char& c : s)
		if (isalpha(c)) c = tolower(c);
}

//-------------------------------------------------------------------------
// functions to devide word, example: don't = do not , etc..

void devide_denial(std::string& word)
{
	if (word == "can't") {
		word = "cannot";
		return;
	}
	std::string d;
	for (int x = 0; x < word.size() - 3; ++x)
		d += word[x];

	word = d + " not";
}

bool is_denial(const std::string& word)
{
	std::string n;

	for (int x = word.size() - 3; x < word.size(); ++x)
		n += word[x];

	if (n == "n't") return true;
	return false;
}

void to_devided(std::string& s)
{
	std::string devided;
	std::istringstream is{ s };
	std::ostringstream os{ devided };

	for (std::string word; is >> word;) {

		if (is_denial(word)) devide_denial(word);
		os << word << ' ';
	}
	s = os.str();
}

//-------------------------------------------------------------------------

void change_file()
{
	std::string fname;
	std::cout << "enter the name of the file: ";
	std::cin >> fname;

	std::fstream fs{ fname };
	if (!fs) std::cerr << "can't open the file ", fname;

	for (std::string s; std::getline(fs, s);)
		delete_wspace_hyphen(s);
}

//-------------------------------------------------------------------------

int main()
try
{
	std::vector<std::string>dictionary;
	std::string line = " - Don't USE the aS-If Rule. -";

	change_file();

	std::cout << line << '\n';

	return 0;
}

//-------------------------------------------------------------------------

catch (std::exception& e) {
	std::cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	std::cerr << "Oops: unknown exception!\n";
	return 2;
}
