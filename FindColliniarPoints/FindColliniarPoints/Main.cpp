// Stephen Belden - SB
// Meghan Haugaas - MH
// Chris Ruiz - CR

// 2015-Oct-11

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Point.h"
#include "RandomUtilities.h"
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

// Global Function Declarations
vector<Point> generateRandomPoints(int number);

// Global Variables
double range = 1000; // Points will have a max x and y of +- this value
double precission = 0.000001; // Acceptable error in double calculations

int main() {
	// Open a file of points
	ifstream infile;
	do {
		string filename;
		cout << "Enter name of a point file: ";
		cin >> filename;
		infile.open(filename.c_str());
		if(!infile) cout << "Failed to open point file." << endl << endl;
	} while(!infile);

	// Read points from the file
	vector<Point> pointListA;
	while(!infile.eof()) {
		double x, y;
		infile >> x >> y;
		pointListA.push_back(Point(x, y));
	}

	// BS output
	cout << endl << "Generic Output:" << endl
		<< "There may or may not be N groups of 4 or more collinear points in this list." << endl;
	cout << endl;
	cout << "Some points from the list: " << endl;
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