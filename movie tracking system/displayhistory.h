#ifndef DISPLAYHISTORY_H
#define DISPLAYHISTORY_H

#include "transaction.h"

using namespace std;

class DisplayHistory : public Transaction{

public:
	DisplayHistory();

	virtual Transaction* create() const;
	// link to user obj
	virtual bool process(User*, NodeData*);
	//print out user's history
	virtual void process () const;

	int getID() const;
	void setID(int);

private:
	int userID;
};

#endif
