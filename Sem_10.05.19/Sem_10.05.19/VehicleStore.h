#pragma once

#include "WaterVehicle.h"
#include "RoadVehicle.h"

class VehicleStore {
	Vehicle** vehicles;
	int curr;
	int count;


	void copy(const VehicleStore&);
	void clean();
	bool resize();
	bool insert(Vehicle* veh);
	WaterVehicle* createWaterVehicle(const char*);
	RoadVehicle* createRoadVehicle(const char* nameMotor);
public:
	VehicleStore(int = 0);
	VehicleStore(const VehicleStore&);
	VehicleStore& operator=(const VehicleStore&);
	~VehicleStore();

	void addVehicle();
	const char* getNameOfTheMostPowerfullMotor() const;
	void printNameAndForce() const;

	void print() const;
};
