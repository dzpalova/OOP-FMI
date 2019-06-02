#include"furniture.h"

void Furniture::copyFurniture(const Furniture & other) {
	mark = new char[strlen(other.mark) + 1];
	strcpy_s(mark, strlen(other.mark) + 1, other.mark);
}

Furniture::Furniture(Box box, const char* addres, double transportPriceForKg, int countElements, const char* mark)
	:Item(box, addres, transportPriceForKg, countElements) {
	this->mark = new char[strlen(mark) + 1];
	strcpy_s(this->mark, strlen(mark) + 1, mark);
}

Furniture::Furniture(const Furniture & other) : Item(other) {
	copyFurniture(other);
}

Furniture & Furniture::operator=(const Furniture & other) {
	if (this != &other) {
		Item::operator=(other);
		delete[] mark;
		copyFurniture(other);
	}
	return *this;
}

Furniture::~Furniture() {
	delete[] mark;
}

bool Furniture::isFrangible() const {
	for (int i = 0; i < curr; i++) {
		if (elements[i].isFrangible()) {
			return true;
		}
	}
	return false;
}

double Furniture::transportPrice() const {
	double tempPrice = Item::transportPrice();
	if (isFrangible()) {
		tempPrice = tempPrice * 1.5 / 100;
		tempPrice += Item::transportPrice();
	}
	return tempPrice;
}

void Furniture::showData() const {
	showCommonData();
	cout << endl << "The mark is : " << mark << endl;
}

Item* Furniture::clone() {
	return new Furniture(*this);
}