#ifndef USERDATABASE_H
#define USERDATABASE_H

#include "user.h"

using namespace std;

const int USER_SIZE = 10000;

class UserDatabase {
	friend ostream& operator<<(ostream &, const UserDatabase &);

public:
	UserDatabase();		// default constuctor
	~UserDatabase();	// destructor

	bool findUser(int) const;	// search user by id
	bool addUser(User*);	// add user into array
	bool retrieveUser(int, User*&) const;

private:
	User* userArray[USER_SIZE];
	int userCount;	// number of users
};

#endif
