#pragma once
#include "Vehicle.h"

class RoadVehicle : public Vehicle {
	char* name;
	int age;
public:
	RoadVehicle(const char* = "", const char* = "", int = 0);
	RoadVehicle(const RoadVehicle&);
	RoadVehicle& operator=(const RoadVehicle&);
	~RoadVehicle();

	virtual double findForce() const;
	virtual Vehicle* clone();
	void setName(const char*);
	void setAge(int);
	virtual void print() const;
};
