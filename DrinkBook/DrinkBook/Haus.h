#include "Club.h"

const double HAUS_MIN_PRICE_VODKA = 30.0;
const double HAUS_MIN_PRICE_WHISKEY = 40.0;

class Haus : public Club {
	int numDJ;

	virtual void setMinPriceVodka(double);
	virtual void setMinPriceWhisley(double);
	virtual Club* clone() const;

public:
	Haus(const char* = "", double = 0.0, double = 0.0, int = 0);
};

