#include "Club.h"

bool Club::copy(const Club & other) {
	name = new char[strlen(other.name) + 1];
	if (name == NULL) {
		return false;
	}
	strcpy_s(name, strlen(name) + 1, other.name);
	setMinPriceVodka(other.minPriceVodka);
	setMinPriceWhisley(other.minPriceWhiskey);
}

Club::Club(const char * name, double priceVodka, double priceWhiskey) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name); //check
	setMinPriceVodka(priceVodka);
	setMinPriceWhisley(priceWhiskey);
}

Club::Club(const Club & other) {
	copy(other);
}

Club & Club::operator=(const Club& other)
{
	if (this != &other) {
		delete[] name;
		copy(other);
	}

	return *this;
}

Club::~Club() {
	delete[] name;
}

