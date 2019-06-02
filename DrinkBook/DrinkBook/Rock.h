#include "Club.h"

const unsigned ROCK_MAX_CAPACITY = 30;
const double ROCK_MIN_PRICE_VODKA = 20.0;
const double ROCK_MIN_PRICE_WHISKEY = 35.0;


class Rock :public Club {
	static unsigned capacity;

	virtual void setMinPriceVodka(double);
	virtual void setMinPriceWhisley(double);
	virtual Club* clone() const;
public:
	Rock(const char* = "", double = 0.0, double = 0.0);
};
