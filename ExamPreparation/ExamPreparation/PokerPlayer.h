#include <iostream>
#include "Hand.h"

class Player {
protected:
	char* name;
	int skill;
	double points;

	Hand* hand;
	void copy(const char* = "", int = 0);
public:
	Player(const char* = "", int = 0);
	Player(const Player&);
	Player& operator=(const Player&);
	~Player();

	virtual void setSkill(int) = 0;
	virtual void setPoints() = 0;
	virtual Player* clone() = 0;

	double getPoints() const { return points; }
};

class Amateur : public Player {
public:
	Amateur(const char* name, int skill) : Player(name, skill) {}
	virtual void setSkill(int skill) {
		if (skill < 1 || skill > 10) {
			skill = 1;
		}
		this->skill = skill;
	}

	virtual void setPoints() {
		points = hand->getPoints();
		if (points == 2) {
			this->points = skill * points;
		}
		else if (points == 5 || points == 9) {
			this->points = (skill * points) / 2;
		}
		else {
			this->points = 0;
		}
	}

	virtual Player* clone() {
		return new Amateur(*this);
	}
};

class SemiProfessional :public Player {
public:
	SemiProfessional(const char* name, int skill) : Player(name, skill) {}
	virtual void setSkill(int skill) {
		if (skill < 11 || skill > 20) {
			skill = 11;
		}
		this->skill = skill;
	}
	virtual void setPoints() {
		points = hand->getPoints();
		if (points == 2 || points == 5) {
			this->points = skill * points;
		}
		else if (points == 9) {
			this->points = ((skill * points) * 3) / 4;
		}
		else {
			this->points = 0;
		}
	}

	virtual Player* clone() {
		return new SemiProfessional(*this);
	}
};

class Professional : public Player {
public:
	Professional(const char* name, int skill) : Player(name, skill) {}
	virtual void setSkill(int skill) {
		if (skill < 21 || skill > 30) {
			skill = 21;
		}
		this->skill = skill;
	}
	virtual void setPoints() {
		points = hand->getPoints();
		if (points == 2 || points == 5 || points == 9) {
			this->points = skill * points;
		}
		else {
			this->points = 0;
		}
	}

	virtual Player* clone() {
		return new Professional(*this);
	}
};

