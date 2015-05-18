#ifndef COLLECTION_H
#define COLLECTION_H

//#include "bintree.h"
#include "factory.h"
class BinTree;

const int ARRAY_SIZE = 128;

class Collection {
	friend ostream& operator<<(ostream &, const Collection &);

public:
	Collection();	//default constructor
	~Collection();  //destructor

	bool addMovie(NodeData*, char); //add movie to binTree

	bool retriveMovie(const NodeData &, NodeData*&, char) const;

private:
	BinTree* movieCollection[ARRAY_SIZE];  // array of pointers to movie trees
	int numberOfTrees;		// number of movie trees
};

#endif
