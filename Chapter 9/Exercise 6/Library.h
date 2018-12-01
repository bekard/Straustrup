#include <string>
#include <vector>
using namespace std;

namespace Library {

	class Book {
	public:
		Book(string ibsn, string name, string author, string d, bool in_library);
		Book();
		void fill_ibsn();
		void fill_name();
		void fill_author();
		void fill_date();
		void is_available();
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
		 vector<Book>catalog;
	};
	// other functions
	void add_book();
	void print_book(const Book& bb);
	void print();
	Book get_book();
	void names_of_books(const vector<Book>& c);
	void print_operations();
	void start();

	// operators for class Book
	bool operator== (const Book& a, const Book& b);
	bool operator!= (const Book& a, const Book& b);
	ostream& operator<< (ostream& os, const Book& b);
}