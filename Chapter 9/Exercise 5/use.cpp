#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"
#include "Library.h"
using namespace Library;

int main()
try
{
	Book kek;
	kek.fill_ibsn();
	cout << kek.get_ibsn();


	keep_window_open();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}