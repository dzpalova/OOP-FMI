#include "shoes.h"

Shoes::Shoes(Box box, const char* addres, double transportPriceForKg, int countElements, bool canBeTried)
	:Item(box, addres, transportPriceForKg, countElements) {
	this->canBeTried = canBeTried;
}

double Shoes::price() const {
	double tempPrice = transportPrice();
	if (canBeTried) {
		tempPrice = tempPrice * 3 / 100;
		tempPrice += transportPrice();
	}
	return tempPrice;
}

void Shoes::showDataForShoes() const {
	showDataForItem();
	cout << "The shoes ";
	if (canBeTried) {
		cout << "can be tried! " << endl;
	}
	else {
		cout << "can't be tried! " << endl;
	}
}

Item* Shoes::clone() {
	return new Shoes(*this);
}