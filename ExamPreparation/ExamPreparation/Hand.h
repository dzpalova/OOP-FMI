#include<iostream>

class Hand {
protected:
	int points;
public:
	Hand(int points = 0) {
		this->points = points;
	}

	int getPoints() const { return points; }
};

class Pair : public Hand {
public:
	Pair() :Hand(2) {};
};

class ThreeOfAKind : public Hand {
public:
	ThreeOfAKind() :Hand(5) {};
};

class Straight : public Hand {
	Straight() :Hand(9) {};
};