#include "furniture.h"
#include "shoes.h"
#include "CourierCompany.h"
#include<cstring>
int main() {

	////       Making Item

	//cout << "Now we will make Item :)" << endl;
	//char addres[20];
	//double price;
	//int countElements;
	//double l, w, h;
	//cout << "Enter length,width and height for box: ";
	//cin >> l >> w >> h;
	//Box box1(l, w, h);
	//cout << "The volume of your box is " << box1.volume() << "." << endl;
	//cout << "Enter the delivery addres:";
	//cin.ignore();
	//cin.getline(addres, 20, '\n');
	//cout << "Enter the price for kilogram for transport: ";
	//cin >> price;
	//cout << "Enter the number of the elements: ";
	//cin >> countElements;
	//Item item1(box1, addres, price, countElements);
	//cout << "Do you want to add element? (y/n) :";
	//char answer;
	//cin >> answer;
	//while (answer == 'y') {

	//	char materialName[20];
	//	bool isFrangible;
	//	cout << "Enter name for material: ";
	//	cin.ignore();
	//	cin.getline(materialName, 20, '\n');
	//	cout << "Enter 1 if the material is frangible of enter 0 if it's not: ";
	//	cin >> isFrangible;
	//	Material mat1(materialName, isFrangible);
	//	//mat1.print();

	//	double kg;
	//	cout << "KG for element: ";
	//	cin >> kg;
	//	Element el1(mat1, kg);
	//	item1.addElement(el1);

	//	el1.print();
	//	cout << "Do you want to add element? (y/n) :";
	//	cin >> answer;
	//}

	//cout << "Do you want to see the weight of the item ? (y/n) :";
	//cin >> answer;
	//if (answer == 'y') {
	//	cout << item1.weightItem() << endl;
	//}

	//cout << "Do you want to see the price of the item ? (y/n) :";
	//cin >> answer;
	//if (answer == 'y') {
	//	cout << item1.transportPrice() << endl;
	//}

	//cout << "Do you want to see the elements of the item ? (y/n) :";
	//cin >> answer;
	//if (answer == 'y') {
	//	item1.showElements();
	//	cout << endl;
	//}

	//cout << "Do you want to see the data of the item ? (y/n) :";
	//cin >> answer;
	//if (answer == 'y') {
	//	item1.showData();
	//	cout << endl;
	//}

	//cout << "Do you want to add the item to file ? (y/n) :";
	//cin >> answer;
	//if (answer == 'y') {
	//	item1.saveInFile("items.txt");
	//	cout << "The items are saved! " << endl;
	//}

	////          Making Furniture

	//cout << "Now we will make furniture so add name for mark : ";
	//char mark[20];
	//cin.ignore();
	//cin.getline(mark, 20, '\n');
	//cout << "Enter length,width and height for box: ";
	//cin >> l >> w >> h;
	//Box box2(l, w, h);
	//cout << "The volume of your box is " << box2.volume() << "." << endl;
	//cout << "Enter the delivery addres:";
	//cin.ignore();
	//cin.getline(addres, 20, '\n');
	//cout << "Enter the price for kilogram for transport: ";
	//cin >> price;
	//cout << "Enter the number of the elements: ";
	//cin >> countElements;
	//Furniture furniture(box2, addres, price, countElements, mark);
	//Item item2(box2, addres, price, countElements);
	//cout << "Do you want to add element? (y/n) :";
	//cin >> answer;
	//while (answer == 'y') {

	//	char materialName[20];
	//	bool isFrangible;
	//	cout << "Enter name for material: ";
	//	cin.ignore();
	//	cin.getline(materialName, 20, '\n');
	//	cout << "Enter 1 if the material is frangible of enter 0 if it's not: ";
	//	cin >> isFrangible;
	//	Material mat2(materialName, isFrangible);
	//	//mat2.print();

	//	double kg;
	//	cout << "KG for element: ";
	//	cin >> kg;
	//	Element el2(mat2, kg);
	//	furniture.addElement(el2);
	//	item2.addElement(el2);
	//	//el2.print();
	//	cout << "Do you want to add element? (y/n) :";
	//	cin >> answer;
	//}

	//cout << "Do you want to see the weight of the furniture ? (y/n) :";
	//cin >> answer;
	//if (answer == 'y') {
	//	cout << furniture.weightItem() << endl;
	//}

	//cout << "Do you want to know if the furniture is frangible ? (y/n) :";
	//cin >> answer;
	//if (answer == 'y') {
	//	if (furniture.isFrangible()) {
	//		cout << "The furniture is frangible." << endl;
	//	}
	//	else {
	//		cout << "The furniture is not frangible." << endl;
	//	}
	//}

	//cout << "Do you want to see the price for transport of the furniture ? (y/n) :";
	//cin >> answer;
	//if (answer == 'y') {
	//	cout << furniture.transportPrice() << endl;
	//}


	////            Making Shoes

	//cout << endl << "Now we will make shoes so tell if they can be tried or not (y/n) :";
	//cin >> answer;
	//bool ans;
	//if (answer == 'y') {
	//	ans = 1;
	//}
	//else {
	//	ans = 0;
	//}
	//cout << "Enter length,width and height for box: ";
	//cin >> l >> w >> h;
	//Box box3(l, w, h);
	//cout << "The volume of your box is " << box3.volume() << "." << endl;
	//cout << "Enter the delivery addres:";
	//cin.ignore();
	//cin.getline(addres, 20, '\n');
	//cout << "Enter the price for kilogram for transport: ";
	//cin >> price;
	//cout << "Enter the number of the elements: ";
	//cin >> countElements;
	//Shoes shoes(box3, addres, price, countElements, ans);
	//Item item3(box3, addres, price, countElements);
	//cout << "Do you want to add element? (y/n) :";
	//cin >> answer;
	//while (answer == 'y') {

	//	char materialName[20];
	//	bool isFrangible;
	//	cout << "Enter name for material: ";
	//	cin.ignore();
	//	cin.getline(materialName, 20, '\n');
	//	cout << "Enter 1 if the material is frangible of enter 0 if it's not: ";
	//	cin >> isFrangible;
	//	Material mat3(materialName, isFrangible);

	//	double kg;
	//	cout << "KG for element: ";
	//	cin >> kg;
	//	Element el3(mat3, kg);
	//	shoes.addElement(el3);
	//	item3.addElement(el3);
	//	cout << "Do you want to add element? (y/n) :";
	//	cin >> answer;
	//}

	//cout << endl;

	//cout << "Do you want to see the price for transport ? (y/n) :";
	//cin >> answer;
	//if (answer == 'y') {
	//	cout << shoes.transportPrice() << endl;
	//}

	//cout << "Do you want to see the data of the shoes ? (y/n) :";
	//cin >> answer;
	//if (answer == 'y') {
	//	shoes.showData();
	//	cout << endl;
	//}


	//                 Courier Company

	int num;
	cout << endl << "Enter how items your company will have: ";
	cin >> num;
	CourierCompany company(num);
	cout << endl << "Now enter " << num << " Items: " << endl;
	for (int i = 0; i < num; i++) {
		company.addItem();
	}
	company.showDataOfCourierCompany();
	cout << endl << "The company income is: " << company.income() << endl;
	cout << "The volume of all items is: " << company.volumeOfAll() << endl;
	company.ranking();
	while (true) {}
	return 0;
}

