#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <fstream>
#include "transaction.h"

using namespace std;

class NodeData;

class User {
	friend ostream& operator<<(ostream &, const User &);

public:
	User();		// default constructor
	~User();	//destructor

	bool setdata(ifstream&);	// read in user data file

	int getID() const;
	void displayHistory() const;
	bool isBorrowed(const NodeData&) const;

	bool addHistory(Transaction*); // add to user's history

private:
	struct Node{
		Transaction* trans;
		Node* next;
	};

	string UserFirst;
	string UserLast;
	int ID;
	Node* userHistory;

};

#endif