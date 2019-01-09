#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void fill_first_file(const std::string& first)
{
	std::string msg = "Hello, my name is:";
	std::ofstream ofs{ first };
	if (!ofs) std::cerr << "can't open the first file";
	ofs << msg;
}

void fill_second_file(const std::string& second)
{
	std::string msg = "Anton Arefyev";
	std::ofstream ofs{ second };
	if (!ofs) std::cerr << "can't open the second file";
	ofs << msg;
}

void combine_in_third(const std::string& first, const std::string& second, const std::string& third)
{
	std::string m;
	std::ifstream ifs1{ first };
	std::ifstream ifs2{ second };
	if (!ifs1 || !ifs2) std::cerr << "can't open the file when combine";

	std::ofstream ofs{ third };
	if (!ofs) std::cerr << "can't open the third file";

	while (ifs1 >> m) ofs << m << " ";
	while (ifs2 >> m) ofs << m << " ";
}

void print(const std::string& third)
{
	std::string msg;
	std::ifstream ifs{ third };
	if (!ifs) std::cerr << "can't open the third file";
	
	while (ifs >> msg) std::cout << msg << " ";
}

void start(const std::string& first, const std::string& second, const std::string& third)
{
	fill_first_file(first);
	fill_second_file(second);
	combine_in_third(first, second);
	print(third);
}

int main()
try
{
	start("first.txt", "second.txt", "third.txt");
	return 0;
}

catch (...) {
	std::cout << "exiting\n";
	return 1;
}