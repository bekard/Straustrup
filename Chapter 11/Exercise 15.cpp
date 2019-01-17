#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <algorithm>

int main()
try
{
	std::string iname;
	std::cout << "please enter the name of the input file:\n";
	std::cin >> iname;
	std::ifstream ifs{ iname };
	if (!ifs) std::cerr << "error: can't open the input file " << iname;

	std::string oname;
	std::cout << "please enter the name of the output file:\n";
	std::cin >> oname;
	std::ofstream ofs{ oname };
	if (!ofs) std::cerr << "error: can't open the output file " << oname;

	double x;
	ofs << std::scientific << std::setprecision(8);
	for (int row = 1; ifs >> x; ++row) {
		ofs  << std::setw(20) << x;
		if (row % 4 == 0) ofs << '\n';
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