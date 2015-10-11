// Line.cpp
// Line class that holds 2 edges
// Meghan Haukaas
// 2015-Oct-11

#pragma once

#include "Line.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

Line::Line() {
	_one = Edge();
	_two = Edge();
}

Line::Line(Edge one, Edge two) {
	_one = one;
	_two = two;
}

void Line::set1(Edge one) {
	_one = one;
}

void Line::set2(Edge two) {
	_two = two;
}

Edge Line::get1() const {
	return _one;
}

Edge Line::get2() const {
	return _two;
}

bool Line::equalSlopes() {
	if (_one.getSlope() == _two.getSlope()) {
		return true;
	}
	return false;
}

ostream& operator<< (ostream& os, const Line& l) {
	os << l.get1() << ", " << l.get2() << endl;
	return os;
}
