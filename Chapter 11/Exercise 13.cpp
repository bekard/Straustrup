#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <algorithm>

std::string reverse_words(const std::string& s)
{
	std::vector<std::string> words;
	std::string word;
	for (std::istringstream is{ s }; is >> word;)
		words.push_back(word);

	std::string str;
	std::ostringstream os{ str };
	for (int x = words.size() - 1; x >= 0; --x)
		os << words[x] << ' ';

	return os.str();
}


int main()
try
{
	std::string line = "Norwegian Blue parrot jir kwqeq 123 wt46!@";
	std::cout << reverse_words(line);

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