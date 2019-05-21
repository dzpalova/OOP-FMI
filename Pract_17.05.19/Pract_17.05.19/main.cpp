#include<iostream>
#include"Student.h"
#include"Teacher.h"

int main() {
	Student s1;
	s1.read(std::cin);
	std::cout << s1;

	Teacher t1(222,"Stela","OOP");
	t1.saveInFile("test.txt");


	while (true) { }
	return 0;
}