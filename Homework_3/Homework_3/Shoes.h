#pragma once
#include"item.h"

class Shoes : public Item {
	bool canBeTried;
public:
	Shoes(Box = BOX, const char* = "", double = 0.0, int = 0, bool = false);
	double price() const;
	void showDataForShoes() const;

	virtual Item* clone();
};