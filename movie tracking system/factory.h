#ifndef FACTORY_H
#define FACTORY_H

#include <string>
using namespace std;

const int SIZE = 50;

class Factory {

public:
	Factory();
	virtual ~Factory();
	
protected:
	int hash(char ch) const;
};

#endif
