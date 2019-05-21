#pragma once
#include "Person.h"
#include <fstream>

class Teacher :public Person {
	int id;
	char* name;
	char* subject;

	void copy(int, const char*, const char*);
	void clean();
public:
	Teacher(int = 0, const char* = "", const char* = "");
	Teacher(const Teacher&);
	Teacher& operator=(const Teacher&);
	~Teacher();

	friend std::ostream& operator<<(std::ostream&, const Teacher&);
	friend std::istream& operator>>(std::istream&, Teacher&);

	virtual void read(std::istream&);
	virtual void print() const;
	virtual void saveInFile(const char*) const;
	//virtual void printGrade() const;
};