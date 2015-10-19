// Given n points in a plane, this algorithm will find all groups of 4 or more
// collinear points in O(N^2 log N) time (probably).
// The algorithm can correctly handle parallel lines, treating them as 2
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
using std::random_shuffle;
using std::abs;
using std::string;
using std::getline;
using std::ifstream;

// Global Function Declarations
vector<Point> generateRandomPoints(int number);
vector<Point> edgesToPoints(vector<Edge> edgeList);

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
			double x = randReal(-range, range);
			double y = randReal(-range, range);
			pointList.push_back(Point(x, y));
			cout << "Generated random point " << pointList.back() << endl;
		}
		for(int i = 0; i < colPoints;) {
			double m = randReal(-50.0, 50.0);
			double b = randReal(-range, range);
			int pointsThisLine = randInt(pointsPerLine - (pointsPerLine / 2),
				pointsPerLine + (pointsPerLine / 2));
			int j = 0;
			while(j < pointsThisLine && i < colPoints) {
				double x, y;
				do {
					x = randReal(-range, range);
					y = (m * x) + b;
				} while((abs(y)) >= range);
				pointList.push_back(Point(x, y));
				cout << "Generated collinear point " << pointList.back() << endl;
				j++;
				i++;
			}
		}
		random_shuffle(pointList.begin(), pointList.end());
	}

	else {
		// Read points from the file
		while(!infile.eof()) {
			double x = 0, y = 0;
			infile >> x >> y;
			pointList.push_back(Point(x, y));
		}
		cout << "Succesfully read " << pointList.size() << " points." << endl;
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
	cout << "Some edges from the list: " << endl;
	for(int i = 0; i < 20; i++) {
		cout << "Edge " << i << " is " << edgeList[i] << endl;
	}

	// Find collinear points
	// 
	vector<Edge> matchedEdges;
	vector<vector<Point>> answerList;
	if (edgeList.size() < 2) exit(1);
	while (!edgeList.empty()) {
		if (edgeList[0] == edgeList[1]) {
			matchedEdges.push_back(edgeList[0]);
			edgeList.erase(edgeList.begin());
			if (edgeList.size() == 1) {
				matchedEdges.push_back(edgeList[0]);
				edgeList.erase(edgeList.begin());
				if (matchedEdges.size() >= 4) {
					answerList.push_back(edgesToPoints(matchedEdges));
				}
			}
		}
		else {
			matchedEdges.push_back(edgeList[0]);
			edgeList.erase(edgeList.begin());
			if (edgeList.size() == 1) {
				edgeList.erase(edgeList.begin());
			}
			if (matchedEdges.size() >= 4) {
				answerList.push_back(edgesToPoints(matchedEdges));
			}
			matchedEdges.clear();
		}
	}

	// Print the lines with collinear points
	for each (vector<Point> v in answerList) {
		cout << "This line contains the points ";
		for each (Point p in v) {
			cout << p << ", ";
		}
		cout << endl;
	}

}

// Global Function Definitons
vector<Point> generateRandomPoints(int number) {
	vector<Point> list = vector<Point>();
	randomizeSeed();
	for (int i = 0; i < number; i++) {
		list.push_back(Point(randReal(-1 * range, range), randReal(-1 * range, range)));
	}
	return list;
}

// Take a vector of Edges and make it into a vector
// of non-repeating Points
vector<Point> edgesToPoints(vector<Edge> edgeList) {
	vector<Point> answers;
	for each (Edge e in edgeList) {
		bool oneInList(false);
		bool twoInList(false);
		if (answers.empty()) {
			answers.push_back(e.get1());
		}
		for each (Point p in answers) {
			if (p == e.get1()) {
				oneInList = true;
			}
			if (p == e.get2()) {
				twoInList = true;
			}
		}
		if (!oneInList) {
			answers.push_back(e.get1());
		}
		if (!twoInList) {
			answers.push_back(e.get2());
		}
	}
	return answers;
}