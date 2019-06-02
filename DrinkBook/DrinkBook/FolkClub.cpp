#include "FolkClub.h"

unsigned FolkClub::capacity = FOLK_MAX_CAPACITY;

void FolkClub::copy(const FolkClub& other) {
	performer = new char[strlen(other.performer) + 1];
	strcpy_s(performer, strlen(other.performer) + 1, other.performer);
	if (other.capacity > FOLK_MAX_CAPACITY) {
		capacity = FOLK_MAX_CAPACITY;
	}
	else {
		capacity = other.capacity;
	}
}

FolkClub::FolkClub(const char* name, double priceVodka, double priceWhiskey, const char* performer) : Club(name, priceVodka, priceWhiskey) {
	this->performer = new char[strlen(performer) + 1];
	strcpy_s(this->performer, strlen(performer) + 1, performer);
	capacity++;
}


FolkClub::FolkClub(const FolkClub& other) : Club(other) {
	copy(other);
}

FolkClub& FolkClub::operator=(const FolkClub& other) {
	if (this != &other) {
		delete[] performer;
		Club::operator=(other);
		copy(other);
	}
	return *this;
}

FolkClub::~FolkClub() {
	delete[] performer;
	capacity--;
}

unsigned FolkClub::getCapacity() const {
	return capacity;
}

void FolkClub::setMinPriceVodka(double price) {
	if (price < FOLK_MIN_PRICE_VODKA) {
		price = FOLK_MIN_PRICE_VODKA;
	}
	minPriceVodka = price;
}

void FolkClub::setMinPriceWhisley(double price) {
	if (price < FOLK_MIN_PRICE_WHISKEY) {
		price = FOLK_MIN_PRICE_WHISKEY;
	}
	minPriceWhiskey = price;
}

Club * FolkClub::clone() const {
	return new FolkClub(*this);
}
