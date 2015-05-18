#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class NodeData;
class User;
class Collection;

class Transaction {
	friend ostream& operator<<(ostream&, const Transaction&);

public:
	Transaction();
	virtual ~Transaction();

	virtual Transaction* create() const = 0;
	// initialize data members
	virtual bool process(User*, NodeData*) = 0;
	// process display history and display inventory
	virtual void process() const = 0;
	//virtual ostream& print(ostream&) const = 0;
	void setCollection(Collection*);

	char getTransType() const;
	void setTransType(char);

	virtual NodeData& getMovie() const;
	virtual User& getUser() const;

protected:
	NodeData* movie;
	User* user;
	// display inventory has a link to collection
	Collection* movieCollection;
	char transType;
};

#endif
