#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>

bool is_vowel(const char& c)
{
	switch (c) {
	case 'a': case 'e': case 'i': case 'o': case 'u':
	case 'A': case 'E': case 'I': case 'O': case 'U':
		return true;
	default:
		return false;
	}
}

void fill_file(const std::string& oname)
{
	const std::string exit = "exit";
	std::ofstream ofs{ oname };
	if (!ofs) std::cerr << "can't open the file ", oname;

	std::cout << "please enter the text (enter 'exit' at the end)\n";
	for (std::string w; std::getline(std::cin,w) && w != exit;) {
		ofs << w << '\n';
	}
}

void delete_vowels(const std::string& iname)
{
	std::fstream ifs{ iname };
	if (!ifs) std::cerr << "can't open the file ", iname;

	std::vector<std::string> lines;
	for (std::string line; std::getline(ifs, line);) {
		std::string without_vowels;

		for (char ch : line) {
			if (!is_vowel(ch)) without_vowels.push_back(ch);
		}

		lines.push_back(without_vowels);
	}

	std::ofstream ofs{ iname };
	if (!ofs) std::cerr << "can't open the file ", iname;

	for (int x = 0; x < lines.size(); ++x)
		ofs << lines[x] << '\n';
}

void print_from_file(const std::string& iname)
{
	std::fstream ifs{ iname };
	if (!ifs) std::cerr << "can't open the file ", iname;

	for (std::string line; std::getline(ifs, line);)
		std::cout << line << '\n';
}

int main()
try
{
	fill_file("text_ch11ex3.txt");
	delete_vowels("text_ch11ex3.txt");
	print_from_file("text_ch11ex3.txt");
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