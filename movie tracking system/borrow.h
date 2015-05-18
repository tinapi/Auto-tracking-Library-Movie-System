#ifndef BORROW_H
#define BORROW_H

#include "transaction.h"

using namespace std;

class Borrow : public Transaction{

public:
	Borrow();

	virtual Transaction* create() const;
	virtual bool process(User*, NodeData*);
	virtual void process() const;
	//virtual ostream& print(ostream&) const;

};

#endif
