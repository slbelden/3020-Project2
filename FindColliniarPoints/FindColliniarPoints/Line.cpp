#pragma once

// Line.cpp
// Chris Ruiz - CR

#include "Line.h"
#include "Point.h"
#include <limits>

#include <iostream>
using std::ostream;
using std::cout;

// CR - Will we ever really have a "blank" line? Meh.

Line::Line(Point first, Point second) {
	if (second.getX() - first.getX() != 0) {
		slope = (second.getY() - first.getY()) / (second.getX() - first.getX());
	}
	else {
		slope = std::numeric_limits<double>::infinity();
	}

	collection.insert(first);
	collection.insert(second);
}

Line::~Line() { }

double Line::getSlope() {
	return slope;
}

ostream& operator<< (ostream& os, Line& l) {
	for (set<Point>::iterator it = l.collection.begin(); it != l.collection.end(); it++) {
		os << *it << " ";
	}
}