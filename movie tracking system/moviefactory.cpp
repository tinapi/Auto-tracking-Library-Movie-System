/////////////////////////////  MovieFactory.cpp  /////////////////////////////
#include "moviefactory.h"

MovieFactory::MovieFactory() {
	for (int i = 0; i < SIZE; i++) {
		movieObjFactory[i] = NULL;
	}

	movieObjFactory[2] = new Classic();
	movieObjFactory[3] = new Drama();
	movieObjFactory[5] = new Comedy();
}

MovieFactory::~MovieFactory() {
	for (int i = 0; i < SIZE; i++) {
		if (movieObjFactory[i] != NULL) {
			delete movieObjFactory[i];
			movieObjFactory[i] = NULL;
		}
	}
}

NodeData* MovieFactory::createIt(char type) const{
	int subscrupit = hash(type);
	return movieObjFactory[subscrupit]->create();
}
