#include "Vehicle.h"

void Vehicle::copy(const char * motor) {
	this->motor = new char[strlen(motor) + 1];
	strcpy_s(this->motor, strlen(motor) + 1, motor);
}

Vehicle::Vehicle(const char* motor) {
	copy(motor);
}

Vehicle::Vehicle(const Vehicle& other) {
	copy(other.motor);
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
	if (this != &other) {
		delete[] motor;
		copy(other.motor);
	}
	return *this;
}

Vehicle::~Vehicle() {
	delete[] motor;
}

const char * Vehicle::getMotor() const {
	return motor;
}

