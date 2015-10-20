// Given n points in a plane, this algorithm will find all groups of 4 or more
// collinear points in O(N^2 log N) time.
// The algorithm can correctly handle parallel lines, treating them as 2
// distinct collinear lines, and can handle n points on any line.
// This program can also generate sets of random example points.

// Stephen Belden - SB
// Meghan Haugaas - MH
// Chris Ruiz - CR

// 2015-Oct-19

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
vector<Point> edgesToPoints(vector<Edge> edgeList);

// Global Variables
double range = 1000.0; // The max |x| and |y| of generated points 
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
		cout << "Switching to random point generation instead..."
			<< endl << endl;

		// Get info for random point generator
		int totalPoints = 0, pointsPerLine = 0;
		double collinearRatio = 0;
		cout << "Total number of points to generate (positive integer): ";
		cin >> totalPoints;
		cout << "Ratio of points that will be collinear (decimal from 0.0 to 1.0): ";
		cin >> collinearRatio;
		cout << "Number of collinear of points on each unique line (positive integer): ";
		cin >> pointsPerLine;

		// Generate points
		randomizeSeed();
		// Determine how many of each kind of point to generate
		int colPoints = (int)((double)totalPoints * collinearRatio);
		int randomPoints = totalPoints - colPoints;
		// Generate totally random points
        for(int i = 0; i < randomPoints; i++) {
			double x = randReal(-range, range);
			double y = randReal(-range, range);
			pointList.push_back(Point(x, y));
		}
		// Generate points guaranteed to be collinear
		for(int i = 0; i < colPoints;) {
			double m = randReal(-50.0, 50.0);
			double b = randReal(-range, range);
			int j = 0;
			while(j < pointsPerLine && i < colPoints) {
				double x, y;
				// Ensure that the absolute value of y is less than range
				do {
					x = randReal(-range, range);
					y = (m * x) + b;
				} while((abs(y)) >= range);
				pointList.push_back(Point(x, y));
				j++;
				i++;
			}
		}
		// Shuffle the random and collinear points together
		random_shuffle(pointList.begin(), pointList.end());
		cout << "Generated " << pointList.size() << " total points." << endl;
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
	// O(K log K), where K is N^2 elements
	sort(edgeList.begin(), edgeList.end());

	// Find collinear points
	//O(K), where K is N^2 elements
	vector<Edge> matchedEdges;
	vector<vector<Point>> answerList;
	// Don't bother looking for groups of collinear points if there aren't
	// at least 3 edges. This check also makes sure there are enough
	// items in the list to avoid accessing an element that doesn't exist.
	if(edgeList.size() < 3) {
		cout << endl
			<< "Not enough input points to find collinear points."
			<< endl << endl;
		exit(1);
	}
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
	cout << endl;
	if(answerList.size() <= 0) {
		cout << "No groups of 4 or more collinear points." << endl << endl;
	}
	else {
		int n = 1;
		for each (vector<Point> v in answerList) {
			cout << "Line " << n << " has "
				<< v.size() << " collinear points: ";
			int p = 0;
			// Print first two points directly beside text
			// This is safe because any v will have at least 4 points
			cout << v[p] << ", ";
			p++;
			cout << v[p] << ", ";
			p++;
			// Print the rest of the points, 3 per line, indented
			while(p < v.size()) {
				if((p + 1) % 3 == 0) cout << endl << "\t";
				cout << v[p] << ", ";
				p++;
			}
			cout << endl << endl;
			n++;
		}
	}
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