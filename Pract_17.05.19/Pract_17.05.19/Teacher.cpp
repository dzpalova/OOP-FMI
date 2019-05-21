#include "Teacher.h"

void Teacher::copy(int id, const char* name, const char* subject) {
	this->id = id;

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->subject = new char[strlen(subject) + 1];
	strcpy_s(this->subject, strlen(name) + 1, subject);
}

void Teacher::clean() {
	delete[] name;
	delete[] subject;
}

Teacher::Teacher(int id, const char* name, const char* subject) {
	copy(id, name, subject);
}

Teacher::Teacher(const Teacher& t) {
	copy(t.id, t.name, t.subject);
}

Teacher& Teacher::operator=(const Teacher& t) {
	if (this != &t) {
		clean();
		copy(t.id, t.name, t.subject);
	}
	return *this;
}

Teacher::~Teacher() {
	clean();
}

std::ostream& operator<<(std::ostream& os, const Teacher& t) {
	os << t.id << " " << t.name << " " << t.subject << std::endl;
	return os;
}
std::istream& operator>>(std::istream& is, Teacher& t) {
	int id;
	char name[20], subject[20];
	is >> id >> name >> subject;
	t = Teacher(id, name, subject);
	return is;
}

void Teacher::read(std::istream& is) {
	is >> *this;
}

void Teacher::print() const {
	std::cout << *this;
}

void Teacher::saveInFile(const char* fileName) const {
	std::ofstream os(fileName,std::ios::app);
	if (!os) {
		std::cout << "Error while opening the file!" << std::endl;
	}
	os << *this;
}
