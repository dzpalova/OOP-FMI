#include "LivePerformance.h"


template <typename T>
void LivePerformance<T>::copy(const LivePerformance<T>& other) {
	strcpy_s(name, strlen(other.name) + 1, other.name);

	numSpectators = other.numSpectators;
	spectators = new Spectator<T>[numSpectators];
	for (int i = 0; i < numSpectators; i++) {
		spectators[i] = other.spectators[i];
	}

	happiness = other.happiness;
	sadness = other.sadness;
	love = other.love;
}

template <typename T>
LivePerformance<T>::LivePerformance(const char * name) {
	strcpy_s(this->name, strlen(name) + 1, name);
	numSpectators = 0;
	spectators = new Spectator<T>[numSpectators];
}

template <typename T>
LivePerformance<T>::LivePerformance(const LivePerformance<T>& other) {
	copy(other);
}

template <typename T>
LivePerformance<T>& LivePerformance::operator=(const LivePerformance<T>& other) {
	if (this != &other) {
		delete[] spectators;
		copy(other);
	}
	return *this;
}

template <typename T>
LivePerformance<T>::~LivePerformance() {
	delete[] spectators;
}

template <typename T>
void LivePerformance<T>::makePoll() const {
	int happy = 0, love = 0, sad = 0, cnt = 0;
	for (int i = 0; i < numSpectators; i++) {
		if (spectators[i].hasTicket()) {
			happy += spectators[i].rateFeeling();
			love += spectators[i].rateFeeling();
			sad += spectators[i].rateFeeling();
			cnt++;
		}
	}
	happiness.setRate(happy / cnt);
	love.setRate(love / cnt);
	sadness.setRate(sad / cnt);

	happiness.print();
	sadness.print();
	love.print();
}




