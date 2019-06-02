#include <iostream>

class Club {
protected:
	char* name;
	double minPriceVodka;
	double minPriceWhiskey;
	bool copy(const Club&);

	virtual void setMinPriceVodka(double) = 0;
	virtual void setMinPriceWhisley(double) = 0;


public:
	virtual Club* clone() const = 0;
	Club(const char* = "", double = 0.0, double = 0.0);
	Club(const Club&);
	Club& operator=(const Club&);
	virtual ~Club();
};