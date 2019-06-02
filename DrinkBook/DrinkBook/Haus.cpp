#include "Haus.h"

void Haus::setMinPriceVodka(double price) {
	if (price < HAUS_MIN_PRICE_VODKA) {
		price = HAUS_MIN_PRICE_VODKA;
	}
	minPriceVodka = price;
}

void Haus::setMinPriceWhisley(double price) {
	if (price < HAUS_MIN_PRICE_WHISKEY) {
		price = HAUS_MIN_PRICE_WHISKEY;
	}
	minPriceWhiskey = price;
}

Club* Haus::clone() const {
	return new Haus(*this);
}

Haus::Haus(const char * name, double priceVodka, double priceWhiskey, int numDJ) : Club(name, priceVodka, priceWhiskey) {
	this->numDJ = numDJ;
}
