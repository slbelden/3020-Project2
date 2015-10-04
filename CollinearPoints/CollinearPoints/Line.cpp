#pragma once

// Line.cpp
// Chris Ruiz - CR

#include "Line.h"

#include <iostream>
using std::ostream;
using std::cout;

// CR - Will we ever really have a "blank" line? Meh.

Line::Line(Point first, Point second) {
	if (second.getX() - first.getX() != 0) {
		slope = (second.getY() - first.getY()) / (second.getX() - first.getX());
	}
	else {
		slope = DBL_MAX;
	}

	collection.insert(first);
	collection.insert(second);
}

Line::~Line() { }

double Line::getSlope() {
	return slope;
}

