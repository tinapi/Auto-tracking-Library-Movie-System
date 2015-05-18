#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"

using namespace std;

class Return : public Transaction {

public:
	Return();

	virtual Transaction* create() const;
	virtual bool process(User*, NodeData*);
	virtual void process() const;
	bool checkBorrow(User&, NodeData&) const;
	//virtual ostream& print(ostream&) const;
};

#endif
