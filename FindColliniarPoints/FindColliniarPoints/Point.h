#pragma once

// Point.h
// Chris Ruiz - CR

// 2015-Oct-4
// A random point class. May be handy.

#include <iostream>

class Point {
public:
	Point();
	Point(double X, double Y);
	~Point();	
	void setX(double X);
	void setY(double Y);
	double getX() const;
	double getY() const;

private:
	double _X;
	double _Y;
};