#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <algorithm>

std::vector<std::string> split(const std::string& s)
{
	std::vector<std::string> words;
	std::istringstream is{ s };

	for (std::string word; is >> word;)
		words.push_back(word);


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
	std::cout << "Please enter a line:\n";

	for (std::string line; getline(std::cin, line);) {
		std::cout << "line:\n" << line << '\n';

		std::vector<std::string>words = split(line);
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