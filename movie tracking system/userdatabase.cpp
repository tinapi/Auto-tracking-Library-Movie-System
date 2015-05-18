#include "userdatabase.h"

UserDatabase::UserDatabase() {
	for (int i = 0; i < USER_SIZE; i++) {
		userArray[i] = NULL;
	}
	userCount = 0;
}

UserDatabase::~UserDatabase() {
	for (int i = 0; i < USER_SIZE; i++) {
		if (userArray[i] != NULL) {
			delete userArray[i];
			userArray[i] = NULL;
		}
	}
	userCount = 0;
}

bool UserDatabase::findUser(int ID) const {
	return userArray[ID] != NULL;
}

bool UserDatabase::addUser(User* oneUser) {
	int index = oneUser->getID();
	if (!findUser(index)) {	//if no dupilicate
		userArray[index] = oneUser;
	}
	return false;
}

bool UserDatabase::retrieveUser(int id, User*& oneUser) const {
	if (!findUser(id)) return false;

	oneUser = userArray[id];
	return true;
}

ostream& operator<< (ostream& output, const UserDatabase& users) {
	for (int i = 0; i < USER_SIZE; i++) {
		if (users.userArray[i] != NULL) {
			output << *users.userArray[i] << endl;
		}
	}

	return output;
}
