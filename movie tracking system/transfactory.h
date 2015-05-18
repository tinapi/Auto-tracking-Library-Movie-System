#ifndef TRANSFACTORY_H
#define TRANSFACTORY_H

#include "factory.h"
#include "borrow.h"
#include "return.h"
#include "displayhistory.h"
#include "displayinventory.h"

class TransFactory : public Factory{
public:
	TransFactory();
	~TransFactory();

	Transaction* createIt(char ch) const;

private:
	Transaction* transObjFactory[SIZE];
};

#endif