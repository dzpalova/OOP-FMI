#include "Ticket.h"

// Ticket

template <typename T>
Ticket<T>::Ticket() {
	price = 0;
	performance = "";
}

template <typename T>
Ticket<T>::Ticket(const char* per, double& pr, T& idd) {
	performance = new char[strlen(per) + 1];
	strcpy_s(performance, strlen(per) + 1, per);
	price = pr;
	id = idd;
}

template <typename T>
void Ticket<T>::copy(const Ticket<T>& other) {
	performance = new char[strlen(other.performance) + 1];
	strcpy_s(performance, strlen(other.performance) + 1, other.performance);
	id = other.id;
	price = other.price;
}

template <typename T>
Ticket<T>::Ticket(const Ticket<T>& other) {
	copy(other);
}

template <typename T>
Ticket<T>& Ticket<T>::operator=(const Ticket<T>& other) {
	if (this != &other) {
		delete[] performance;
		copy(other);
	}
	return *this;
}

template <typename T>
Ticket<T>::~Ticket() {
	delete[] performance;
}


//GroupTicket

template <typename T>
GroupTicket<T>::GroupTicket() : Ticket<T>() {
	places = 0;
}

template <typename T>
GroupTicket<T>::GroupTicket(const char* per, double& pr, T& idd, int& placess)
	: Ticket<T>(per, pr - placess > 0 ? pr - placess : 1, idd) {
	places = placess;
}

template <typename T>
double sumPrices(Ticket<T>** tickets, int num) {
	double sum;
	for (int i = 0; i < num; i++) {
		sum += (tickets->getPlace()*tickets->getPrice());
	}
	return sum;
}