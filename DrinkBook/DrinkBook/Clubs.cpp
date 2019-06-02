#include "Clubs.h"

bool Clubs::resize() {
	Club** temp = new Club*[capacity * 2];
	if (temp == NULL) {
		return false;
	}
	for (int i = 0; i < capacity; i++) {
		temp[i] = clubs[i];
	}
	delete[] clubs;
	capacity *= 2;
	clubs = temp;
	return true;
}

void Clubs::copy(const Clubs& other) {
	clubs = new Club*[other.capacity];
	for (int i = 0; i < currPos; i++) {
		clubs[i] = other.clubs[i]->clone();
	}
	capacity = other.capacity;
	currPos = other.currPos;
}

void Clubs::clean() {
	for (int i = 0; i < currPos; i++) {
		delete clubs[i];
	}
	delete[] clubs;
}

Clubs::Clubs(int capacity) {
	this->capacity = capacity;
	clubs = new Club*[capacity];
	currPos = 0;
}

Clubs::Clubs(const Clubs& other) {
	copy(other);
}

Clubs & Clubs::operator=(const Clubs& other) {
	if (this != &other) {
		clean();
		copy(other);
	}
	return *this;
}

Clubs::~Clubs() {
	clean();
}

bool Clubs::addFolkClub(const char * name, double priceVodka, double priceWhiskey, const char * performer) {
	if (currPos >= capacity && !resize()) {
		return false;
	}

	clubs[currPos++] = new FolkClub(name, priceVodka, priceWhiskey, performer);

	return true;
}

bool Clubs::addRockClub(const char * name, double priceVodka, double priceWhiskey) {
	if (currPos >= capacity && !resize()) {
		return false;
	}

	clubs[currPos++] = new Rock(name, priceVodka, priceWhiskey);

	return true;
}

bool Clubs::addHouseClub(const char * name, double priceVodka, double priceWhiskey, int numDG) {
	if (currPos >= capacity && !resize()) {
		return false;
	}

	clubs[currPos++] = new Haus(name, priceVodka, priceWhiskey, numDG);

	return true;
}
