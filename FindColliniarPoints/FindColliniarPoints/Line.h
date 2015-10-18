// Line.h
// Line class with 2 edges
// Meghan Haukaas
// 2015-Oct-11

#pragma once

#include <iostream>
#include "Edge.h"
using std::ostream;

class Line {
public:
	Line();
	Line(Edge one, Edge two);
	void set1(Edge one);
	void set2(Edge two);
	Edge get1() const;
	Edge get2() const;
	bool equalSlopes();
	bool equalOffset();

private:
	Edge _one;
	Edge _two;
};

ostream& operator<< (ostream& os, const Line& l);

