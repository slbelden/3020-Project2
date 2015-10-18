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
	_intercept = 0.0;
}

Edge::Edge(Point one, Point two) {
	_one = one;
	_two = two;
	setSlope();
	// y = mx + b, so b = y - mx
	_intercept = one.getY() - ( _slope * one.getX() );
}

void Edge::set1(Point one) {
	_one = one;
}

void Edge::set2(Point two) {
	_two = two;
}


void Edge::setSlope() {
	double x;
	double y;
	double slope;
	x = (_two.getX() - _one.getX());
	y = (_two.getY() - _one.getY());
	if (x == 0) {
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

double Edge::getIntercept() const {
	return _intercept;
}

bool operator< (const Edge & lhs, const Edge & rhs){
	return lhs.getSlope() < rhs.getSlope();
}

ostream& operator<< (ostream& os, const Edge& e) {
	os << "(" << e.get1() << ", " << e.get2() << ")" << endl << "\tSlope: " 
		<< e.getSlope() << " Intercept: " << e.getIntercept();
	return os;
}

bool compareWithPrecision(double precision, double first, double second) {
	return (abs(second - first) <= precision);
}

bool Edge::operator== (const Edge& rhs) {
	return (compareWithPrecision(_precision, _slope, rhs._slope)
		&& compareWithPrecision(_precision, _intercept, rhs._intercept));
}