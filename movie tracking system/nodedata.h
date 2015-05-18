//////////////////////////////  nodedata.h  //////////////////////////////////
// Simple object containing one integer and one character

#ifndef NODEDATA_H
#define NODEDATA_H

#include <iostream>
#include <fstream>
using namespace std;

//---------------------------  class NodeData  ------------------------------
class NodeData {                                
	friend ostream& operator<<(ostream &, const NodeData &);

public:
	NodeData();						// default constructor

	virtual ~NodeData();	  // destructor
	virtual bool setData(ifstream &) = 0;		// reads data from file
	virtual bool setSorting(ifstream &) = 0;

	virtual NodeData* create() const = 0;
	virtual ostream& print(ostream &) const = 0;

	virtual bool operator<(const NodeData &) const = 0;
	virtual bool operator>(const NodeData &) const = 0;
	virtual bool operator==(const NodeData &) const = 0;
	virtual bool operator!=(const NodeData &) const = 0;

	// other operators: >=, <= are left to the reader
};

#endif
