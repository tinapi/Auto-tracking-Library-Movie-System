////////////////////////////////  movie.cpp  /////////////////////////////////
#include "movie.h"

//--------------------------  constructor  -----------------------------------
// set default quantity of movie
Movie::Movie(){
	director = "";
	year = -1;
	title = "";
	instock = DEFAULT_QUANTITY;
	media = "DVD";
}

//------------------------  copy constructor  --------------------------------
Movie::Movie(const Movie& rhs){
	director = rhs.director;
	year = rhs.year;
	title = rhs.title;
	instock = rhs.instock;
}

ostream& Movie::print(ostream & output) const {
	output.setf(ios::left, ios::adjustfield);

	output << setw(QUANTIRY_OUTPUT_WIDTH) << instock;
	output << setw(QUANTIRY_OUTPUT_WIDTH) << DEFAULT_QUANTITY - instock;
	output << setw(TITLE_OUTPUT_WIDTH) << title.substr(0, TITLE_OUTPUT_MAX_LENGTH);
	output << setw(DIRECTOR_OUTPUT_WIDTH) << director.substr(0, DIRECTOR_OUTPUT_MAX_LENGTH);
	output << setw(YEAR_OUTPUT_WIDTH) << year;
	output << endl;

	return output;
}

//------------------------  set data  --------------------------------
bool Movie::setData(ifstream & infile) {

   infile.get();     // get (and ignore) blank before director
   getline(infile, director, ',');     // input director
   
   infile.get();                       // get (and ignore) blank before title
   getline(infile, title, ',');        // input title
   
   infile.get();                       // get (and ignore) blank before actor
   infile >> year;            // input month and year

   return true;
}

// return name of director
string Movie::getDirector() const{
	return director;
}

// return media of movie
string Movie::getMedia() const {
	return media;
}

// return title of movie
string Movie::getTitle() const{
	return title;
}

// return year of movie
int Movie::getYear() const{
	return year;
}

// return quantity of movie
int Movie::getQuantity() const{
	return instock;
}


// set director first and last name
void Movie::setDirector(string director){
	this->director = director;
}

// set title of movie
void Movie::setTitle(string movieTitle){
	title = movieTitle;
}

// set year of movie
void Movie::setYear(int movieYear){
	year = movieYear;
}

// set quantity of movie
void Movie::setQuantity(int movieQuantity) {
	instock = movieQuantity;
}

// increase quantity by 1
bool Movie::increment() {
	if (instock < 10) {
		instock++;
		return true;
	}
	return false;
}

// decrease quantity by 1
bool Movie::decrement() {
	if (instock > 0) {
		instock--;
		return true;
	}
	return false;
}
