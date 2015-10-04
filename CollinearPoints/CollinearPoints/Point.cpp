#pragma once

// Point.cpp
// Chris Ruiz - CR

// 2015-Oct-4
// A random point class. May be handy.

#include "Point.h"

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

// Somewhat arbitrary, but it works.
Point::Point() {
	_X = 0;
	_Y = 0;
}

Point::Point(double X, double Y) {
	_X = X;
	_Y = Y;
}

Point::~Point() { }

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

