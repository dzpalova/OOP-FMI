#include "CourierCompany.h"

void CourierCompany::copyCourierCompany(const CourierCompany &other) {
	countItems = other.countItems;
	currPos = other.currPos;
	items = new Item*[countItems];
	for (int i = 0; i < currPos; i++) {
		items[i] = other.items[i]->clone();
	}
}

void CourierCompany::clean() {
	for (int i = 0; i < countItems; i++) {
		delete items[i];
	}
	delete[] items;
}

bool CourierCompany::resize() {
	Item** tempItems = new Item*[countItems + 2];
	if (tempItems == NULL) {
		return false;
	}
	for (int i = 0; i < currPos; i++) {
		tempItems[i] = items[i];
	}
	clean();
	items = tempItems;
	countItems += 2;
	return true;
}

Furniture * CourierCompany::createFurniture() {
	char addres[20];
	double price;
	int countElements;
	double l, w, h;
	char mark[20];

	cout << "Enter mark : ";
	cin.ignore();
	cin.getline(mark, 20, '\n');

	cout << "Enter length,width and height for box: ";
	cin >> l >> w >> h;
	Box box(l, w, h);

	cout << "Enter the delivery addres:";
	cin.ignore();
	cin.getline(addres, 20, '\n');

	cout << "Enter the price for kilogram for transport: ";
	cin >> price;

	cout << "Enter the number of the elements: ";
	cin >> countElements;

	Furniture* furniture = new Furniture(box, addres, price, countElements, mark);
	cout << endl;

	return furniture;
}

Shoes * CourierCompany::createShoes() {
	char answer;
	char addres[20];
	double price;
	int countElements;
	double l, w, h;

	cout << "Can shoes be tried out immediately after shipment? (y/n) :";
	cin >> answer;
	bool ans;
	if (answer == 'y') {
		ans = 1;
	}
	else {
		ans = 0;
	}

	cout << "Enter length,width and height for box: ";
	cin >> l >> w >> h;
	Box box(l, w, h);

	cout << "Enter the delivery addres:";
	cin.ignore();
	cin.getline(addres, 20, '\n');

	cout << "Enter the price for kilogram for transport: ";
	cin >> price;

	cout << "Enter the number of the elements: ";
	cin >> countElements;

	Shoes* shoes = new Shoes(box, addres, price, countElements, ans);
	cout << endl;

	return shoes;
}

CourierCompany::CourierCompany(int countItems) {
	this->countItems = countItems;
	items = new Item*[countItems];
	currPos = 0;
}

CourierCompany::CourierCompany(const CourierCompany & other) {
	copyCourierCompany(other);
}

CourierCompany& CourierCompany::operator=(const CourierCompany& other) {
	if (this != &other) {
		clean();
		copyCourierCompany(other);
	}
	return *this;
}

CourierCompany::~CourierCompany() {
	clean();
}

bool CourierCompany::addItem() {
	char answer[20];
	do {
		cout << "Choose between shoes or furniture? : " << endl;
		cin >> answer;
	} while (strcmp(answer, "shoes") != 0 && strcmp(answer, "furniture") != 0);

	if (currPos >= countItems && !resize()) {
		return false;
	}
	if (strcmp(answer, "shoes") == 0) {
		items[currPos++] = createShoes();
	}
	else {
		items[currPos++] = createFurniture();
	}
	return true;
}

double CourierCompany::income() const {
	double temp = 0.0;
	for (int i = 0; i < currPos; i++) {
		temp += items[i]->transportPrice();
	}
	return temp;
}

double CourierCompany::volumeOfAll() const {
	double temp = 0.0;
	for (int i = 0; i < currPos; i++) {
		temp += items[i]->getBox().volume();
	}
	return temp;
}

void CourierCompany::showDataOfCourierCompany() const {
	cout << "The Courier Company have " << currPos << " items: ";
	for (int i = 0; i < currPos; i++) {
		items[i]->showDataForItem();
	}
}

