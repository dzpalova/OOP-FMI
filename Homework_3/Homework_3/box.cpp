#include<iostream>
#include "box.h"
using namespace std;

Box::Box(double length, double width, double height) {
	this->length = length;
	this->width = width;
	this->height = height;
}

double Box::volume() {
	return length * width*height;
}

void Box::print() const {
	cout << "The length is: " << length
		<< " , the width is: " << width
		<< " , the height is: " << height << endl;
}

ostream & operator<<(ostream & os, const Box & box) {
	os << box.length << " " << box.width << " " << box.height << endl;
	return os;
}
