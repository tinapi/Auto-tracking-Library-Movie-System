#include "displayhistory.h"
#include "user.h"

DisplayHistory::DisplayHistory() : Transaction() {
	transType = 'H';
}

Transaction* DisplayHistory::create() const {
	return new DisplayHistory();
}

void DisplayHistory::process() const{
	user->displayHistory();
}

bool DisplayHistory::process(User* dUser, NodeData* dMovie) {
	user = dUser;
	return true;
}

int DisplayHistory::getID() const {
	return userID;
}

void DisplayHistory::setID(int id) {
	userID = id;
}
