#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <algorithm>

bool is_w(const char& c, const std::string& w)
{
	for (char ch : w)
		if (c == ch) return true;

	return false;
}

std::vector<std::string> split(const std::string& s, const std::string& w)
{
	std::vector<std::string> words;
	std::string word;

	for (int x = 0; x < s.size(); ++x) {
		if (!is_w(s[x], w) && !std::ispunct(s[x]) && !std::isspace(s[x]))
			word.push_back(s[x]);
		else {
			if (word != "") words.push_back(word);
			word = "";
		}
	}

	return words;
}

void print_words(const std::vector<std::string>& v)
{
	std::cout << "Words in the vector:\n";
	for (std::string s : v)
		std::cout << s << '\n';
}

int main()
try
{
	const std::string ws = "$:.-!><";
	std::cout << "Please enter a line:\n";

	for (std::string line; getline(std::cin, line);) {
		std::cout << "line:\n" << line << '\n';

		std::vector<std::string>words = split(line, ws);
		print_words(words);

		std::cout << "Please enter another line:\n";
	}
	
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