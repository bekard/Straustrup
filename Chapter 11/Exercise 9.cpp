#include <iostream>
#include <fstream>
#include <string>
#include <vector>

template<class T> char* as_bytes(T& i)	// needed for binary I/O
{
	void* addr = &i;	// get the address of the first byte
						// of memory used to store the object
	return static_cast<char*>(addr); // treat that memory as bytes
}

std::vector<int>to_binary(const std::string& iname)
{
	std::vector<int>v;

	std::ifstream ifs{ iname, std::ios_base::binary };
	if (!ifs) std::cerr << "can't open the input file " << iname;

	for (int x; ifs.read(as_bytes(x), sizeof(int));)
		v.push_back(x);

	return v;
}

void from_binary(const std::string& oname, const std::vector<int>&v)
{
	std::ofstream ofs{ oname, std::ios_base::binary };
	if (!ofs) std::cerr << "can't open the output file " << oname;

	for (int x : v)
		ofs.write(as_bytes(x), sizeof(int));
}

int main()
try
{
	std::cout << "enter the name of the file for input\n";
	std::string iname;
	std::cin >> iname;
	std::vector<int>binary = to_binary(iname);

	std::cout << "enter the name of the file for output\n";
	std::string oname;
	std::cin >> oname;
	from_binary(oname, binary);

	std::cout << "done!\n";

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