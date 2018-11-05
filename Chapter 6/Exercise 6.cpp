#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

// exercise 6

/*
Sentence:
Subject Verb
Sentence Conjunction Sentence

Subject:
Noun
"the" Noun
"a" Noun

Conjunction:
"and"
"or"
"but"

Noun:
"birds"
"fish"
"C++"

Verb:
"rules"
"fly"
"swim"
*/

vector<string> words;
string word;
bool is_first = true;
bool is_sentence = true;
string last_w;

bool check(string w) {
	if (is_first == true) {
		if (w == "birds" || w == "fish" || w == "C++") {
			is_first = false;
			last_w = "noun";
			return true;
		}
		return false;
	}
	if (last_w == "noun") {
		if (w == "fly" || w == "swim" || w == "rules") {
			last_w = "verb";
			return true;
		}
		return false;
	}
	if (last_w == "verb") {
		if (w == "but" || w == "and" || w == "or") {
			is_first = true;
			return true;
		}
		return false;
	}
	return false;
}

int main()
try
{
	cout << "The sentence:\n";
	while (cin >> word && word != ".") words.push_back(word);

	for (int a = 0; a < words.size(); ++a) {
		if (check(words[a]) == false) is_sentence = false; break;
	}
	if (!is_sentence) cout << "It is not a sentance!\n";
	else cout << "It is OK!\n";
	keep_window_open();
}

catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}