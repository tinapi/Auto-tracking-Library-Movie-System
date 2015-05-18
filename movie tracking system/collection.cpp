//////////////////////////////  collection.cpp  /////////////////////////////
#include "collection.h"

//--------------------------  constructor  -----------------------------------
Collection::Collection() {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		movieCollection[i] = NULL;
	}
}

//--------------------------  destructor  ------------------------------------
Collection::~Collection() {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (movieCollection[i] != NULL) {
			delete movieCollection[i];
			movieCollection[i] = NULL;
		}
	}
}

//---------------------------  addMovie  -------------------------------------
bool Collection::addMovie(NodeData* movieObj, char movieType){
	int index = (int)movieType;
	if (movieCollection[index] == NULL) {
		movieCollection[index] = new BinTree();
	}
	return movieCollection[index]->insert(movieObj);
}

//-------------------------  retriveMovie  -----------------------------------
bool Collection::retriveMovie(const NodeData& target, NodeData*& targetPtr,
		char movieCode) const {
	return movieCollection[movieCode]->retrieve(target, targetPtr);
}

//--------------------------  operator <<  ------------------------------------
ostream& operator<<(ostream & output, const Collection & other) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (other.movieCollection[i] != NULL) {
			output << *other.movieCollection[i] << endl;
		}
	}
	return output;
}

