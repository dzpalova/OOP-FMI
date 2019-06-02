#include "User.h"

bool User::copy(const User& other) {
	name = new char[strlen(other.name) + 1];
	if (name == NULL) {
		return false;
	}
	years = other.years;
	budget = other.budget;
	numVodka = other.numVodka;
	numWhiskey = other.numWhiskey;
	music = other.music;
	return true;
}

User::User(const char * name, unsigned years, double budget, unsigned numVodka, unsigned numWhiskey, Music music) {
	this->name = new char[strlen(name) + 1]; //check
	strcpy_s(this->name, strlen(name) + 1, name);
	this->years = years;
	this->budget = budget;
	this->numVodka = numVodka;
	this->numWhiskey = numWhiskey;
	this->music = music;
}

User::User(const User& other) {
	copy(other);
}

User & User::operator=(const User& other) {
	if (this != &other) {
		delete[] name;
		copy(other);
	}
	return *this;
}

User::~User() {
	delete[] name;
}
