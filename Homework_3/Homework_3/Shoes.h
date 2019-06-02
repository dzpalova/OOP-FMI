#pragma once
#include"item.h"

class Shoes : public Item {
	bool canBeTried;
public:
	Shoes(Box = BOX, const char* = "", double = 0.0, int = 0, bool = false);
	virtual double transportPrice() const;
	virtual void showData() const;

	virtual Item* clone();
};