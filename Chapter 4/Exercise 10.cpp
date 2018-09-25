#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

int main() {
	char player_choice = 0;
	string player_enter = " ";
	int c = 0;

	cout << "Let's play the rock-scissors-paper game!" << endl;
	cout << "Plese enter your choice: ";

	vector<char> comp_choices;
	comp_choices.push_back('s');
	comp_choices.push_back('r');
	comp_choices.push_back('p');
	comp_choices.push_back('p');
	comp_choices.push_back('s');
	comp_choices.push_back('r');
	comp_choices.push_back('s');
	comp_choices.push_back('r');
	comp_choices.push_back('p');
	comp_choices.push_back('s');

	int player_score = 0;
	int comp_score = 0;

	while (cin >> player_enter)
	{
		// the edit string in the char
		if (player_enter == "rock" || player_enter == "r")
			player_choice = 'r';
		else if (player_enter == "scissors" || player_enter == "s")
			player_choice = 's';
		else if (player_enter == "paper" || player_enter == "p")
			player_choice = 'p';
		else
			player_choice = 0;

		switch (player_choice) {
		case 'r':
			if (comp_choices[c] == 'r') { cout << "Computer's choice - rock. Draw.\n"; }
			if (comp_choices[c] == 'p') { cout << "Computer's choice - paper. You lost.\n"; ++comp_score; }
			if (comp_choices[c] == 's') { cout << "Computer's choice - scissors. You win!\n"; ++player_score; }
			break;

		case 's':
			if (comp_choices[c] == 's') { cout << "Computer's choice - scissors. Draw.\n"; }
			if (comp_choices[c] == 'r') { cout << "Computer's choice - rock. You lost.\n"; ++comp_score; }
			if (comp_choices[c] == 'p') { cout << "Computer's choice - paper. You win!\n"; ++player_score; }
			break;

		case 'p':
			if (comp_choices[c] == 'p') {cout << "Computer's choice - papaer. Draw.\n";	}
			if (comp_choices[c] == 's') { cout << "Computer's choice - scissors. You lost.\n"; ++comp_score; }
			if (comp_choices[c] == 'r') { cout << "Computer's choice - rock. You win!\n"; ++player_score; }
			break;

		default:
			cout << "Incorrect input, try one more time.\n";
		}
		if (c == comp_choices.size()-1) c = 0;
		else ++c;
		
	}
	cout << "Your score: " << player_score << " *** "
		<< "Computer score: " << comp_score << endl;

	if (player_score > comp_score)
		cout << "Congratulations! You win!";
	else if (player_score == comp_score)
		cout << "It's a draw.";
	else
		cout << "Computer won!";
	return 0;
}
