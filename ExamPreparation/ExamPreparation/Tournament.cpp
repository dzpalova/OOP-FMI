#include "Tournament.h"

bool Tournament::resize() {
	Player** temp = new Player*[capacity * 2];
	if (temp == NULL) { return false; }

	for (int i = 0; i < curr; i++) {
		temp[i] = players[i];
	}
	delete[] players;
	players = temp;
	capacity *= 2;
	return true;

}

void Tournament::copy(const Tournament & other) {
	players = new Player*[other.capacity];
	for (int i = 0; i < curr; i++) {
		players[i] = other.players[i]->clone();
	}
	capacity = other.capacity;
	curr = other.curr;
}

void Tournament::clean() {
	for (int i = 0; i < curr; i++) {
		delete players[i];
	}
	delete[] players;
}

Player * Tournament::createPlayer() {
	char answer[20];
	std::cout << "What player you want to add ? (amateur, semiProfessional, professional) : " << std::endl;
	std::cin >> answer;

	char name[20];
	std::cout << "Enter name for the new player : " << std::endl;
	std::cin >> name;

	int skill;
	std::cout << "Enter skill for the new player : " << std::endl;
	std::cin >> skill;
	if (strcmp(answer, "amateur") == 0) {
		Player* temp = new Amateur(name, skill);
		return temp;
	}
	else if (strcmp(answer, "semiProfessional") == 0) {
		Player* temp = new SemiProfessional(name, skill);
		return temp;
	}
	else if (strcmp(answer, "professional") == 0) {
		Player* temp = new Professional(name, skill);
		return temp;
	}
	else {
		std::cout << "Wrong answer! :(" << std::endl;
		return nullptr;
	}
}

Tournament::Tournament(int capacity) {
	this->capacity = capacity;
	players = new Player*[capacity];
	curr = 0;
}

Tournament::Tournament(const Tournament & other) {
	copy(other);
}
Tournament& Tournament::operator=(const Tournament& other) {
	if (this != &other) {
		clean();
		copy(other);
	}
	return *this;
}

Tournament::~Tournament() {
	clean();
}

void Tournament::addPlayer() {
	if (curr >= capacity && !resize()) {
		std::cout << "Error!" << std::endl;
	}
	players[curr++] = createPlayer();
}

Player& Tournament::winner() const {
	double max = 0;
	int index = -1;
	for (int i = 0; i < curr; i++) {
		if (players[i]->getPoints() > max) {
			max = players[i]->getPoints();
			index = i;
		}
	}
	return *players[index];
}
