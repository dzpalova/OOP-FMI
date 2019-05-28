#pragma warning(disable:4996)
#include<iostream>
#include<cstring>
using namespace std;

class Material {
	char* name;
	bool isFrangible;
	void copyMaterial(const Material&);
public:
	Material(const char* = "", bool = false);
	Material(const Material&);
	Material& operator=(const Material&);
	~Material();
	friend ostream& operator<<(ostream&, Material&);
	bool getIsFrangible()const;
	void print() const;
};


