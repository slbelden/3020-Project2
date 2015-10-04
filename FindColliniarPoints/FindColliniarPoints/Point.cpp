// Point.cpp
// A random point class. May be handy.
// Chris Ruiz - CR

// 2015-Oct-4

#pragma once

#include "Point.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

Point::Point() {
	_X = 0.0;
	_Y = 0.0;
}

Point::Point(double X, double Y) {
	_X = X;
	_Y = Y;
}

void Point::setX(double X) {
	_X = X;
}

void Point::setY(double Y) {
	_Y = Y;
}

double Point::getX() const {
	return _X;
}

double Point::getY() const {
	return _Y;
}

ostream& operator<< (ostream& os, const Point& p) {
	os << "(" << p.getX() << ", " << p.getY() << ")";
	return os;
}
