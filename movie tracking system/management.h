#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "movie.h"
#include "bintree.h"
#include "moviefactory.h"
#include "collection.h"
#include "userdatabase.h"

#include "transaction.h"
#include "transfactory.h"

using namespace std;

class Management {
public:
	Management();	// constructor
	~Management();	// destructor

	// readin movie data file and build collection
	void buildCollection(ifstream & );

	// display movie collection
	void displayCollection() const;

	void buildUserDatabase(ifstream &);

	void displayUser() const;

	void runCommand(ifstream &) const;

private:
	MovieFactory movieFactory; // create movie object
	TransFactory transacFactory; // create a  transaction object
	Collection movieCollection;	// insert movie object through collection
	UserDatabase users;
}

#endif
