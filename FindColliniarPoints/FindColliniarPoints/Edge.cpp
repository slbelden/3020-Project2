// Edge.cpp
// Edge class that holds 2 points and a slope
// Meghan Haukaas
// 2015-Oct-11

#pragma once

#include "Edge.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;


Edge::Edge() {
	_one = Point();
	_two = Point();
	_slope = 0.0;
}

Edge::Edge(Point one, Point two) {
	_one = one;
	_two = two;
	setSlope(one, two);
	_slope = getSlope();
}

void Edge::set1(Point one) {
	_one = one;
}

void Edge::set2(Point two) {
	_two = two;
}

void Edge::setSlope(Point one, Point two) {
	double x;
	double y;
	double slope;
	x = (two.getX() - one.getX());
	y = (two.getY() - one.getY());
	if (x = 0) {
		slope = std::numeric_limits<double>::infinity();
	}
	else {
		slope = (y / x);
	}
	_slope = slope;
}

Point Edge::get1() const {
	return _one;
}

Point Edge::get2() const {
	return _two;
}

double Edge::getSlope() const {
	return _slope;
}

ostream& operator<< (ostream& os, const Edge& e) {
	os << "(" << e.get1() << ", " << e.get2() << ")" << " Slope: " 
		<< e.getSlope();
	return os;
}
