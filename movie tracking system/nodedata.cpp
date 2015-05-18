//////////////////////////////  nodedata.cpp  ////////////////////////////////

#include "nodedata.h"

//--------------------------  constructor  -----------------------------------
NodeData::NodeData()  {}

NodeData::~NodeData() {}

ostream& operator<<(ostream & output, const NodeData & rhs){
	return rhs.print(output);
}