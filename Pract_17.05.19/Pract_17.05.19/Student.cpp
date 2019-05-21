#include "Student.h"

void Student::copy(int FN, const char* name, const char* speciality, int course) {
	this->FN = FN;

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->speciality = new char[strlen(speciality) + 1];
	strcpy_s(this->speciality, strlen(speciality) + 1, speciality);

	this->course = course;
}

void Student::clean() {
	delete[] name;
	delete[] speciality;
}

Student::Student(int FN, const char* name, const char* speciality, int course) {
	copy(FN, name, speciality, course);
}

Student::Student(const Student& st) {
	copy(st.FN, st.name, st.speciality, st.course);
}

Student& Student::operator=(const Student& st) {
	if (this != &st) {
		clean();
		copy(st.FN, st.name, st.speciality, st.course);
	}
	return *this;
}

Student::~Student() {
	clean();
}

std::ostream& operator<<(std::ostream& os, const Student& st) {
	os << st.FN << " " << st.name << " " << st.speciality << " " << st.course << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Student& st) {
	int FN,course;
	char name[32], speciality[32];
	is >> FN >> name >> speciality >> course;
	st = Student(FN, name, speciality, course);
	return is;
}