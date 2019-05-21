#pragma once
#include <iostream>
#include <cstring>

class Vehicle {
protected:
	char* motor;

	void copy(const char*);
public:
	Vehicle(const char* = "");
	Vehicle(const Vehicle&);
	Vehicle& operator=(const Vehicle&);
	virtual ~Vehicle();

	virtual double findForce() const = 0;
	virtual Vehicle* clone() = 0;
	virtual void print() const = 0;
	const char* getMotor()const;
};
