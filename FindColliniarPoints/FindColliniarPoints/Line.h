#pragma once

// Line.h
// Chris Ruiz - CR

// 2015-Oct-4
// May be handy as well. Depends on our implementation.

#include "Point.h"
#include <set>
using std::set;


class Line {
public:
	Line(Point first, Point second); 
	~Line();
	double getSlope();
	friend ostream& operator<< (ostream& os, Line& l);

private:
	set<Point> collection; // Contains the known points in the line.
	double slope; // Carries the slope of the line. DBL_MAX indicates a slope of infinity.
}; 
