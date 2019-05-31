#include "PokerPlayer.h"

void Player::copy(const char * name, int skill) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	setSkill(skill);
}

Player::Player(const char * name, int skill) {
	copy(name, skill);
}

Player::Player(const Player& other) {
	copy(other.name, other.skill);
}

Player & Player::operator=(const Player & other) {
	if (this != &other) {
		delete[] name;
		copy(name, skill);
	}
	return *this;
}

Player::~Player() {
	delete[] name;
}
