#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>

void replacement(std::string& s)
{
	for (char& c : s) {
		c = tolower(c);
		if (ispunct(c)) c = ' ';
	}
}

int main()
try
{
	std::string line = " - don't use the as-if rule.";
	std::cout << line << '\n';
	replacement(line);
	std::cout << line << '\n';

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