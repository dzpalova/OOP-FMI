#include"shoes.h"
#include "furniture.h"

class CourierCompany {
	int countItems;
	int currPos;
	Item** items;

	void copyCourierCompany(const CourierCompany&);
	void clean();
	bool resize();
	Furniture* createFurniture();
	Shoes* createShoes();	
public:
	CourierCompany(int = 0);
	CourierCompany(const CourierCompany&);
	CourierCompany& operator=(const CourierCompany&);
	virtual ~CourierCompany();

	bool addItem();
	double income() const;
	double volumeOfAll() const;
	void showDataOfCourierCompany() const;
	void ranking() const;
};