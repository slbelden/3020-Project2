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
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::string;
using std::getline;
using std::ifstream;

// Global Function Declarations
vector<Point> generateRandomPoints(int number);

// Global Variables
double range = 1000.0; // Points will have a max x and y of +- this value 
bool fileMode = true; // Used to control program flow

int main() {
	// Open a file of points
	ifstream infile;
	string filename;
	cout << "Enter name of a point file (press enter to skip): ";
	getline(cin, filename);
	infile.open(filename.c_str());
	if(!infile) {
		cout << "Failed to open point file." << endl;
		cout << "Switching to random point generation instead..." << endl << endl;
		fileMode = false;
	}

	vector<Point> pointList;

	if(!fileMode) {
		// Get info for random point generator
		int totalPoints;
		double collinearRatio;
		int pointsPerLine;
		cout << "Total number of points to generate (positive integer): ";
		cin >> totalPoints;
		cout << "Ratio of points that will be collinear (double from 0.0 to 1.0): ";
		cin >> collinearRatio;
		cout << "Number collinear of points on each unique line (int 2 or larger): ";
		cin >> pointsPerLine;
		cout << endl;

		// Generate points
		randomizeSeed();
		int colPoints = (double)totalPoints * collinearRatio;
		int randomPoints = totalPoints - colPoints;

	}

	if(fileMode) {
		// Read points from the file
		while(!infile.eof()) {
			double x = 0, y = 0;
			infile >> x >> y;
			pointList.push_back(Point(x, y));
		}
	}

	// Create all edges
	// O(N^2)
	vector<Edge> edgeList;
	vector <Point> tempPoints;
	tempPoints = pointList;
	for each(Point a in pointList) {
		for each(Point b in tempPoints) {
			if (a != b) edgeList.push_back(Edge(a, b));
		}
		tempPoints.erase(tempPoints.begin());
	}

	// Sort by slope
	// O(N log N)
	sort(edgeList.begin(), edgeList.end());

	// Testing Output
	cout << endl << "Generic Output:" << endl
		<< "There may or may not be N groups of 4 or more collinear points in this list." << endl;
	cout << endl;
	cout << "Some points from the list: " << endl;
	int i = 1;
	for each (Edge e in edgeList) {
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