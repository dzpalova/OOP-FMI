#include "WaterVehicle.h"

void WaterVehicle::copyTurbines(const WaterVehicle& other) {
	count = other.count;
	curr = other.curr;
	turbines = new int[other.count];
	for (int i = 0; i < curr; i++) {
		turbines[i] = other.turbines[i];
	}
}

bool WaterVehicle::resize() {
	int* buffer = new int[count * 2];
	if (buffer == NULL) { return false; }
	for (int i = 0; i < curr; i++) {
		buffer[i] = turbines[i];
	}
	delete[] turbines;
	count *= 2;
	turbines = buffer;
	return true;
}

WaterVehicle::WaterVehicle(const char* motor, int count) : Vehicle(motor) {
	curr = 0;
	this->count = count;
	turbines = new int[count];
}

WaterVehicle::WaterVehicle(const WaterVehicle& other) : Vehicle(other) {
	copyTurbines(other);
}

WaterVehicle& WaterVehicle::operator=(const WaterVehicle& other) {
	if (this != &other) {
		Vehicle::operator=(other);
		delete[] turbines;
		copyTurbines(other);
	}
	return *this;
}

WaterVehicle::~WaterVehicle() {
	delete[] turbines;
}

Vehicle * WaterVehicle::clone() {
	return new WaterVehicle(*this);
}

bool WaterVehicle::addTurbine(int newTurbine) {
	if (curr >= count && !resize()) {
		return false;
	}
	turbines[curr++] = newTurbine;
	return true;
}

double WaterVehicle::findForce() const {
	double temp = 0;
	for (int i = 0; i < count; i++) {
		temp += turbines[i];
	}
	return temp / count;
}

void WaterVehicle::print() const {
	std::cout << motor << std::endl;
	for (int i = 0; i < curr; i++) {
		std::cout << turbines[i] << " ";
	}
	std::cout << std::endl;
}

