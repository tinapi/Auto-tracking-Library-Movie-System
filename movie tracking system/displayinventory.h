#ifndef DISPLAYINVENTORY_H
#define DISPLAYINVENTORY_H

#include "transaction.h"

using namespace std;

class DisplayInventory : public Transaction{
public:
	DisplayInventory();
	
	virtual Transaction* create() const;
	virtual bool process(User*, NodeData*);
	virtual void process() const;

};

#endif