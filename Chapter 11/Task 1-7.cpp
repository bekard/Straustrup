#include <iostream>

void hex_out(const int& y, std::ostream& os)
{
	os << std::hex << y << "\tHexadecimal\n";
}

void print_dec(const int& y)
{
	std::cout << std::showbase << y << "\tDecimal\t\t no base\n";
}

void print_hex(const int& y)
{
	std::cout << std::hex << y << "\tHexadecimal\t base: 0x\n";
}

void print_oct(const int& y)
{
	std::cout << std::oct << y << "\tOctal\t\t base: 0\n";
}

void dec_hex_oct(const int& y)
{
	print_dec(y);
	print_hex(y);
	print_oct(y);
}

void print_age(const int& a)
{
	std::cout << std::noshowbase << std::dec <<a << "\tMy age\n";
}

int main()
try
{
	const int birth_year = 1994;
	const int my_age = 24;

	dec_hex_oct(birth_year);
	print_age(my_age);

	return 0;
}

catch (...) {
	std::cout << "exiting\n";
	return 1;
}