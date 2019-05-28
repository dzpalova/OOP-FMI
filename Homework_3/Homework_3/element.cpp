#include"element.h"

Element::Element(Material material, double kilogram) {
	this->material = material;
	this->kilogram = kilogram;
}

bool Element::isFrangible() const {
	if (material.getIsFrangible()) {
		return true;
	}
	return false;
}

void Element::print() const {
	cout << "The element is made of: " << kilogram << "kg ";
	material.print();
}

double Element::getKilogram() const {
	return kilogram;
}

ostream & operator<<(ostream & os, Element & el) {
	os << el.material << " " << el.kilogram << "kg. ";
	return os;
}

