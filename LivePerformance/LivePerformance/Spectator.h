#include "Ticket.h"
#include "Feelings.h"

template <typename T>
class Spectator {
	Ticket<T>* ticket;
	Feeling feeling;

	void setTicket(const Ticket<T>*);
	void clean();
public:
	Spectator(const Ticket<T>*);
	Spectator(const Spectator<T>&);
	Spectator<T>& operator=(const Spectator<T>&);
	~Spectator();

	bool hasTicket()const;
	double rateFeeling()const;

};