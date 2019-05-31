#include "PokerPlayer.h"

class Tournament {
	Player** players;
	int capacity;
	int curr;

	bool resize();
	void copy(const Tournament&);
	void clean();
	Player* createPlayer();
public:
	Tournament(int = 0);
	Tournament(const Tournament&);
	Tournament& operator=(const Tournament&);
	~Tournament();

	void addPlayer();

	Player& winner() const;
};