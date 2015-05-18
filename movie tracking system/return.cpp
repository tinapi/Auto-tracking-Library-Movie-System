#include "return.h"
//#include "nodedata.h"
#include "user.h"

Return::Return() {
	transType = 'R';
	movie = NULL;
}

Transaction* Return::create() const{
	return new Return();
}

bool Return::process(User* tUser, NodeData* tMovie) {
	if (checkBorrow(*tUser, *tMovie)) {
		// link to user
		user = tUser;
		// link to movie
		movie = tMovie;
		return true;
	}
	else { // invalid return, display error message
		cout << "Invalid Return Command" << endl;
		return false;
	}
}

void Return::process() const {}

bool Return::checkBorrow(User& tUser, NodeData& tMovie) const {
	return tUser.isBorrowed(tMovie);
}
