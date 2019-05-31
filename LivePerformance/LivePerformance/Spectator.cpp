#include "Spectator.h"


template <typename T>
void Spectator<T>::setTicket(const Ticket<T>* ticket) {
	this->ticket = nullptr;
	if (ticket != nullptr) {
		if (ticket->getPlaces() > 1) {
			this->ticket = new GroupTicket<T>(*ticket);
		}
		else {
			this->ticket = new Ticket<T>(*ticket);
		}
	}
}

template<typename T>
void Spectator<T>::clean() {
	if (ticket) {
		delete ticket;
	}
}

template <typename T>
Spectator<T>::Spectator(const  Ticket<T>* ticket) {
	setTicket(ticket);
}

template <typename T>
Spectator<T>::Spectator(const Spectator<T>& other) {
	setTicket(other.ticket);
}

template <typename T>
Spectator<T>& Spectator<T>::operator=(const Spectator<T>& other) {
	if (this != &other) {
		clean();
		setTicket(other.ticket);
	}
	return *this;
}

template <typename T>
Spectator<T>::~Spectator() {
	clean();
}


template <typename T>
bool Spectator<T>::hasTicket()const {
	return (ticket != nullptr);
}

template <typename T>
double Spectator<T>::rateFeeling()const {
	return (double)(rand() % 100) / 100;
}