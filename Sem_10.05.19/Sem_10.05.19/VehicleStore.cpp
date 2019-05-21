#include "VehicleStore.h"

void VehicleStore::copy(const VehicleStore& veh) {
	count = veh.count;
	curr = veh.curr;
	for (int i = 0; i < curr; i++) {
		vehicles[i] = veh.vehicles[i];
	}
}

void VehicleStore::clean() {
	for (int i = 0; i < count; i++) {
		delete vehicles[i];
	}
	delete[] vehicles;
}

bool VehicleStore::resize() {
	Vehicle** buffer = new Vehicle*[count * 2];
	if (buffer == NULL) { return false; }
	for (int i = 0; i < count; i++) {
		buffer[i] = vehicles[i];
	}
	clean();
	vehicles = buffer;
	count *= 2;
	return true;
}

bool VehicleStore::insert(Vehicle * veh) {
	if (curr >= count && !resize()) { return false; }
	vehicles[curr++] = veh;
	return true;
}

VehicleStore::VehicleStore(int count) {
	this->count = count;
	curr = 0;
	vehicles = new Vehicle*[count];
}

VehicleStore::VehicleStore(const VehicleStore& veh) {
	copy(veh);
}

VehicleStore& VehicleStore::operator=(const VehicleStore& veh) {
	if (this != &veh) {
		clean();
		copy(veh);
	}
	return *this;
}

VehicleStore::~VehicleStore() {
	clean();
}

WaterVehicle * VehicleStore::createWaterVehicle(const char* name)
{
	int countTurbines;
	std::cout << "Enter num turbines for your Water Vehicle: ";
	std::cin >> countTurbines;
	WaterVehicle* waterVeh = new WaterVehicle(name, countTurbines);
	for (int i = 0; i < countTurbines; i++) {
		int turb;
		std::cout << "Enter turbine " << i + 1 << " : ";
		std::cin >> turb;
		waterVeh->addTurbine(turb);
	}
	return waterVeh;
}

RoadVehicle * VehicleStore::createRoadVehicle(const char * nameMotor) {
	char name[20];
	std::cout << "Enter name for your Road Vehicle: ";
	std::cin >> name;
	int age;
	std::cout << "Enter age for your Road Vehicle: ";
	std::cin >> age;
	RoadVehicle* roadVeh = new RoadVehicle(nameMotor, name, age);
	return roadVeh;
}

void VehicleStore::addVehicle() {
	char name[20];
	std::cout << "Enter name for the motor: ";
	std::cin >> name;
	bool x;
	std::cout << "Enter 1 if you want to make Road Vehicle or 0 if you want to make Water Vehicle:";
	std::cin >> x;
	if (x == 0) { vehicles[curr++] = createWaterVehicle(name); }
	if (x == 1) { vehicles[curr++] = createRoadVehicle(name); }
}

const char * VehicleStore::getNameOfTheMostPowerfullMotor() const {
	double max = 0;
	int maxIndex;
	for (int i = 0; i < count; i++) {
		if (max < vehicles[i]->findForce()) {
			max = vehicles[i]->findForce();
			maxIndex = i;
		}
	}
	return vehicles[maxIndex]->getMotor();
}

void VehicleStore::printNameAndForce() const {
	for (int i = 0; i < count; i++) {
		std::cout << "Motor " << i + 1 << " : Name : " << vehicles[i]->getMotor()
			<< "Power : " << vehicles[i]->findForce() << std::endl;
	}
}

void VehicleStore::print() const {
	for (int i = 0; i < curr; i++) {
		vehicles[i]->print();
		std::cout << std::endl;
	}
}
