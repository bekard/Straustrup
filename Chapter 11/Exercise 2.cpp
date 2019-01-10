#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

void find_and_print(const std::string& iname, const std::string& word)
{
	std::ifstream ifs{ iname };
	if (!ifs) std::cerr << "can't open the file ", iname;

	std::string line;
	for (int x = 1; std::getline(ifs, line); ++x) {
		std::istringstream is{ line };

		for (std::string s; is >> s;) {
			std::string low_word;

			for (char ch : s) {
				if (isalpha(ch)) low_word.push_back(std::tolower(ch));
			}

			if (low_word == word) {
				std::cout << x << ") " << line << '\n';
				break;
			}
		}
	}
}

int main()
try
{
	find_and_print("text_ch11ex2.txt", "not");
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