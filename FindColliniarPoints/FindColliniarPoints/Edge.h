// Edge.h
// Edge class with 2 points and a slope
// Meghan Haukaas
// 2015-Oct-11

#pragma once

#include <iostream>
#include "Point.h"
using std::ostream;

class Edge {
public:
	Edge();
	Edge(Point one, Point two);
	void set1(Point one);
	void set2(Point two);
	void setSlope();
	Point get1() const;
	Point get2() const;
	double getSlope() const;
	double getIntercept() const;

private:
	Point _one;
	Point _two;
	double _slope;
	double _intercept; // "b" value
};

ostream& operator<< (ostream& os, const Edge& e);
bool operator< (const Edge & lhs, const Edge & rhs);