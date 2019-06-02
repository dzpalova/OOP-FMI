#include <iostream>

enum Music {
	POP_FOLK = 1,
	HOUSE,
	ROCK,
	I_LISTEN_EVERYTHING
};

class User {
	char* name;
	unsigned years;
	double budget;
	unsigned numVodka;
	unsigned numWhiskey;
	Music music;

	bool copy(const User&);

public:
	User(const char* = "", unsigned = 0, double = 0.0, unsigned = 0, unsigned = 0, Music = I_LISTEN_EVERYTHING);
	User(const User&);
	User& operator=(const User&);
	~User();
};