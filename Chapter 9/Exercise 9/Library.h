#include <string>
#include <vector>
using namespace std;

namespace Lib {

	class Date {
	public:
		enum class Month {
			jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
		};
		Date(int d, Month m, int y);
		Date();
		int year() const { return y; };
		Month month() const { return m; };
		int day() const { return d; };
	private:
		int y;
		Month m;
		int d;
	};

	class Patron {
	public:
		Patron(string u, int c, double f);
		Patron();
		string get_user() const { return user; }
		int get_card_num() const { return card_num; }
		double get_fee() const {return fee;}

		void fill_user();
		void fill_card_num();
		void fill_fee();
		void set_fee();
		bool owes_fee(const Patron& p);
	private:
		string user;
		int card_num;
		double fee;
	};
	bool owes_fee(const Patron& p);

	enum class Genre {
		none, fiction, prose, periodical, biography, children
	};

	class Book {
	public:
		Book(string ibsn, string name, string author,
			string d, bool in_library, Genre g);
		Book();
		void fill_ibsn();
		void fill_name();
		void fill_author();
		void fill_date();
		void is_available();
		void choose_genre();
		string get_ibsn() const { return ibsn; }
		string get_name() const {return name; }
		string get_author() const { return author; }
		string get_data() const { return data; }
		string get_available() const {
			if (available == true) return "yes";
			else return "no";
		}
	private:
		 string ibsn;
		 string name;
		 string author;
		 string data;
		 bool available;
		 Genre g;
		 vector<Book>catalog;
	};

	class Library {
	public:
		struct Transaction {
			Book b;
			Patron p;
			Date d;

			Transaction(Book bb, Patron pp, Date dd);
			Transaction();
		};

		Library(vector<Book>books, vector<Patron>patrons, vector<Transaction>transactions);
		Library();

		void add_book();
		void add_patron();
		Book get_book();
		void fill_books();
		void fill_patrons();
		void print();
		void trans();
		void get_debtors();

		vector<Book> get_books() const { return books; }
		vector<Patron> get_patrons() const { return patrons; }
		vector<Library::Transaction> get_transactions() const { return transactions; }
	private:
		vector<Book>books{};
		vector<Patron>patrons{};
		vector<Transaction>transactions{};
	};

	// other functions
	void print_book(const Book& bb);
	void print_operations();
	void start();
	void names_of_books(const vector<Book>& c);

	// operators for class Book
	bool operator== (const Book& a, const Book& b);
	bool operator!= (const Book& a, const Book& b);
	ostream& operator<< (ostream& os, const Book& b);
}