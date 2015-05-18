/////////////////////////////////  drama.cpp  ////////////////////////////////
#include "drama.h"

//--------------------------  constructor  -----------------------------------
Drama::Drama() : Movie() {};

//------------------------  copy constructor  --------------------------------
Drama::Drama(const Drama& rhs) : Movie(rhs) {};

//-----------------------------  create()  -----------------------------------
NodeData* Drama::create() const {
	return new Drama();
}

//----------------------------  setSorting  ----------------------------------
bool Drama::setSorting(ifstream & infile) {
	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');

	return true;
}

// override operator ==
bool Drama::operator== (const NodeData& rhs) const {
	// casting a nodedata renference to a drama reference
	const Drama& dMovie = static_cast<const Drama&>(rhs);

	return (director == dMovie.director && title == dMovie.title);
}

// override opeartor !=
bool Drama::operator!= (const NodeData& rhs) const {
	return !(*this == rhs);
}

//override operator >
// sort drama by director, then title
bool Drama::operator> (const NodeData& rhs) const{
	// casting a nodedata renference to a drama reference
	const Drama& dMovie = static_cast<const Drama&>(rhs);

	if (director != dMovie.director){
		return director > dMovie.director;
	} 
	else if (title != dMovie.title) {
		return title > dMovie.title;
	}

	return false;
}

// override operator <
// sort drama by director, then title
bool Drama::operator< (const NodeData& rhs) const{
	// casting a nodedata renference to a drama reference
	const Drama& dMovie = static_cast<const Drama&>(rhs);

	if (director != dMovie.director){
		return director < dMovie.director;
	}
	else if (title != dMovie.title) {
		return title < dMovie.title;
	}

	return false;
}