#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "factory.h"
#include "classic.h"
#include "drama.h"
#include "comedy.h"

class MovieFactory : public Factory{

public:
	MovieFactory();		// default constructor
	virtual ~MovieFactory();

	NodeData* createIt(char ch) const;

private:
	NodeData* movieObjFactory[SIZE];
};

#endif
