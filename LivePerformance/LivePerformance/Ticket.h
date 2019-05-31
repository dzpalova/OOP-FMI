#include <iostream>

template <typename T>
class Ticket {
protected:
	char* performance;
	double price;
	T id;

	void copy(const Ticket<T>&);
public:
	Ticket();
	Ticket(const char*, double&, T&);
	Ticket<T>& operator=(const Ticket<T>&);
	Ticket(const Ticket<T>&);
	~Ticket();

	double getPrice() const { return price; }
	virtual int getPlaces() const { return 1; }
};



template <typename T>
class GroupTicket : public Ticket<T> {
private:
	int places;
public:
	GroupTicket();
	GroupTicket(const char*, double&, T&, int&);
	~GroupTicket() { }

	virtual int getPlaces() const { return places; }
};
