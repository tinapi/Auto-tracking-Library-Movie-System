#include "transfactory.h"

TransFactory::TransFactory() : Factory() {
	for (int i = 0; i < SIZE; i++) {
		transObjFactory[i] = NULL;
	}

	transObjFactory[1] = new Borrow(); // 'B'-'A' = 1
	transObjFactory[17] = new Return(); // 'R'-'A' = 17
	transObjFactory[7] = new DisplayHistory(); // 'H' - 'A' = 7
	transObjFactory[18] = new DisplayInventory(); // 'S'-'A' = 18
}

TransFactory::~TransFactory() {
	for (int i = 0; i < SIZE; i++){
		if (transObjFactory[i] != NULL) {
			delete transObjFactory[i];
			transObjFactory[i] = NULL;			
		}
	}
}

Transaction* TransFactory::createIt(char commandType) const{
	int subscrupit = hash(commandType);
	return transObjFactory[subscrupit]->create();
}