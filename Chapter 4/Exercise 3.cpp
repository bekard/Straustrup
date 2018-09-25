#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"
int main()
{
	// Variebles initialization
	vector<double>distances;
	double sum = 0;
	
	//The instruction 'for' for adding a distance to the end of a vector
	//and summation of a distances
	for (double distance = 0; cin >> distance;) {
		distances.push_back(distance);
		sum += distance;
	}

	// Sort of a distances
	sort(distances.begin(), distances.end());

	cout << "The total distance is " << sum << '\n';
	cout << "The highest distance is " << distances[distances.size() - 1] << '\n';
	cout << "The lowest distance is " << distances[0] << '\n';
	cout << "The middle value of a distances is " << sum / distances.size() << '\n';

	return 0;
}
