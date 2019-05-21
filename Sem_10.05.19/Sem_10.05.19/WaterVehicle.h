#pragma once
#include "Vehicle.h"

class WaterVehicle :public Vehicle {
	int* turbines;
	int curr;
	int count;
	void copyTurbines(const WaterVehicle&);

	bool resize();
public:
	WaterVehicle(const char* = "", int = 0);
	WaterVehicle(const WaterVehicle&);
	WaterVehicle& operator=(const WaterVehicle&);
	~WaterVehicle();

	bool addTurbine(int);
	double findForce() const;
	virtual void print() const;
};

