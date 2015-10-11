// Edge.cpp
// Edge class that holds 2 points and a slope
// Meghan Haukaas
// 2015-Oct-11

#pragma once

#include "Line2.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

Line2::Line2() {
	_one = Edge();
	_two = Edge();
}

Line2::Line2(Edge one, Edge two) {
	_one = one;
	_two = two;
}

void Line2::set1(Edge one) {
	_one = one;
}

void Line2::set2(Edge two) {
	_two = two;
}

Edge Line2::get1() const {
	return _one;
}

Edge Line2::get2() const {
	return _two;
}

bool Line2::equalSlopes() {
	if (_one.getSlope() == _two.getSlope()) {
		return true;
	}
	return false;
}

ostream& operator<< (ostream& os, const Line2& l) {
	os << l.get1() << ", " << l.get2() << endl;
	return os;
}
