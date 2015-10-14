// Point.h
// A random point class. May be handy.
// Chris Ruiz - CR

// 2015-Oct-4

#pragma once

#include <iostream>
using std::ostream;

class Point {
public:
	Point();
	Point(double X, double Y);
	void setX(double X);
	void setY(double Y);
	double getX() const;
	double getY() const;

private:
	double _X;
	double _Y;
};

ostream& operator<< (ostream& os, const Point& p);
bool operator== (const Point & lhs, const Point & rhs);
bool operator!= (const Point & lhs, const Point & rhs);