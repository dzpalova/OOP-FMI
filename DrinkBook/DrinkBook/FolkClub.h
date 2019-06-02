#include "Club.h"

const unsigned FOLK_MAX_CAPACITY = 70;
const double FOLK_MIN_PRICE_VODKA = 20.0;
const double FOLK_MIN_PRICE_WHISKEY = 35.0;

class FolkClub : public Club {
	static unsigned capacity;
	char* performer;
	void copy(const FolkClub&);

	virtual void setMinPriceVodka(double);
	virtual void setMinPriceWhisley(double);
	virtual Club* clone() const;

public:
	FolkClub(const char* = "", double = 0.0, double = 0.0, const char* = "");
	FolkClub(const FolkClub&);
	FolkClub& operator=(const FolkClub&);
	~FolkClub();

	unsigned getCapacity() const;
};