#include "Spectator.h"

template <typename T>
class LivePerformance {
	char name[101];
	Happiness happiness;
	Sadness sadness;
	Love love;
	Spectator<T>* spectator;
	int numSpectators;

	void copy(const LivePerformance<T>&);
public:
	LivePerformance(const char*);
	LivePerformance(const LivePerformance<T>&);
	LivePerformance<T>& operator=(const LivePerformance<T>&);
	~LivePerformance();

	void makePoll() const;
};
