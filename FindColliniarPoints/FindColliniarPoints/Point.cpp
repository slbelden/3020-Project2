// Point.cpp
// Manages a Cartesian point defined by 2 doubles.
// Chris Ruiz

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

bool operator== (const Point & lhs, const Point & rhs) {
	return (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
}

bool operator!= (const Point & lhs, const Point & rhs) {
	return !operator==(lhs, rhs);
}

ostream& operator<< (ostream& os, const Point& p) {
	os << "(" << p.getX() << ", " << p.getY() << ")";
	return os;
}
