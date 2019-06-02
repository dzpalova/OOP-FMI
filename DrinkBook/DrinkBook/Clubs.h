#include "Club.h"
#include "FolkClub.h"
#include "Rock.h"
#include "Haus.h"

class Clubs {
	Club** clubs;
	int capacity;
	int currPos;


	bool resize();
	void copy(const Clubs&);
	void clean();

public:
	Clubs(int = 0);
	Clubs(const Clubs&);
	Clubs& operator=(const Clubs&);
	~Clubs();

	bool addFolkClub(const char*, double, double, const char*);
	bool addRockClub(const char*, double, double);
	bool addHouseClub(const char*, double, double, int);
};