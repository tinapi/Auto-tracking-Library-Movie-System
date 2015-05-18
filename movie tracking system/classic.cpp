///////////////////////////////  classic.cpp  ////////////////////////////////
#include "classic.h"

//--------------------------  constructor  -----------------------------------
// constructor calls the base class movie constructor
Classic::Classic() : Movie() {
	actorFirst = "";
	actorLast = "";
	month = -1;
}

//------------------------  copy constructor  --------------------------------
Classic::Classic(const Classic& rhs) : Movie(rhs) {
	actorFirst = rhs.actorFirst;
	actorLast = rhs.actorLast;
	month = rhs.month;
}

//-----------------------------  create()  -----------------------------------
NodeData* Classic::create() const {
	return new Classic();
}

ostream& Classic::print(ostream & output) const {
	output.setf(ios::left, ios::adjustfield);

	output << setw(QUANTIRY_OUTPUT_WIDTH) << instock;
	output << setw(QUANTIRY_OUTPUT_WIDTH) << DEFAULT_QUANTITY - instock;
	output << setw(TITLE_OUTPUT_WIDTH) << title.substr(0, TITLE_OUTPUT_MAX_LENGTH);
	output << setw(DIRECTOR_OUTPUT_WIDTH) << director.substr(0, DIRECTOR_OUTPUT_MAX_LENGTH);
	output << setw(YEAR_OUTPUT_WIDTH) << year;
	output << setw(MONTH_OUTPUT_WIDTH) << month;
	output << actorFirst << " " << actorLast;
	output << endl;

	return output; 
}

bool Classic::setData(ifstream & infile) {
	infile.get();     // get (and ignore) blank before director
    getline(infile, director, ',');     // input director
   
    infile.get();                       // get (and ignore) blank before title
    getline(infile, title, ',');        // input title
   
    infile.get();			// get (and ignore) blank before actor
	infile >> actorFirst>> actorLast;
    infile >> month >> year;            // input month and year

   return true;
}

bool Classic::setSorting(ifstream & infile) {
	infile.get();
	infile >> month >> year >> actorFirst >> actorLast;
	return true;
}

// return month of movie
int Classic::getMonth() const{
	return month;
}

// return first name of actor
string Classic::getActFirst() const{
	return actorFirst;
}

// return last name of actor
string Classic::getActLast() const{
	return actorLast;
}

// set month of movie
void Classic::setMonth(int movieMonth){
	month = movieMonth;
}

// set actor of movie
void Classic::setActor(string firstName, string lastName) {
	actorFirst = firstName;
	actorLast = lastName;
}

// override opeartor ==
// sort classic movie by date, then famous actor
bool Classic::operator== (const NodeData& rhs) const {
	// casting a nodedata renference to a classic reference
	const Classic& aClassic = static_cast<const Classic&>(rhs);
	return getYear() == aClassic.getYear() && 
		getMonth() == aClassic.getMonth() && 
		getActFirst() == aClassic.getActFirst() && 
		getActLast() == aClassic.getActLast();
}

// override operator !=
bool Classic::operator!= (const NodeData& rhs) const {
	return !(*this == rhs);
}

// override operator >
bool Classic::operator> (const NodeData& rhs) const {
	// casting a nodedata renference to a classic reference
	const Classic& aClassic = static_cast<const Classic&>(rhs);

	if (year != aClassic.year) { 
		return year > aClassic.year; 
	} 
	else if (month != aClassic.month) { 
		return month > aClassic.month; 
	} 
	else if (actorLast != aClassic.actorLast) {
		return actorLast > aClassic.actorLast;
	}
	else if (actorFirst != aClassic.actorFirst) {
		return actorFirst > aClassic.actorFirst;
	}

	return false;
}

// override operator <
bool Classic::operator< (const NodeData& crhs) const {
	// casting a nodedata renference to a classic reference
	const Classic& aClassic = static_cast<const Classic&>(crhs);

	if (year != aClassic.year) {
		return year < aClassic.year;
	}
	else if (month != aClassic.month) {
		return month < aClassic.month;
	}
	else if (actorLast != aClassic.actorLast) {
		return actorLast < aClassic.actorLast;
	}
	else if (actorFirst != aClassic.actorFirst) {
		return actorFirst < aClassic.actorFirst;
	}

	return false;
}
