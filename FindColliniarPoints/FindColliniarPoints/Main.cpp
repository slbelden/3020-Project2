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

// Global Variables
double range = 1000; // Points will have a max x and y of +- this value
double precission = 0.000001; // Accepted error in double calculations

int main() {
	// Temporary IO code
	int number = 0;
	cout << "Number of points to randomly generate: ";
	cin >> number;

	vector<Point> pointListA = generateRandomPoints(number);
	cout << "There are " << pointListA.size() << " points in list A." << endl;
	cout << endl;

	// BS output
	cout << "Generic Output:" << endl
		<< "There may or may not be 0 groups of 4 or more collinear points in this list." << endl;
	cout << endl;
	cout << "Some points: " << endl;
	int i = 0;
	char letter = 'A';
	while(letter < 'Z' && i < pointListA.size()) {
		cout << "Point " << letter << ": " << pointListA[i] << endl;
		letter++;
		i++;
	}
}

// Gobal Function Deffinions
vector<Point> generateRandomPoints(int number) {
	vector<Point> list = vector<Point>();
	randomizeSeed();
	for (int i = 0; i < number; i++) {
		list.push_back(Point(randReal(-1 * range, range), randReal(-1 * range, range)));
	}
	return list;
}