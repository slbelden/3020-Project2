// Stephen Belden - SB
// Meghan Haugaas - MH
// Chris Ruiz - CR

// 2015-Oct-04

#include <iostream>
#include <vector>
#include "Point.h"
#include "RandomUtilities.h"
using std::vector;
using std::cout;
using std::cin;
using std::endl;

// Global Function Declarations
vector<Point> generateRandomPoints(int number);

int main() {
	// Temporary Point class testing
	Point A = Point(1.1, 2.2);
	Point B = Point();
	cout << "Point A: " << A << endl;
	cout << "Point B: " << B << endl;

	vector<Point> pointListA = generateRandomPoints(1000);
	cout << "There are " << pointListA.size() << " points in list A." << endl;
}

// Gobal Function Deffinions
vector<Point> generateRandomPoints(int number) {
	vector<Point> list = vector<Point>();
	randomizeSeed();
	for (int i = 0; i < number; i++) {
		list.push_back(Point(randUniform() * 1000, randUniform() * 1000));
	}
	return list;
}