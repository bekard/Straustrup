#include <string>
#include <vector>
using namespace std;

namespace Library {

	enum class Month {
		jan = 1, feb, mar, apr, may, jun,
		jul, aug, sep, oct, nov, dec
	};

	class Date {
	public:
		Date(int day, Month m, int year);
		Date get_date();
	private:
		int year{ 2018 };
		Month m{ Month::nov };
		int day{ 26 };
	};

	class Book {
	public:
		Book(fill_ibsn(), string name, string author, Date d, bool in_library);
		Book();
		void add_book();
		string fill_ibsn();
		string fill_name();
		string fill_author();
		string get_ibsn() { return ibsn; };
		string get_name() {return name; };
		string get_author() { return author; };
	private:
		 string ibsn;
		 string name;
		 string author;
		 Date d;
		 bool available;
		 void print();
		 vector<Book>catalog{};
	};
}
