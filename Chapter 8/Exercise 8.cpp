#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

void fill_price(vector<double>&p) {
	cout << "fill the vector of prices $ (for exit enter 0):\n";
	for (double x = 0; cin >> x && x != 0;)
		p.push_back(x);
}

void fill_weight(vector<double>&v, const vector<double>&p) {
	double w;
	cout << "fill the vector of weights\n";
	for (int n = 0; n < p.size(); ++n) {
		cout << n + 1 << " item (" << p[n] << "$) = ";
		cin >> w;
		v.push_back(w);
	}
}

void result(vector<double>p, vector<double>w){
	cout << "Results:\n";
	for (int x = 0; x < p.size(); ++x) {
		cout << x + 1 << " item: " << p[x] << " * " << w[x] << " = " << p[x] * w[x] << '\n';
	}
}

int main()
try
{
	vector<double>price;
	vector<double>weight;

	fill_price(price);
	fill_weight(weight, price);
	result(price, weight);

	keep_window_open();
}

catch (runtime_error e) {
	cout << e.what() << '\n';
	keep_window_open("~");
}
catch (...) {
	cout << "exiting\n";
	keep_window_open("~");
}