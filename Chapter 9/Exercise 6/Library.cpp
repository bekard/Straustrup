#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"
#include "Library.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace Library {

	// ------------------------------------------------------------------------

	// definitions of class Book
	// constructor
	Book::Book(string i, string n, string a, string dd, bool in)
		:ibsn{ i }, name{ n }, author{ a }, data{ dd }, available{ in }
	{
	}

	// constructor by default
	Book::Book()
		: ibsn{ "" }, name{ "" }, author{ "" }, data{ "" }, available{ false }
	{
	}

	// create vector for Book(s)
	vector<Book>catalog{};

	// ------------------------------------------------------------------------

	// defenitions of Book helper functions
	void Book::fill_ibsn()
	{
		cout << "IBSN has form n-n-n-x, where n-integer and x-digit or letåer.\n";
		cout << "Enter IBSN (separate fragments by space): ";

		int n1, n2, n3;
		string x;

		if (!(cin >> n1 >> n2 >> n3 >> x)) error("incorrect input.");
		if (n1 <= 0 || n2 <= 0 || n3 <= 0) error("n can't be negative.");
		if (x.size() > 1) error("x must have one character.");

		ibsn = to_string(n1) + "-" + to_string(n2) + "-" + to_string(n3) + "-" + x;
	}

	void Book::fill_name()
	{
		cout << "Enter the name of the book (e at the end for exit): ";

		const string out = "e";
		string n;
		while (cin >> n && n != out) {
			name += n;
			name += " ";
		}
	}

	void Book::fill_author()
	{
		cout << "Enter author's last name: ";

		string ln;
		cin >> ln;
		author = ln;
	}

	void Book::fill_date()
	{
		cout << "Enter the date of book registration (day month year): ";

		int d, y, m;

		if (!(cin >> d >> m >> y)) error("incorrect input.");
		if (d <= 0 || d > 31) error("incorrect day.");
		if (m <= 0 || m > 12) error("incorrect month.");
		if (y < 1800 || y > 2018) error("incorrect year.");

		data = "(" + to_string(d) + ", " + to_string(m) + ", " + to_string(y)+")";
	}

	void Book::is_available()
	{
		char a;
		cout << "Is book in library now? (y or n) ";
		cin >> a;

		switch (a) {
		case 'y':
			available = true;
			break;
		case 'n':
			available = false;
			break;
		default:
			error("Incorrect input");
			break;
		}
	}

	// ------------------------------------------------------------------------

	// just functions 
	// create book for catalog
	void add_book()
	{
		Book b;
		b.fill_ibsn();
		b.fill_name();
		b.fill_author();
		b.fill_date();
		b.is_available();
		catalog.push_back(b);
		cout << "Book added.\n";
	}

	// print book information
	void print_book(const Book& bb)
	{
		cout << "/// Information about book: " << bb.get_name() << endl;
		cout << "IBSN: " << bb.get_ibsn() << endl;
		cout << "Name: " << bb.get_name() << endl;
		cout << "Author: " << bb.get_author() << endl;
		cout << "Date of registration: " << bb.get_data() << endl;
		cout << "Book in library: " << bb.get_available() << endl;
	}

	// get book
	Book get_book() { return catalog[0]; }

	// print names of books
	void names_of_books(const vector<Book>& c)
	{
		cout << "/// Books in the catalog:\n";
		for (int x = 0; x < c.size(); ++x)
			cout << x << ") " << c[x].get_name() << endl;
	}

	// print information about chosen book
	void print()
	{
		if (catalog.size() > 0) {
			int n;
			names_of_books(catalog);
			cout << "Please enter the Number of book that you want to see: ";
			cin >> n;

			if (n > catalog.size()) error("Incorrect number.");

			cout << catalog[n];
		}
		else {
			cout << "No books in the catalog.\n";
		}
	}

	// ------------------------------------------------------------------------

	// print operations in program
	void print_operations()
	{
		cout << "/// Operations that you can do in this program:\n"
			<< "Enter:\n"
			<< "1 - to add book.\n"
			<< "2 - to print info about book.\n"
			<< "q - for exit.\n";
	}

	// function for operations with Book b
	void start()
	{
		print_operations();

		char op;
		const char quit = 'q';
		while (cin >> op && op != quit) {

			switch (op) {

			case '1': // add book
				add_book();
				break;

			case '2': // for print 
				print();
				break;

//			case '3': // for quit
				


			default: 
				error("Incorrect number of operation.");
				break;
			}
		}
		cout << "Bye!\n";
	}

	// ------------------------------------------------------------------------

	// definitions of operators for class Book
	bool operator== (const Book& a, const Book& b)
	{
		return a.get_ibsn() == b.get_ibsn();
	}

	bool operator!= (const Book& a, const Book& b)
	{
		return !(a.get_ibsn() == b.get_ibsn());
	}

	ostream& operator<< (ostream& os, const Book& b)
	{
		return os << "Name: " << b.get_name() << endl
			<< "Author: " << b.get_author() << endl
			<< "IBSN: " << b.get_ibsn() << endl;
	}
}