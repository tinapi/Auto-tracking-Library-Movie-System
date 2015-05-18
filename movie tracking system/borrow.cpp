#include "borrow.h"
//#include "nodedata.h"
//#include "user.h"

Borrow::Borrow() : Transaction(){
	transType = 'B';
	movie = NULL;
}

Transaction* Borrow::create() const{
	return new Borrow();
}

bool Borrow::process(User* tUser, NodeData* tMovie) {
	// link to movie
	movie = tMovie;
	// link to user
	user = tUser;
	return true;
}

void Borrow::process() const {}
/*ostream& Borrow::print(ostream& infile) const {
	const Movie& aMovie = static_cast<const Movie&>(*movie);
	infile << aMovie.getMedia() << " Borrow  " << aMovie;
}*/
