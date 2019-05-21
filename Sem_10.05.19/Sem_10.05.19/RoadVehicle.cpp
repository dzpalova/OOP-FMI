#include "RoadVehicle.h"

RoadVehicle::RoadVehicle(const char* motor, const char* name, int age) :Vehicle(motor) {
	setName(name);
	setAge(age);
}

RoadVehicle::RoadVehicle(const RoadVehicle& other) : Vehicle(other) {
	setName(other.name);
	setAge(other.age);
}

RoadVehicle& RoadVehicle::operator=(const RoadVehicle& other) {
	if (this != &other) {
		Vehicle::operator=(other);
		delete[] name;
		setName(other.name);
		setAge(other.age);
	}
	return *this;
}

RoadVehicle::~RoadVehicle() {
	delete[] name;
}

double RoadVehicle::findForce() const {
	int num = 0;
	for (int i = 0; i < strlen(name); i++) {
		if (name[i] != 'a'&&name[i] != 'e'&&name[i] != 'i'&&name[i] != 'u', name[i] != 'o') {
			num++;
		}
	}
	return num * age;
}

Vehicle * RoadVehicle::clone() {
	return new RoadVehicle(*this);
}

void RoadVehicle::setName(const char * name) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void RoadVehicle::setAge(int age) {
	this->age = age;
}

void RoadVehicle::print() const {
	std::cout << name << " " << age;
}
