#include<iostream>
class Feeling {
	char name[11];
	char emoji[4];
	double rate;
public:
	Feeling(const char* namee, const char* emojii) {
		strcpy_s(name, strlen(namee) + 1, namee);
		strcpy_s(emoji, strlen(emojii) + 1, emojii);
		rate = 0;
	}

	void print()const {
		std::cout << name << " " << emoji << " rate:" << rate << std::endl;
	}
};

class Happiness : public Feeling {
public:
	Happiness() : Feeling("happiness", ":)") {}
};

class Sadness : public Feeling {
public:
	Sadness() : Feeling("sadness", ":(") {}
};

class Love : public Feeling {
public:
	Love() : Feeling("Love", "<3") {}
};