#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

void fill_file(const std::string& oname)
{
	const std::string exit = "exit";
	std::ofstream ofs{ oname };
	if (!ofs) std::cerr << "can't open the file ", oname;

	for (std::string word; std::cin >> word && word != exit;)
		ofs << word << ' ';
}

void to_low(const std::string& iname, const std::string& oname)
{
	std::ifstream ifs{ iname };
	if (!ifs) std::cerr << "can't open the file ", iname;

	std::ofstream ofs{ oname };
	if (!ofs) std::cerr << "can't open the file ", oname;

	for (char ch; ifs.get(ch);) {
		ch = tolower(ch);
		ofs << ch;
	}
}

int main()
try
{
	to_low("message.txt", "lowmsg.txt");

	return 0;
}

catch (...) {
	std::cout << "exiting\n";
	return 1;
}