#include "displayinventory.h"

DisplayInventory::DisplayInventory() : Transaction(){
	transType = 'S';
}

Transaction* DisplayInventory::create() const{
	return new DisplayInventory();
}

void DisplayInventory::process() const{
	cout << movieCollection;
}

bool DisplayInventory::process(User*, NodeData*) {};