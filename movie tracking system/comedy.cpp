////////////////////////////////  comedy.cpp  ////////////////////////////////
#include "comedy.h"

//--------------------------  constructor  -----------------------------------
Comedy::Comedy() : Movie() {};

//------------------------  copy constructor  --------------------------------
Comedy::Comedy(const Comedy& rhs) : Movie(rhs) {};

//------------------------------  create  ------------------------------------
NodeData* Comedy::create() const {
	return new Comedy();
}

//----------------------------  setSorting  ----------------------------------
bool Comedy::setSorting(ifstream & infile) {
	infile.get();
	getline(infile, title, ','); 

	infile.get();
	infile >> year;
	
	return true;
}

// override operator ==
bool Comedy::operator== (const NodeData& rhs) const {
	const Comedy& aComedy = static_cast<const Comedy&>(rhs);
	return title == aComedy.title && year == aComedy.year;
}

// override opeartor !=
bool Comedy::operator!= (const NodeData& rhs) const {
	const Comedy& aComedy = static_cast<const Comedy&>(rhs);
	return !(*this == aComedy);
}

//override operator >
// sort drama by title, then date
bool Comedy::operator> (const NodeData& rhs) const{
	const Comedy& aComedy = static_cast<const Comedy&>(rhs);
	if (title != aComedy.title){
		return title > aComedy.title;
	}
	else if (year != aComedy.year) {
		return year > aComedy.year;
	}

	return false;
}

// override operator <
// sort drama by title, then date
bool Comedy::operator< (const NodeData& rhs) const{
	const Comedy& aComedy = static_cast<const Comedy&>(rhs);
	if (title != aComedy.title){
		return title < aComedy.title;
	}
	else if (year != aComedy.year) {
		return year < aComedy.year;
	}

	return false;
}
