#pragma warning(disable:4996)
#pragma once
//#include<cstring>
#include "item.h"

class Furniture : public Item {
private:
	char* mark;
	void copyFurniture(const Furniture&);
public:
	Furniture(Box = BOX, const char* = "", double = 0.0, int = 0, const char* = "");
	Furniture(const Furniture&);
	Furniture& operator=(const Furniture&);
	~Furniture();

	double weightFurniture() const;
	bool isFrangible() const;
	double priceForTransoprt() const;

	virtual Item* clone();
};