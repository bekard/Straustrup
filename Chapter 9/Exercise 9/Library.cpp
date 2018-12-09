#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"
#include "Library.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace Lib {

	// create Library
	Library my_lib;
	// ------------------------------------------------------------------------
	// definitions for class Date

	Date::Date(int dd, Month mm, int yy)
		:d { dd }, m{ mm }, y{ yy }
	{
		if (d < 1 || d > 31 || m < Month::jan || m > Month::dec) error("LOL date");
	}

	const Date def_date{ 9, Date::Month::dec, 2018 };

	Date::Date()
		:d{ def_date.d }, m{ def_date.m }, y{ def_date.y }
	{
	}

	// ------------------------------------------------------------------------
	// definitions of class Patron
	// constructor
	Patron::Patron(string n, int cn, double f)
		:user{ n }, card_num{ cn }, fee{ f }
	{
	}

	// default user
	const Patron def_user{ "", 0, 0 };

	// constructor by default
	Patron::Patron()
		:user{ def_user.user },
		card_num{ def_user.card_num },
		fee{ def_user.fee }
	{
	}

	// helper functions:

	void Patron::fill_user()
	{
		cout << "Name of the patron: ";
		cin >> user;
	}

	void Patron::fill_card_num()
	{
		cout << "Card number: ";
		cin >> card_num;
		if (card_num < 0 || card_num > 1000) error("incorrect number");
	}

	void Patron::fill_fee()
	{
		cout << "Set fee: ";
		cin >> fee;
		if (fee < 0 || fee > 100.0) error("incorrect fee");
	}

	// set fee for the patron
	void Patron::set_fee()
	{
		cout << "Set fee for the patron: ";
		cin >> fee;

		if (fee < 0) error("fee can't be less then zero.");
	}
	
	// did the patron pay fee?
	bool Patron::owes_fee(const Patron& p)
	{
		return p.get_fee() > 0;
	}

	// ------------------------------------------------------------------------

	// definitions of class Book
	// constructor
	Book::Book(string i, string n, string a, string dd, bool in, Genre gg)
		:ibsn{ i }, name{ n }, author{ a }, data{ dd }, available{ in }, g { gg }
	{
	}

	// constructor by default
	Book::Book()
		: ibsn{ "" }, name{ "" }, author{ "" }, data{ "" }, available{ false },
		g{ Genre::none }
	{
	}

	// add some books in catalog
	void Library::fill_books() 
	{
		Book first
		{
			"9785-699-84774-7",
			"The man in the high castle",
			"Dick",
			"10.12.1990",
			true,
			Genre::fiction
		};
		books.push_back(first);
		
		Book second
		{
			"9785-389-01554-8",
			"Bag",
			"Davlatov",
			"1.7.2002",
			false,
			Genre::biography
		};
		books.push_back(second);
		
		Book third
		{
		"9781-77226-118-9",
		"Alice's adventures in Wonderland",
		"Carroll",
		"21.10.2018",
		true,
		Genre::children
		};
		books.push_back(third);
	}

	// add patrons to library
	void Library::fill_patrons()
	{
		Patron first
		{
			"Joe Jukovsky",
			123,
			0
		}; 
		patrons.push_back(first);

		Patron second
		{
			"Qwerty",
			17,
			5
		};
		patrons.push_back(second);

		Patron third
		{
			"Boris Anikov",
			8,
			99
		};
		patrons.push_back(third);

		Patron fourth
		{
			"Zed z",
			1,
			0
		};
		patrons.push_back(fourth);
	}

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

	void Book::choose_genre()
	{
		cout << "Choose genre.\n"
			<< "0 - none\n"
			<< "1 - fiction\n"
			<< "3 - prose\n"
			<< "4 - periodical\n"
			<< "5 - biography\n"
			<< "6 - children\n";
		char n;
		cin >> n;

		switch (n) {
		case '0': case '1': case '2': case'3': case'4': case'5': case'6':
			g = Genre(n);
			break;

		default:
			error("incorrect genre.");
			break;
		}
	}

	// ------------------------------------------------------------------------
	// definitions of constructors Transaction
	Library::Transaction::Transaction(Book bb, Patron pp, Date dd)
		:b { bb }, p { pp }, d { dd }
	{
	}

	const Date default_d{ 10, Date::Month::oct, 2000 };

	const Library::Transaction def_transaction{
		Book(), Patron(), default_d
	};

	Library::Transaction::Transaction()
		:b{ def_transaction.b },
		p{ def_transaction.p },
		d{ def_transaction.d }
	{
	}

	// Library constractor defenition
	Library::Library(vector<Book>bb, vector<Patron>pp, vector<Transaction>tt)
		:books{ bb }, patrons{ pp }, transactions{ tt }
	{
	}

	const Library& def_library()
	{
		vector<Book>b;
		vector<Patron>p;
		vector<Library::Transaction>t;
		const Library lib{ b, p, t };
		return lib;
	}
	
	Library::Library()
		:books{def_library().get_books()},
		patrons{ def_library().get_patrons() },
		transactions{ def_library().get_transactions() }
	{
	}

	// ------------------------------------------------------------------------

	// just functions 
	// to add book in library
	void Library::add_book()
	{
		Book b;
		b.fill_ibsn();
		b.fill_name();
		b.fill_author();
		b.fill_date();
		b.is_available();
		b.choose_genre();
		books.push_back(b);
		cout << "Book added.\n";
	}

	// add patron to library
	void Library::add_patron()
	{
		Patron p;
		p.fill_user();
		p.fill_card_num();
		p.fill_fee();
		patrons.push_back(p);
		cout << "Patron added.\n";
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
	Book Library::get_book() { return books[0]; }

	// print names of books
	void names_of_books(const vector<Book>& c)
	{
		cout << "/// Books in the library:\n";
		for (int x = 0; x < c.size(); ++x)
			cout << x << ") " << c[x].get_name() << endl;
	}

	// print information about chosen book
	void Library::print()
	{
		if (books.size() > 0) {
			int n;
			names_of_books(books);
			cout << "Please enter the Number of book that you want to see: ";
			cin >> n;

			if (n > books.size()) error("Incorrect number.");

			cout << books[n];
		}
		else {
			cout << "No books in the library.\n";
		}
	}

	// transaction 
	void Library::trans()
	{
		cout << "Who wants to take a book?(enter number)\n";
		for (int x = 0; x < patrons.size(); ++x) // print patrons
			cout << x << ") " << patrons[x].get_user() << endl;

		int p; // choose patron
		cin >> p;
		if (p >= patrons.size() || p < 0) error("Incorrect number.");
		if (patrons[p].get_fee() > 0) error("The patron needs to pay fee.");

		cout << "Choose a book.\n";
		names_of_books(books); // print books

		int b; // choose book
		cin >> b;
		if (b >= books.size() || b < 0) error("Incorrect number.");
		if (books[b].get_available() == "no") {
			cout << "book is not in the library.\n";
			return;
		}

		Transaction t
		{
			books[b],
			patrons[p],
			Date()
		};
		transactions.push_back(t);
		cout << "Transaction added.\n";
	}

	// print debtors of the library
	void Library::get_debtors()
	{
		cout << "Debtors" << '\t' << "Fees\n";
		for (int x = 0; x < patrons.size(); ++x) {
			if (patrons[x].get_fee() > 0)
				cout << patrons[x].get_user() << '\t' << patrons[x].get_fee() << endl;
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
			<< "3 - to add patron.\n"
			<< "4 - print list of debtors.\n"
			<< "5 - patron wants to take a book.\n"
			<< "q - for exit.\n";
	}

	// function for operations with Book b
	void start()
	{
		my_lib.fill_books();
		my_lib.fill_patrons();
		print_operations();

		char op;
		const char quit = 'q';
		while (cin >> op && op != quit) {

			switch (op) {

			case '1': // add book
				my_lib.add_book();
				break;

			case '2': // for print 
				my_lib.print();
				break;

			case '3': // add patron
				my_lib.add_patron();
				break;

			case '4': // print debtors
				my_lib.get_debtors();
				break;

			case '5':
				my_lib.trans();
				break;
				
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