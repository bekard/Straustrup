#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <algorithm>

//-------------------------------------------------------------------------
// other functions

bool is_punct(const char& c)
{
	switch (c) {
	case '.': case ';': case '!':
	case '?': case ',': case ':':
	case '(': case ')':
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

void file_to_lower(const std::string& fname)
{
	std::ifstream ifs{ fname };
	if (!ifs) std::cerr << "can't open the file: " << fname;

	std::vector<std::string>lines;
	for (std::string line; getline(ifs, line);) {
		to_lower(line);
		lines.push_back(line);
	}

	std::ofstream ofs{ fname };
	if (!ofs) std::cerr << "can't open the file: " << fname;

	for (std::string& s : lines)
		ofs << s << '\n';
}

void delete_ws_and_hyphen_infile(const std::string& fname)
{
	std::ifstream ifs{ fname };
	if (!ifs) std::cerr << "can't open the file: " << fname;

	std::vector<std::string>lines;
	for (std::string line; getline(ifs, line);) {
		delete_wspace_hyphen(line);
		lines.push_back(line);
	}
		
	std::ofstream ofs{ fname };
	if (!ofs) std::cerr << "can't open the file: " << fname;

	for (std::string& s : lines)
		ofs << s << '\n';
}

void change_file(const std::string& fname)
{
	file_to_lower(fname);
	delete_ws_and_hyphen_infile(fname);
}

void add_to_dictionary(const std::string& iname, const std::string& oname)
{
	std::vector<std::string>all_words;
	std::ifstream ifs{ iname };
	if (!ifs) std::cerr << "can't open the file: " << iname;

	for (std::string s; std::getline(ifs, s);) {
		std::istringstream is{ s };
		while (is >> s)
			all_words.push_back(s);
	}

	std::sort(all_words.begin(), all_words.end());

	std::ofstream ofs{ oname };
	if (!ofs) std::cerr << "can't open the file: " << oname;

	bool is_first = true;
	for (int x = 0; x < all_words.size(); ++x) {
		if (is_first) {
			ofs << all_words[x] << '\n';
			is_first = false;
		}
		else {
			if (!(all_words[x] == all_words[x - 1]))
				ofs << all_words[x] << '\n';
		}
	}
}

//-------------------------------------------------------------------------

int main()
try
{
	const std::string file = "text_ch11ex8.txt";
	const std::string dictionary_file = "dictionary_ch11ex8.txt";

	change_file(file);
	add_to_dictionary(file, dictionary_file);

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