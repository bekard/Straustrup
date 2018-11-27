#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"
#include "Library.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
using namespace Library;


// definition of constructor Date
Date::Date(int dd, Month mm, int yy)
	:day{dd}, m{mm}, year{yy}
{
}

// definition of helper function
//Date Date::get_date();


// default date
const Date def_date{ 1, Month::jan, 2000 };

// ------------------------------------------------------------------------

// definitions of class Book
// constructor
Book::Book(string i, string n, string a, Date dd, bool in)
	:ibsn{ i }, name{ n }, author{ a }, d{ dd }, available{ in }
{
}

// constructor by default
Book::Book()
	: ibsn{ "none" }, name{ "none" }, author{ "none" }, d{ def_date }, available{ true }
{
}

// defenitions of helper functions
string Book::fill_ibsn()
{
	cout << "IBSN has form n-n-n-x, where n-integer and x-digit or letåer.\n";
	cout << "Enter IBSN (separate fragments by space): ";

	int n1, n2, n3;
	string x;

	//cin >> n1 >> n2 >> n3 >> x;

	if (!(cin >> n1 >> n2 >> n3 >> x)) error("incorrect input.");
	if (n1 <= 0 || n2 <= 0 || n3 <= 0) error("n can't be negative.");
	if (x.size() > 1) error("x must have one character.");

	return (n1,"-",n2,"-",n3,"-",x);
}

//string Book::fill_name()


//string Book::fill_author()


void Book::add_book()
{

}

void Book::print()
{

}