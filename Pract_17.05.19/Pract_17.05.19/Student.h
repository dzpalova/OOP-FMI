#pragma once

#include "Person.h"
#include <fstream>

class Student :public Person {
	int FN;
	char* name;
	char* speciality;
	int course;

	void copy(int, const char*, const char*, int);
	void clean();
public:
	Student(int = 0, const char* = "", const char* = "", int = 0);
	Student(const Student&);
	Student& operator=(const Student&);
	~Student();

	friend std::ostream& operator<<(std::ostream&, const Student&);
	friend std::istream& operator>>(std::istream&, Student&);

	virtual void read(std::istream&);
	virtual void print() const;
	virtual void saveInFile(const char*) const;
	//virtual void printGrade() const;
};