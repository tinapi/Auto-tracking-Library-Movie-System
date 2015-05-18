#include "transaction.h"

Transaction::Transaction() {
	transType = '\0';
	user = NULL;
	movie = NULL;
	movieCollection = NULL;
}

Transaction::~Transaction() {};

char Transaction::getTransType() const{
	return transType;
}

void Transaction::setTransType(char type) {
	transType = type;
}

NodeData& Transaction::getMovie() const {
	return *movie;
}
User& Transaction::getUser() const {
	return *user;
}

void Transaction::setCollection(Collection* movies) {
	movieCollection = movies;
}
/**
bool Transaction::process(User* aUser, NodeData* aMovie, Collection* movies) {
	user = aUser;
	movie = aMovie;
	movieCollection = movies;
}
*/

/*ostream& operator<<(ostream & output, const Transaction & rhs){
	return rhs.print(output);
}*/