#pragma once
#include"material.h"
#include <fstream>
#include <iostream>
using namespace std;
const Material MATERIAL = Material();

class Element {
private:
	Material material;
	double kilogram;
public:
	Element(Material = MATERIAL, double = 0.0);
	bool isFrangible() const;
	void print() const;

	double getKilogram() const;
	friend ostream& operator<<(ostream&, Element&);
};
