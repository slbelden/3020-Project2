// Given n points in a plane, this algorithm will find all groups of 4 or more
// collinear points in O(N^2 log N) time (probably).
// The algorithm cna correctly handle parralel lines, treating them as 2
// distinct collinear lines, and can handle n point on any line.
// This program can also generate sets of random example points.

// Stephen Belden - SB
// Meghan Haugaas - MH
// Chris Ruiz - CR

// 2015-Oct-18

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include "Point.h"
#include "RandomUtilities.h"
#include "Edge.h"
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::abs;
using std::string;
using std::getline;
using std::ifstream;

// Global Function Declarations
vector<Point> generateRandomPoints(int number);
vector<vector<Point>> edgesToPoints(vector<Edge> edgeList);

// Global Variables
double range = 1000.0; // Points will have a max x and y of +- this value 
vector<Point> pointList; // Master list of points, used everywhere

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

		// Get info for random point generator
		int totalPoints = 0, pointsPerLine = 0;
		double collinearRatio = 0;
		cout << "Total number of points to generate (positive integer): ";
		cin >> totalPoints;
		cout << "Ratio of points that will be collinear (double from 0.0 to 1.0): ";
		cin >> collinearRatio;
		cout << "Average number of collinear of points on each unique line," << endl
			<< "will vary randomly by +- half of this value. (int 2 or larger): ";
		cin >> pointsPerLine;
		cout << endl;

		// Generate points
		randomizeSeed();
		int colPoints = (int)((double)totalPoints * collinearRatio);
		int randomPoints = totalPoints - colPoints;
        for(int i = 0; i < randomPoints; i++) {
			double x = randReal(range * -1, range);
			double y = randReal(range * -1, range);
			pointList.push_back(Point(x, y));
			cout << "Generated random point " << pointList.back() << endl;
		}
		for(int i = 0; i < colPoints;) {
			double m = randReal(-50.0, 50.0);
			double b = randReal(range * -1, range);
			int pointsThisLine = randInt(pointsPerLine - (pointsPerLine / 2),
				pointsPerLine + (pointsPerLine / 2));
			int j = 0;
			while(j < pointsThisLine && i < colPoints) {
				double x = randReal(range * -1, range);
				double y;
				do {
					y = (m * x) + b;
				} while(abs(y) <= 1000);
				cout << "Generated collinear point " << pointList.back() << endl;
				j++;
				i++;
			}
		}
	}

	else {
		// Read points from the file
		while(!infile.eof()) {
			double x = 0, y = 0;
			infile >> x >> y;
			pointList.push_back(Point(x, y));
		}
		cout << "Seccesfully read " << pointList.size() << " points." << endl;
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

	// Find collinear points
	// 
	vector<Edge> edgeListB;
	vector<vector<Point>> answerList;
	int temp(1);
	while (temp==1) {
		if (edgeList[0] == edgeList[1]) {
			edgeListB.push_back(edgeList[0]);
			edgeList.erase(edgeList.begin());
			if (edgeList.size() == 1) {
				edgeListB.push_back(edgeList[0]);
				edgeList.erase(edgeList.begin());
				answerList = edgesToPoints(edgeListB);
			}
		}
		else {
			edgeListB.push_back(edgeList[0]);
			if (edgeList.size() == 1) {
				edgeList.erase(edgeList.begin());
			}
			if (edgeListB.size() >= 4) {
				answerList = edgesToPoints(edgeListB);
			}
			edgeListB.clear();
		}
		if (edgeList.size() == 0) {
			temp = 0;
		}
	}

}

// Global Function Deffinions
vector<Point> generateRandomPoints(int number) {
	vector<Point> list = vector<Point>();
	randomizeSeed();
	for (int i = 0; i < number; i++) {
		list.push_back(Point(randReal(-1 * range, range), randReal(-1 * range, range)));
	}
	return list;
}


// incomplete!
vector<vector<Point>> edgesToPoints(vector<Edge> edgeList) {
	vector<vector<Point>> answers;
	for each (Edge e in edgeList) {

	}
	return answers;
}