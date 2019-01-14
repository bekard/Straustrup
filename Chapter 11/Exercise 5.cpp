#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>

void check(const char& ch, const int& n)
{
	std::string s;
	switch (n)
	{
	case 0:
		if (isspace(ch)) std::cout << "(is space)";
		break;
	case 1:
		if (isalpha(ch)) std::cout << "(is alpha)";
		break;
	case 2:
		if (isdigit(ch)) std::cout << "(is digit)";
		break;
	case 3:
		if (isxdigit(ch)) std::cout << "(is xdigit)";
		break;
	case 4:
		if (isupper(ch)) std::cout << "(is upper)";
		break;
	case 5:
		if (islower(ch)) std::cout << "(is lower)";
		break;
	case 6:
		if (isalnum(ch)) std::cout << "(is alnum)";
		break;
	case 7:
		if (iscntrl(ch)) std::cout << "(is cntrl)";
		break;
	case 8:
		if (ispunct(ch)) std::cout << "(is punct)";
		break;
	case 9:
		if (isprint(ch)) std::cout << "(is print)";
		break;
	case 10:
		if (isgraph(ch)) std::cout << "(is graph)";
		break;
	default:
		std::cerr << "incorrect input";
	}
}

int main()
try
{
	for (std::string s; std::getline(std::cin, s);) {
		
		for (char ch : s) {
			std::cout << ch;
			
			for (int x = 0; x <= 10; ++x) {
				std::cout << std::setw(11);
				check(ch, x);
			}
			std::cout << '\n';
		}
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