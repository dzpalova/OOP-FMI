#include <iostream>

const int MAX_FACULTY = 3;

class Budget {
	double facultyBudget;
	static double universityBudget;
public:
	Budget();
	void addBudget(double);
	static void administrationBudget(double);

	double getFacultyBudget() const;
	double getUniversityBudget() const;
};

double Budget::universityBudget = 0;

Budget::Budget() {
	facultyBudget = 0;
}

void Budget::addBudget(double newBudget) {
	facultyBudget = newBudget;
	universityBudget += newBudget;
}

void Budget::administrationBudget(double newBudget) {
	universityBudget += newBudget;
}

double Budget::getFacultyBudget() const {
	return facultyBudget;
}

double Budget::getUniversityBudget() const {
	return universityBudget;
}

int main()
{

	double budget;
	Budget uni[MAX_FACULTY];
	for (int i = 0; i < MAX_FACULTY; i++) {
		std::cout << " Enter budget of faculty " << i + 1 << " : ";
		std::cin >> budget;
		uni[i].addBudget(budget);
	}

	std::cout << " Enter administration budget : ";
	double admin;
	std::cin >> admin;
	uni->administrationBudget(admin);

	for (int i = 0; i < MAX_FACULTY; i++) {
		std::cout << uni[i].getFacultyBudget() << std::endl;
	}
	std::cout << uni[2].getUniversityBudget() << std::endl;

	while (true) {}
	return 0;
}
