#include"material.h"

void Material::copyMaterial(const Material& other) {
    name=new char[strlen(other.name)+1];
    //check
    strcpy(name,other.name);
    isFrangible=other.isFrangible;
}


Material::Material(const char* name, bool isFrangible) {
    this->name=new char[strlen(name)+1];
    //check
    strcpy(this->name,name);
    this->isFrangible=isFrangible;
}

Material::Material(const Material& other) {
    copyMaterial(other);
}

Material& Material::operator=(const Material& other){
    if(this!=&other){
        delete[] name;
        copyMaterial(other);
    }
    return *this;
}

Material::~Material() {
    delete[] name;
}

bool Material::getIsFrangible() const {
    return isFrangible;
}

void Material::print() const {
    cout << "Name of material: " << name << " Frangible: ";
    if (isFrangible) { cout << "yes" << endl; }
    else { cout << "no" << endl; }
}

ostream & operator<<(ostream & os, Material & mat) {
	os << mat.name << " - ";
	if (mat.isFrangible) {
		os << "Is frangible ";
	}
	else {
		os << "Is not frangible ";
	}
	return os;
}