#include "Rock.h"

unsigned Rock::capacity = ROCK_MAX_CAPACITY;

Rock::Rock(const char * name, double priceVodka, double priceWhiskey) : Club(name, priceVodka, priceWhiskey) { }

void Rock::setMinPriceVodka(double price) {
	if (price < ROCK_MIN_PRICE_VODKA) {
		price = ROCK_MIN_PRICE_VODKA;
	}
	minPriceVodka = price;
}

void Rock::setMinPriceWhisley(double price) {
	if (price < ROCK_MIN_PRICE_WHISKEY) {
		price = ROCK_MIN_PRICE_WHISKEY;
	}
	minPriceWhiskey = price;
}

Club * Rock::clone() const {
	return new Rock(*this);
}


