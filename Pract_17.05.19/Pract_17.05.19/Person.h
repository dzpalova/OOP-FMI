#pragma once
#include<iostream>

class Person {
public:
	virtual void read(std::istream&) = 0;
	virtual void print() const = 0;
	virtual void saveInFile(const char*) const = 0;
	//virtual void printGrade() const = 0;
	virtual ~Person() {};
};