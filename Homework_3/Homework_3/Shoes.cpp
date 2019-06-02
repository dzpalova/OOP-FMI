#include "shoes.h"

Shoes::Shoes(Box box, const char* addres, double transportPriceForKg, int countElements, bool canBeTried)
	:Item(box, addres, transportPriceForKg, countElements) {
	this->canBeTried = canBeTried;
}

double Shoes::transportPrice() const {
	double tempPrice = Item::transportPrice();
	if (canBeTried) {
		tempPrice = tempPrice * 3 / 100;
		tempPrice += Item::transportPrice();
	}
	return tempPrice;
}

void Shoes::showData() const {
	showCommonData();
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