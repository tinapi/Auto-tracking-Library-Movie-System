#include "user.h"
#include "nodedata.h"

User::User() {
	UserFirst = "";
	UserLast = "";
	ID = -1;
	userHistory = NULL;
}

User::~User() {};

bool User::setdata(ifstream& infile) {
	infile >> ID >> UserFirst >> UserLast;
	return true;
}

int User::getID() const {
	return ID;
}

bool User::addHistory(Transaction* history) {
	Node* temp = new Node();
	temp->trans = history;
	temp->next = NULL;

	// if user history is empty
	if (userHistory == NULL){
		userHistory = temp;
		return true;
	}

	// else iterate over user history list 
	Node* current = userHistory;	
	while (current->next != NULL) {
		current = current->next;
	}

	// add a node at the end of the list
	current->next = temp;

	return true;
}

// display user's history
// print out the transaction linked list
void User::displayHistory() const {
	cout<< "  *** Customer ID = " << ID << "  " <<
		UserFirst << " " << UserLast << endl;

	Node* current = userHistory;
	while (current!=NULL){
		cout << *current->trans << endl;
		current = current->next;
	}
}

bool User::isBorrowed(const NodeData& target) const {
	Node* current = userHistory;
	while (current != NULL) {
		Transaction* curTrans = current->trans;
		if (curTrans->getTransType() == 'B' && curTrans->getMovie() == target) {
			return true;
		}
		current = current->next;
	}
	return false;
}

ostream& operator<< (ostream& output, const User& rhs) {
	output << rhs.ID << " " << rhs.UserFirst << " ";
	output << rhs.UserLast;

	return output;
}