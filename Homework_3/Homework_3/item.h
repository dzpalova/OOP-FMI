#pragma warning(disable:4996)
#pragma once
#include "element.h"
#include "box.h"
#include <cstring>
#include <fstream>

const Box BOX = Box();

class Item {
private:
	Box box;
	char* addres;
	double transportPriceForKg;
	int countElements;
protected:
	Element * elements;
	int curr;
private:
	void copyItem(const Item&);
	void clearItem();
public:
	Item(Box = BOX, const char* = "", double = 0.0, int = 0);
	Item(const Item&);
	Item& operator=(const Item&);
	virtual ~Item();

	bool addElement(const Element&);
	double weightItem() const;
	double transportPrice() const;
	void showElements() const;
	void showDataForItem() const;
	bool saveInFile(const char*);

	int getCurr() const;
	Box getBox() const;

	virtual Item* clone();  //po-skoro da q napravq chisto virtualna
};
