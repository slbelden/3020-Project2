// Stephen Belden - SB
// Meghan Haugaas - MH
// Chris Ruiz - CR

// 2015-Sept-28

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

#include "Point.h"
#include "Line.h"

// These only play nice is if it sits in main. Friend functions are weird....
ostream& operator<< (ostream& os, Line& l) {
	for (set<Point>::iterator it = l.collection.begin(); it != l.collection.end(); it++) {
		os << *it << " ";
	}
}

ostream& operator<< (ostream& os, const Point& p) {
	os << "(" << p.getX() << ", " << p.getY() << ")";
	return os;
}

int main() {
	cout << "Hello World." << endl; 
	// Hi, Stephen. 
}

