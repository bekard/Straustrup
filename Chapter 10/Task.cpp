#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

struct Point
{
	int x;
	int y;
	Point(int q, int w) :x{ q }, y{ w }{}
	Point() :x{ 0 }, y{ 0 }{}
};

bool operator==(const Point& p1, const Point& p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(const Point& p1, const Point& p2)
{
	return !(p1 == p2);
}

vector<Point> fill_vector() 
{
	vector<Point>v;
	v.push_back(Point{ 1,2 });
	v.push_back(Point{ -5,13 });
	v.push_back(Point{ 0,7 });
	v.push_back(Point{ 8,2 });
	v.push_back(Point{ -1,-7 });
	v.push_back(Point{ 1,10 });
	v.push_back(Point{ 5,11 });
	return v;
}

void add_to_file(const vector<Point>& points, string oname)
{
	ofstream ost{ oname };
	if (!ost) error("unable to open output file", oname);
	for (int p = 0; p < points.size(); ++p)
		ost << points[p].x << '\t' << points[p].y << '\n';
}

void fill_from_file(vector<Point>& points, string iname)
{
	ifstream ist{ iname };
	if (!ist) error("unable to open input file", iname);
	int x, y;
	while (ist >> x >> y)
		points.push_back(Point{ x,y });
}

void print_vector(const vector<Point>& points, string name)
{
	cout << name << '\n';
	for (int p = 0; p < points.size(); ++p)
		cout << points[p].x << '\t' << points[p].y << '\n';
}

void vectors_same(const vector<Point>& p1, const vector<Point>& p2)
{
	if (p1.size() != p2.size()) error("wrong sizes");
	for (int xx = 0; xx < p1.size(); ++xx)
		if (p1[xx] != p2[xx]) {
			cout << "vectors are not the same";
			break;
		}
	cout << "vector are the same";
}

int main()
{   
	// fill vector with points
	vector<Point>original_points = fill_vector();

	// add points from vector "original_points" to file
	add_to_file(original_points, "mydata.txt");

	// new vector definition and his filling
	vector<Point>processed_points; 
	fill_from_file(processed_points, "mydata.txt");

	// print both vectors
	print_vector(original_points, "original points");
	print_vector(processed_points, "processed_points");

	// compare vectors
	vectors_same(original_points, processed_points);

	return 0;
}