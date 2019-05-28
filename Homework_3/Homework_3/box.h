#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include <fstream>

using namespace std;
class Box {
private:
	double length;
	double width;
	double height;
public:
	Box(double = 0.0, double = 0.0, double = 0.0);
	double volume();
	void print() const;

	friend ostream& operator<<(ostream&, const Box&);
};

