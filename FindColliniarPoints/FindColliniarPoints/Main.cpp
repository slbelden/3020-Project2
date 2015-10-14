// Stephen Belden - SB
// Meghan Haugaas - MH
// Chris Ruiz - CR

// 2015-Oct-11

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Point.h"
#include "RandomUtilities.h"
#include "Edge.h"
#include "Line.h"
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::sort;
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
		double x = 0, y = 0;
		infile >> x >> y;
		pointListA.push_back(Point(x, y));
	}

	// Create all edges
	// O(N^2)
	vector<Edge> edgeListA;
	vector <Point> tempPoints;
	tempPoints = pointListA;
	for each(Point a in pointListA) {
		for each(Point b in tempPoints) {
			if (a != b) edgeListA.push_back(Edge(a, b));
		}
		tempPoints.erase(tempPoints.begin());
	}

	// Sort by slope
	// O(N log N)
	sort(edgeListA.begin(), edgeListA.end());

	// Testing Output
	cout << endl << "Generic Output:" << endl
		<< "There may or may not be N groups of 4 or more collinear points in this list." << endl;
	cout << endl;
	cout << "Some points from the list: " << endl;
	int i = 1;
	for each (Edge e in edgeListA) {
		cout << "Edge " << i << " is " << e << endl;
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