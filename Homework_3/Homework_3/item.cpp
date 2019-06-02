#include"item.h"

void Item::copyItem(const Item& other) {
	box = other.box;
	addres = new char[strlen(other.addres) + 1];
	strcpy_s(addres, strlen(other.addres) + 1, other.addres);
	transportPriceForKg = other.transportPriceForKg;
	countElements = other.countElements;
	curr = other.curr;
	elements = new Element[countElements];
	for (int i = 0; i < curr; i++) {
		elements[i] = other.elements[i];
	}
}

void Item::clearItem() {
	delete[] addres;
	delete[] elements;
}


Item::Item(Box box, const char* addres, double transportPriceForKg, int countElements) {
	this->box = box;
	this->addres = new char[strlen(addres) + 1];
	strcpy_s(this->addres, strlen(addres) + 1, addres);
	this->transportPriceForKg = transportPriceForKg;
	this->countElements = countElements;
	this->elements = new Element[countElements];
	curr = 0;
}

Item::Item(const Item& other) {
	copyItem(other);
}

Item& Item::operator=(const Item& other) {
	if (this != &other) {
		clearItem();
		copyItem(other);
	}
	return *this;
}

Item::~Item() {
	clearItem();
}

bool Item::addElement(const Element& item) {
	if (curr >= countElements) {
		cout << "Sorry. You can't add more elements." << endl;
		return false;
	}
	elements[curr++] = item;
	return true;
}

double Item::weightItem() const {
	double temp = 0.0;
	for (int i = 0; i < curr; i++) {
		temp += elements[i].getKilogram();
	}
	return temp;
}

double Item::transportPrice() const {
	double temp = 0.0;
	for (int i = 0; i < curr; i++) {
		temp += (transportPriceForKg*elements[i].getKilogram());
	}
	return temp;
}

void Item::showElements() const {
	for (int i = 0; i < countElements; i++) {
		elements[i].print();
	}
}

void Item::showCommonData() const {
	box.print();
	cout << "The addres for delivery is: " << addres << endl;
	cout << "The transport price for kg is: " << transportPriceForKg << endl;
	cout << "In the item have " << countElements << " elemets: " << endl;
	for (int i = 0; i < countElements; i++) {
		cout << i + 1 << " : ";
		elements[i].print();
	}
}

void Item::showData() const {
	showCommonData();
}

bool Item::saveInFile(const char * fileName) {
	ofstream oFile(fileName);
	if (!oFile) {
		cout << "The file could not be opened!" << endl;
		return false;
	}
	oFile << "The proportions of the box are : " << box << "The addres is : " << addres << endl << "The transport price is : " << transportPriceForKg << endl
		<< "The count of the elements is : " << countElements << endl;
	for (int i = 0; i < curr; i++) {
		oFile << "The " << i + 1 << " element : " << elements[i] << endl;
	}
	oFile.close();
	return true;
}

int Item::getCurr() const {
	return curr;
}

Box Item::getBox() const {
	return box;
}

Item * Item::clone()
{
	return new Item(*this);
}

